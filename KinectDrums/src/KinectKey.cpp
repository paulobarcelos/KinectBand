/*
 *  KinectKey.cpp
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/11/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#include "KinectKey.h"

///////////////////////////////////////////////////////////////////////////////////
// update -------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void KinectKey::update(ofxTrackedUser* user){	
	KinectMusician::update(user);
	
	if(isTracked){
		ofxLimb& leftUpperArm = user->left_upper_arm;
		ofxLimb& leftLowerArm = user->left_lower_arm;
		
		XnPoint3D& leftShoulder = leftUpperArm.position[0];
		XnPoint3D& leftHand = leftLowerArm.position[1];
		
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &leftShoulder, &leftShoulder);
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &leftHand, &leftHand);
		
		if(memberExists(leftShoulder) && memberExists(leftHand)){	
			ofVec3f lHand = ofVec3f(leftHand.X, leftHand.Y, leftHand.Z);
			ofVec3f lShoulder = ofVec3f(leftShoulder.X, leftShoulder.Y, leftShoulder.Z);
			
			float diff = lShoulder.y - lHand.y;			
			leftDiff = leftDiff * 0.5f + diff * 0.5f;
			
			if (leftDiff < 350.f) {
				if(!leftInside){
					leftInside = true;
					ofxOscMessage msg;
					msg.setAddress("/osc/midi/out/noteOn");
					msg.addIntArg(KEY_MIDI_CHANNEL); // channel
					msg.addIntArg(1); // index
					msg.addIntArg(1); // velocity
					osc.sendMessage(msg);
				
					cout << "linside" << endl;
				}
			}
			else {
				leftInside = false;
				ofxOscMessage msg;				
				msg.setAddress("/osc/midi/out/noteOff");
				msg.addIntArg(KEY_MIDI_CHANNEL); // channel
				msg.addIntArg(1); // index
				msg.addIntArg(1); // velocity
				osc.sendMessage(msg);
			}
			
		}
		
		ofxLimb& rightUpperArm = user->right_upper_arm;
		ofxLimb& rightLowerArm = user->right_lower_arm;
		
		XnPoint3D& rightShoulder = rightUpperArm.position[0];
		XnPoint3D& rightHand = rightLowerArm.position[1];
		
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &rightShoulder, &rightShoulder);
		depthGenerator->getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &rightHand, &rightHand);
		
		if(memberExists(rightShoulder) && memberExists(rightHand)){	
			ofVec3f rHand = ofVec3f(rightHand.X, rightHand.Y, rightHand.Z);
			ofVec3f rShoulder = ofVec3f(rightShoulder.X, rightShoulder.Y, rightShoulder.Z);
			
			float diff = rShoulder.y - rHand.y;			
			rightDiff = rightDiff * 0.5f + diff * 0.5f;
			
			if (rightDiff < -350.f) {
				if(!rightInside){
					rightInside = true;
					ofxOscMessage msg;
					msg.setAddress("/osc/midi/out/noteOn");
					msg.addIntArg(KEY_MIDI_CHANNEL); // channel
					msg.addIntArg(2); // index
					msg.addIntArg(1); // velocity
					osc.sendMessage(msg);
					
					cout << "linside" << endl;
				}
			}
			else {
				rightInside = false;
				ofxOscMessage msg;				
				msg.setAddress("/osc/midi/out/noteOff");
				msg.addIntArg(KEY_MIDI_CHANNEL); // channel
				msg.addIntArg(2); // index
				msg.addIntArg(1); // velocity
				osc.sendMessage(msg);
			}
			
		}
	}	
}