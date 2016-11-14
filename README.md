[![GitHub license](https://img.shields.io/badge/content-Gui%2Fcore-yellow.svg)](https://raw.githubusercontent.com/Facetracker-project/facetracker-core/master/COPYING)
[![GitHub license](https://img.shields.io/badge/codename-TheMachine-red.svg)](https://raw.githubusercontent.com/Facetracker-project/facetracker-core/master/COPYING)
[![GitHub license](https://img.shields.io/badge/license-GPLv3-blue.svg)](https://raw.githubusercontent.com/Facetracker-project/facetracker-core/master/COPYING) [![Code Climate](https://codeclimate.com/repos/56363a6b6956801daf00c1ec/badges/31b2ffeeb02d53158157/gpa.svg)](https://codeclimate.com/repos/56363a6b6956801daf00c1ec/feed) [![Test Coverage](https://codeclimate.com/repos/56363a6b6956801daf00c1ec/badges/31b2ffeeb02d53158157/coverage.svg)](https://codeclimate.com/repos/56363a6b6956801daf00c1ec/coverage) [![GitHub version](https://badge.fury.io/gh/invicnaper%2FMWF.svg)](http://badge.fury.io/gh/invicnaper%2FMWF)
# README #

This README would normally document whatever steps are necessary to get facetracker up and running.

![alt text](https://cdn1.iconfinder.com/data/icons/skype-icons/128/skype_camera.png "FT logo")

### What is this repository for? ###

* Share facetracker code 
* Facetracker is insipred from the American Tv show "Person Of Interest"
* Version 1.2
* This repo contains facetracker-core and facetracker-gui . You can check out facetracker-core via this link . https://github.com/Facetracker-project/facetracker-core

### Screen ###

![alt text](http://nsa37.casimages.com/img/2015/10/31/151031053712540888.png "FT screen")

![alt text](http://naper.eu/me/images/facetracker.jpg "FT screen")


### How do I get set up? ###

build facetracker using source code

#Linux (Facetracker core)

	$ git clone https://github.com/Facetracker-project/facetracker-gui.git
	$ cd facetracker-gui/
	
installing dependecies(Debian - ubuntu) : 

	$ sudo apt-get install libopencv-dev
	
making the project : 

	$ make
	**************************************
	*  Facetracker Building    *
	**************************************
	make ftall		: Build facetracker
	make memleaks		: Check memory leaks

to compile all facetracker modules : 

	$ make ftall
	
then execute it using

	$ ./facetracker
	
#Linux (facetracker gui)

Open the <b>.pro</b> file using QT creator .

#Windows (facetracker core)

Open the <b>.sln</b> file using Visual Studio

#Windows (facetracker gui)

Open the <b>.pro</b> file using QT creator .

#Available Arguments
-o : allows you to open a media source (camera , picture , video, rtsp link..)

	$ ./facetracker -o CAM0 (open camera id=0)
	$ ./facetracker -o video.avi (open the file video.avi)

### Contributors ###

* Hamza Bourrahim
* Godeleine Champenois
* Quentin Jeannaud

