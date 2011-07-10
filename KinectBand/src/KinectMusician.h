/*
 *  KinectMusician.h
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/10/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#ifndef _KINECT_MUSICIAN
#define _KINECT_MUSICIAN

#include "ofMain.h"
#include "ofxOpenNI.h"

////////////////////////////////////////////////////////////
// CLASS DEFINITION ----------------------------------------
////////////////////////////////////////////////////////////
class KinectMusician {
	
public:
	
	KinectMusician();
	~KinectMusician();
	
	void				setup(ofxDepthGenerator* depthGenerator);
	void				update(ofxTrackedUser* user);
	void				start(ofxTrackedUser* user);
	void				stop();
	
	ofxTrackedUser*		user;
	ofxDepthGenerator*	depthGenerator;
	
	bool				isTracked;
	
	
};
#endif