# Introduction
I took the ["improved dense trajectories"](https://lear.inrialpes.fr/people/wang/improved_trajectories) code and made small modifications to make it compatible with OpenCV 4.0. To see the readme of the original code, see the `original-README` file.
# Install
The code requires OpenCV (with OpenCV-contrib) and ffmpeg to be installed.
First, install ffmpeg.

To install OpenCV, you could refer to the official website's [instructions](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html), however, the following instructions should work, too:
```sh
apt-get install build-essential
apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```
download OpenCV
download OpenCV-contrib
```sh
cd <path to OpenCV>
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -DOPENCV_EXTRA_MODULES_PATH=<path to OpenCV-contrib>/modules 
-OPENCV_ENABLE_NONFREE .. && make -j4
```
If the above make fails, the following may help:

If the file `/etc/ld.so.conf.d/opencv.conf` and its parent folder don't exist, create them:
```sh
mkdir /etc/ld.so.conf.d
touch /etc/ld.so.conf.d/opencv.conf
```
then:
```sh
echo /usr/local/lib >> /etc/ld.so.conf.d/opencv.conf
make clean && make -j4
```
# License
Improved dense trajectories for OpenCV 4.0, based on the ["improved dense trajectories"](https://lear.inrialpes.fr/people/wang/improved_trajectories) code.
Copyright (C) 2020  Mehrin Saremi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see [https://www.gnu.org/licenses/](https://www.gnu.org/licenses/).


