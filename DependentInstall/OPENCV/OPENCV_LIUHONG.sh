#!/bin/bash

# install gcc compiler
sudo apt install -y g++
# install cmake build comfiguration tool
sudo apt install -y cmake
# install make
sudo apt install -y make
# Install tool for getting and unpacking sources
sudo apt install -y wget unzip

# download source
wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/master.zip
unzip opencv.zip
unzip opencv_contrib.zip
rm opencv_contrib.zip
rm opencv.zip
# Create build directory and switch into it
mkdir -p build && cd build
# Configure
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-master/modules ../opencv-master
# Build
cmake --build .
# install into system 
sudo make install
