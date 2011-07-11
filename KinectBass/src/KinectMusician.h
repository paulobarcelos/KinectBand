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

#define OSC_HOST "localhost"
#define OSC_PORT 57117

#include "ofMain.h"
#include "ofxOpenNI.h"
#include "ofxOsc.h"

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
	bool				memberExists(XnPoint3D& memberPoint);
	
	ofxTrackedUser*		user;
	ofxDepthGenerator*	depthGenerator;
	
	bool				isTracked;
	
	ofxOscSender		osc;
	
};
#endif