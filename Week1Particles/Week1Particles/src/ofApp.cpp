
// Example from Zach Lieberman, http://github.com/ofZach/algo2012
// https://github.com/ofZach/algo2012/tree/master/week4/multiParticles


#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
	heightOfPurple = windowHeight;
    /*
	
    for (int i = 0; i < 1000; i++){
        Particle waterParticle (water);
        float vx = ofRandom(-10,-8);
        float vy = ofRandom(-3,3);
        waterParticle.setInitialCondition(windowWidth/2.0 + 300,windowHeight/2.0,vx, vy);
        waterParticle.damping = ofRandom(0.01, 0.02);
        waterParticles.push_back(waterParticle);
    }

	for (int i = 0; i < 1000; i++) {
		Particle fireParticle (fire);
		float vx = ofRandom(8, 10);
		float vy = ofRandom(-3, 3);
		fireParticle.setInitialCondition(windowWidth / 2.0 - 300, windowHeight / 2.0, vx, vy);
		fireParticle.damping = ofRandom(0.01, 0.02);
		fireParticles.push_back(fireParticle);
	}*/
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perform damping and
    // then update
	Particle waterParticle(water);
	Particle fireParticle(fire);

	addWaterParticles();
	addFireParticles();
	if(ofGetElapsedTimeMillis() > 2500)
		addPurpleParticles();

	
		
    
    for (int i = 0; i < waterParticles.size(); i++){
        waterParticles[i].resetForce();
        //particles[i].addForce(0,0.04);  // gravity
        waterParticles[i].bounceOffWalls();
        waterParticles[i].addDampingForce();
		waterParticles[i].addGravity();
        waterParticles[i].update();
    }
	for (int i = 0; i < fireParticles.size(); i++) {
		fireParticles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		fireParticles[i].bounceOffWalls();
		fireParticles[i].addDampingForce();
		fireParticles[i].addGravity();
		fireParticles[i].update();
	}
	for (int i = 0; i < purpleParticles.size(); i++) {
		purpleParticles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		purpleParticles[i].bounceOffWalls();
		purpleParticles[i].addDampingForce();
		purpleParticles[i].addGravity();
		purpleParticles[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);

    for (int i = 0; i < waterParticles.size(); i++){
        waterParticles[i].draw();
    }
	for (int i = 0; i < fireParticles.size(); i++) {
		fireParticles[i].draw();
	}
	for (int i = 0; i < purpleParticles.size(); i++) {
		purpleParticles[i].draw();
	}
	if (ofGetElapsedTimeMillis() > 3000)
		raisePurple();
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
    /*for (int i = 0; i < waterParticles.size(); i++){
        float vx = ofRandom(-4,4);
        float vy = ofRandom(-4,4);
        particles[i].setInitialCondition(mouseX,mouseY,vx, vy);
        
    }*/
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

void ofApp::addWaterParticles()
{
	Particle waterParticle(water);
	float vx = ofRandom(5, 8);
	float vy = ofRandom(-8, -10);
	waterParticle.setInitialCondition(windowWidth/2.0 - 350, heightOfPurple, vx, vy);
	waterParticle.damping = ofRandom(0.01, 0.02);
	waterParticles.push_back(waterParticle);
}

void ofApp::addFireParticles()
{
	Particle fireParticle(fire);
	float vx = ofRandom(-5, -8);
	float vy = ofRandom(-8, -10);
	fireParticle.setInitialCondition(windowWidth / 2.0 + 350, heightOfPurple, vx, vy);
	fireParticle.damping = ofRandom(0.01, 0.02);
	fireParticles.push_back(fireParticle);
}

void ofApp::addPurpleParticles()
{
	Particle purpParticle(purple);
	float vx = ofRandom(-5, 5);
	float vy = ofRandom(-2,-3);
	float initWidth = ofRandom(windowWidth / 2.0 - 200, windowWidth / 2.0 + 200);
	purpParticle.setInitialCondition(initWidth, heightOfPurple, vx, vy);
	purpParticle.damping = 0.05;
	purpleParticles.push_back(purpParticle);
}

void ofApp::raisePurple()
{
	heightOfPurple = 800 - ((ofGetElapsedTimeMillis() - 3000) / 100);
	ofDrawRectangle(0, heightOfPurple, windowWidth, windowHeight);
}