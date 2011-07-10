/*
 *  KinectBass.cpp
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/10/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#include "KinectBass.h"

///////////////////////////////////////////////////////////////////////////////////
// update -------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void KinectBass::update(ofxTrackedUser* user){	
	KinectMusician::update(user);

	if(isTracked){
		ofxLimb& leftArm = user->left_lower_arm;
		ofxLimb& rightArm = user->right_lower_arm;		
		
		XnPoint3D& leftHand = leftArm.position[1];
		XnPoint3D& rightHand = rightArm.position[1];		
		
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &leftHand, &leftHand);
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &rightHand, &rightHand);	
		
		if(memberExists(leftHand) && memberExists(rightHand)){
		
		
			left = ofVec3f(leftHand.X, leftHand.Y, leftHand.Z);
			right = ofVec3f(rightHand.X, rightHand.Y, rightHand.Z);
	
			distance = (left - right).length();
			
			float norm = ofClamp(distance/BASS_MAX_HAND_DIST, 0, 1);
			
			output = output*.9f + norm*0.1f;
			
			ofxOscMessage msg;
			msg.setAddress("/osc/midi/out/control");
			msg.addIntArg(1); // channel
			msg.addIntArg(1); // index
			msg.addIntArg(int(output*128)); // value
			osc.sendMessage(msg);
		}			
	}	
}