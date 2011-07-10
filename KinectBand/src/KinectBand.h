/*
 *  KinectBand.h
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/10/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#ifndef _KINECT_BAND
#define _KINECT_BAND

#include "ofMain.h"
#include "ofxOpenNI.h"
#include "KinectBass.h"
#include "KinectDrums.h"
#include "KinectKey.h"

////////////////////////////////////////////////////////////
// CLASS DEFINITION ----------------------------------------
////////////////////////////////////////////////////////////
class KinectBand {
	
public:
	
	KinectBand();
	~KinectBand();
	
	void				setup(ofxDepthGenerator* depthGenerator, ofxUserGenerator* userGenerator);
	void				update();
	
	ofxUserGenerator*	userGenerator;
	ofxDepthGenerator*	depthGenerator;
	
	KinectBass			bass;
	KinectDrums			drums;
	KinectKey			key;

	
private:
	
	
};
#endif