#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(false);
	ofSetFrameRate(90);
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogVerbose("HELLLOOOO");

	// We need to pass the method we want ofxOpenVR to call when rending the scene
	openVR.setup(std::bind(&ofApp::render, this, std::placeholders::_1));

    cam.setDistance(4);
    cam.setNearClip(0.01);
    cam.setFarClip(1000);
    
    // UI
    ui = new ofxUISuperCanvas("MENU");
    ui->setWidgetFontSize(ofxUIWidgetFontType::OFX_UI_FONT_MEDIUM);
    ui->addSpacer();
    ui->addButton("Set Value", false);
    ui->addButton("Next Target", false);
    ui->setColorBack(ofxUIColor(100, 100, 100, 128));
    ui->autoSizeToFitWidgets();
    ofAddListener(ui->newGUIEvent, this, &ofApp::guiEvent);
}

//--------------------------------------------------------------
void ofApp::exit() {
	openVR.exit();
}

//--------------------------------------------------------------
void ofApp::update(){
	openVR.update();
    calibpoints.update();

	trackerPose = openVR.getLastGenericTrackerPose();
	ofVec3f rotvec;
	float angle;
	trackerPose.getRotate().getRotate(angle, rotvec.x, rotvec.y, rotvec.z);
	pos = trackerPose.getTranslation();
	ori_y = ofVec3f(0, 1, 0).getRotated(angle, rotvec);
	ori_z = ofVec3f(0, 0, 1).getRotated(angle, rotvec);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    cam.begin();
	{
		// scene
		ofPushMatrix();
		if(!calibpoints.isCalibrated) ofScale(-1, 1, -1);
		staticCgSceneAttr.draw();
		staticCgSceneAttr.drawBlackWireFrame();
		// points
		calibpoints.draw();
		ofPopMatrix();

		// tracker
		ofPushMatrix();
		// usual
		ofTranslate(calibpoints.calibmat*trackerPose.getTranslation());
		float x, y, z, angle;
		trackerPose.getRotate().getRotate(angle, x, y, z);
		ofRotate(angle, x, y, z);
		ofDrawAxis(0.3);
		ofPopMatrix();
	}
	cam.end();
    ofDisableDepthTest();
    ofDisableAlphaBlending();

	stringstream ss;
	ss << "pos:   " << pos << endl;
	ss << "ori_y: " << ori_y << endl;
	ss << "ori_z: " << ori_z << endl << endl;
	ss << "calibmat: " << endl << calibpoints.calibmat << endl;
	ofDrawBitmapString(ss.str(), 20, 120);

	openVR.drawDebugInfo(10.0f, 500.0f);
}

//--------------------------------------------------------------
void  ofApp::render(vr::Hmd_Eye nEye) {
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e) {
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    
    if (kind == OFX_UI_WIDGET_BUTTON)
    {
        ofxUIButton *button = (ofxUIButton *)e.widget;
        if (name == "Set Value" && button->getValue() == 0) { // button released
			ofVec3f rotvec;
			float angle;
			trackerPose.getRotate().getRotate(angle, rotvec.x, rotvec.y, rotvec.z);
			calibpoints.setValue(pos, rotvec, angle, ori_y, ori_z);
        }
        if (name == "Next Target" && button->getValue() == 0) { // button released
            calibpoints.nextTarget();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
