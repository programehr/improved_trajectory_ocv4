#I coudln't build the code with the original make file (by Wang et al.), and had to modify it.
#However, I have kept the original lines as comments so you can restore them.

# set the binaries that have to be built
TARGETS := DenseTrackStab Video

# set the build configuration set 
BUILD := release
#BUILD := debug

# set bin and build dirs
BUILDDIR := .build_$(BUILD)
BINDIR := $(BUILD)

# libraries 
LDLIBS = $(addprefix -l, $(LIBS) $(LIBS_$(notdir $*)))
#LIBS := \
#	opencv_core opencv_highgui opencv_video opencv_imgproc opencv_calib3d opencv_features2d opencv_nonfree \
#	avformat avdevice avutil avcodec swscale
	
LIBS := \
	opencv_core opencv_highgui opencv_video opencv_imgproc opencv_calib3d opencv_features2d \
	avformat avutil avcodec swscale opencv_videoio opencv_xfeatures2d

# set some flags and compiler/linker specific commands
CXXFLAGS = -pipe -D __STDC_CONSTANT_MACROS -D STD=std -Wall $(CXXFLAGS_$(BUILD)) -I. -I/opt/include -I/usr/local/include/opencv4
CXXFLAGS_debug := -ggdb
CXXFLAGS_release := -O3 -DNDEBUG -ggdb
LDFLAGS = -L/opt/lib -pipe -Wall $(LDFLAGS_$(BUILD))
LDFLAGS_debug := -ggdb
LDFLAGS_release := -O3 -ggdb

include make/generic.mk
