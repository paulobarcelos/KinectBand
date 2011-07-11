/*
 *  KinectBass.h
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/10/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#ifndef _KINECT_BASS
#define _KINECT_BASS

#define BASS_MIDI_CHANNEL 2
#define BASS_MAX_HAND_DIST 1400.f

#include "KinectMusician.h"

////////////////////////////////////////////////////////////
// CLASS DEFINITION ----------------------------------------
////////////////////////////////////////////////////////////
class KinectBass : public KinectMusician{
	
public:

	void	update(ofxTrackedUser* user);	
	float	distance;
	float	output;
	
	ofVec3f left, right;
	
};
#endif