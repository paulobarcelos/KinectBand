/*
 *  KinectDrums.cpp
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/10/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#include "KinectDrums.h"

///////////////////////////////////////////////////////////////////////////////////
// update -------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void KinectDrums::update(ofxTrackedUser* user){	
	KinectMusician::update(user);
	
	if(isTracked){
		ofxLimb& leftShoulder = user->left_upper_arm;
		ofxLimb& leftArm = user->left_lower_arm;
		
		ofxLimb& rightArm = user->right_lower_arm;		
		
		XnPoint3D& leftShoulderStart = leftShoulder.position[0];
		XnPoint3D& leftHand = leftArm.position[1];
		XnPoint3D& rightHand = rightArm.position[1];		
		
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &leftShoulderStart, &leftShoulderStart);
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &leftHand, &leftHand);
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &rightHand, &rightHand);	
		
		if(memberExists(leftHand) && memberExists(leftHand)){	
			ofVec3f lHand = ofVec3f(leftHand.X, leftHand.Y, leftHand.Z);
			ofVec3f lShoulder = ofVec3f(leftShoulderStart.X, leftShoulderStart.Y, leftShoulderStart.Z);

			float lDiff = lShoulder.y - lHand.y;
			
			lDiff = lDiff + 500.f; // range 0 (top) - 1000 (bottom)
			lDiff = 1000.f - lDiff; // range 1000 - 0;
			lDiff = lDiff / 1000.f; 
			lDiff = ofClamp(lDiff, 0, 1);
			
			smoothLDiff = smoothLDiff * 0.8f + lDiff * 0.2f;
			
			ofxOscMessage msg;
			msg.setAddress("/osc/midi/out/control");
			msg.addIntArg(DRUMS_MIDI_CHANNEL); // channel
			msg.addIntArg(2); // index
			msg.addIntArg(int(smoothLDiff*128)); // value
			osc.sendMessage(msg);
		}
		
		if(memberExists(rightHand)){			
			right = ofVec3f(rightHand.X, rightHand.Y, rightHand.Z);
			smoothRight = smoothRight * 0.7f + right * 0.3f;
			
			ofVec2f smoothRight2D = smoothRight;
			ofVec2f lastSmoothRight2D = lastSmoothRight;
			
			diff = (smoothRight2D - lastSmoothRight2D).length();			
			smoothDiff = smoothDiff*0.965f + diff*0.035f;
			
			activity = (smoothDiff - 2) / 55.f;
			activity = ofClamp(activity, 0, 1);
			
			lastSmoothRight = smoothRight;
			
			ofxOscMessage msg;
			msg.setAddress("/osc/midi/out/control");
			msg.addIntArg(DRUMS_MIDI_CHANNEL); // channel
			msg.addIntArg(1); // index
			msg.addIntArg(int(activity*128)); // value
			osc.sendMessage(msg);
		}			
	}	
}