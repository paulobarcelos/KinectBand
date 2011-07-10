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
		
		ofVec3f leftVec(leftHand.X, leftHand.Y, leftHand.Z);
		ofVec3f rightVec(rightHand.X, rightHand.Y, rightHand.Z);
		
		distance = (leftVec - rightVec).length();
		
		cout << distance << endl;
		
	}	
}