/*
 *  KinectDrums.h
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/10/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#ifndef _KINECT_DRUMS
#define _KINECT_DRUMS

#define DRUMS_MIDI_CHANNEL 1

#include "KinectMusician.h"

////////////////////////////////////////////////////////////
// CLASS DEFINITION ----------------------------------------
////////////////////////////////////////////////////////////
class KinectDrums : public KinectMusician{
	
public:
	
	void	update(ofxTrackedUser* user);	
	//float	distance;
	float	activity;
	float	tempo;
	
	ofVec3f right;
	ofVec3f smoothRight, lastSmoothRight;
	float	diff, smoothDiff;
	
	float smoothLDiff, height;
	
};
#endif