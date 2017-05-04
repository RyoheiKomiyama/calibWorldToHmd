#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setDistance(4);
    cam.setNearClip(0.01);
    cam.setFarClip(1000);
}

//--------------------------------------------------------------
void ofApp::update(){
    calibpoints.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    cam.begin();
    
    staticCgSceneAttr.draw();
    staticCgSceneAttr.drawBlackWireFrame();
    
    calibpoints.draw();

    cam.end();
    ofDisableDepthTest();
    ofDisableAlphaBlending();
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
