#pragma once

#include "ofMain.h"
#include "ofxOpenVR.h"
#include "ofxUI.h"
#include "StaticCGSceneAttr.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void exit();

		void update();
		void draw();

		void render(vr::Hmd_Eye nEye);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxOpenVR openVR;
		ofMatrix4x4 trackerPose;
		ofVec3f pos, ori_y, ori_z;
		
		scgsa::StaticCGSceneAttr staticCgSceneAttr;
		scgsa::CalibPoints calibpoints;
		ofEasyCam cam;

		// UI
		ofxUISuperCanvas *ui;
		void guiEvent(ofxUIEventArgs &e);

};
