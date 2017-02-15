#include "ofApp.h"

const string soundFiles[] = { R"(notes\c.wav)" , R"(notes\d.wav)" , R"(notes\e.wav)" , R"(notes\f.wav)", R"(notes\g.wav)", R"(notes\a.wav)", R"(notes\b.wav)" };

//--------------------------------------------------------------
void ofApp::setup(){

	for (int i = 0; i < 7; i++)
	{
		ofSoundPlayer newSound;
		newSound.load(soundFiles[i]);
		newSound.setMultiPlay(true);
		sounds.push_back(newSound);
	}
	lastPlay = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < size(soundBalls); i++)
	{
		if ((soundBalls[i].yPos > lineHeight - 30) && !soundBalls[i].played)
		{
			soundBalls[i].played = true;
			sounds[song[i]].play();
		}

	}
	if ((int)(ofGetElapsedTimef()*4) != lastPlay)
	{
		int playRand = ofRandom(3);
		if (playRand > 0)
		{
			int newRand = ofRandom(7);
			
			TimedSound newSound(newRand % 4);
			soundBalls.push_back(newSound);
			song.push_back(newRand);
		}
		lastPlay = (int)(ofGetElapsedTimef() * 4);
		updated = true;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::black);
	ofDrawLine(0, lineHeight, ofGetWidth(), lineHeight);
    for(int i = 0; i < soundBalls.size(); i++) {
		soundBalls[i].update();
		soundBalls[i].draw();
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
    //startTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //TimedSound tmpSound;
    //tmpSound.sound = &mySound;
    //tmpSound.setInitialConditions(x,y, ofGetElapsedTimef() - startTime);
    //sounds.push_back(tmpSound);
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
