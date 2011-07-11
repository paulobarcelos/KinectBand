/*
 *  KinectKey.h
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/11/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#ifndef _KINECT_KEY
#define _KINECT_KEY

#define KEY_MIDI_CHANNEL 3

#include "KinectMusician.h"

////////////////////////////////////////////////////////////
// CLASS DEFINITION ----------------------------------------
////////////////////////////////////////////////////////////
class KinectKey : public KinectMusician{
	
public:
	
	void	update(ofxTrackedUser* user);	
	
	bool	leftInside, rightInside;
	float	leftDiff, rightDiff;
	//float	distance;
	/*float	activity;
	float	tempo;
	
	ofVec3f right;
	ofVec3f smoothRight, lastSmoothRight;
	float	diff, smoothDiff;
	
	float smoothLDiff, height;*/
	
};
#endif