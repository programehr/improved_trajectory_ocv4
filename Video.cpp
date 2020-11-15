//#include <opencv2/cv.h>
#include <opencv2/highgui.hpp>
#include <ctype.h>
#include <unistd.h>

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>

#include <opencv2/core/types_c.h>

using namespace cv;

Mat image; 
Mat prev_image;
VideoCapture capture;

bool has_image = false;

int show = 1; 

int main( int argc, char** argv )
{
	int frameNum = 0;

	char* video = argv[1];
	capture.open(video);

	if( !capture.isOpened() ) { 
		printf( "Could not initialize capturing..\n" );
		return -1;
	}
	
	if( show == 1 )
		namedWindow( "Video", 0 );

	while( true ) {
		Mat frame;
		int i, j, c;

		// get a new frame
		//frame = cvQueryFrame( capture );
		capture.read(frame);
		if( frame.empty() )
			break;

		if( !has_image ) {
			image.create(frame.size(), CV_8UC3);
			has_image = true;
			//image =  cvCreateImage( cvSize(frame->width,frame->height), 8, 3 );
			//image->origin = frame->origin;
		}

		frame.copyTo(image);
		//cvCopy( frame, image, 0 );

		if( show == 1 ) {
			imshow( "Video", image);
			c = waitKey(3);
			if((char)c == 27) break;
		}
		
		std::cerr << "The " << frameNum << "-th frame" << std::endl;
		frameNum++;
	}

	if( show == 1 )
		destroyWindow("Video");

	return 0;
}
