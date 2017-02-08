#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    soundStream.printDeviceList();
    
    //if you want to set a different device id
    soundStream.setDeviceID(1); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
	switchColor = 0;
	switchForward = true;
	ball.radius = 10;
	ball.color = ofColor(0, 0, 255);
	ball.pos.x = ofGetWidth() / 2.0f;
	ball.pos.y = ofGetHeight() / 2.0f;
	ball.vel.x = 0;
	ball.vel.y = 0;
}


//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    //RMS Algorithm. Get loudness of input.
	if (ofGetElapsedTimeMillis() < 2000)
		return;
	switchColor = (ofGetElapsedTimeMillis() - 2000)*0.0001;
	if (switchColor > 1)
	{
		switchColor = 0;
		switchForward = !switchForward;
	}
	if (!switchForward)
		switchColor = 1 - switchColor;
    float rms = 0.0;
    int numCounted = 0;
	int switchAmount;
    for (int i = 0; i < bufferSize; i++) {
        float leftSample = input[i * 2] * .5;
        float rightSample = input[i * 2 + 1] * .5;
        rms += leftSample * leftSample;
        rms += rightSample * rightSample;
        numCounted += 2;
    }
    
    rms /= (float)numCounted;
    rms = sqrt(rms);
    loudness_history.push_back(rms);
	Particle newParticle;
	newParticle.setInitialCondition(ofGetWidth(), ofGetHeight(),-0.2, -rms*30);
	int redColor = rms * 40000;
	int greenColor = 0;
	int blueColor = 0;
	if (redColor > 255)
	{
		greenColor = redColor - 255;
		redColor = 255;
	}
	if (greenColor > 255)
	{
		greenColor = 255;
	}
	if (blueColor > 255)
		blueColor = 255;
	//switchAmount = redColor * switchColor;
	//blueColor = redColor * (1 - switchColor);
	newParticle.changeColor(ofColor(redColor, greenColor, blueColor));
	particles.push_back(newParticle);
	ball.vel.y += rms/50.0;
	if(ball.vel.y > 0.01)
		ball.frc.y += -0.00001;
	if (ball.pos.y < ofGetWidth() / 2.0f)
		ball.pos.y = ofGetWidth() / 2.0f;
}

//--------------------------------------------------------------
void ofApp::update(){
    while(loudness_history.size() > ofGetWidth()) {
        loudness_history.erase(loudness_history.begin());
    }
	//if (particles.size() > 10000)
	//	particles.pop_front();
	for (int i = 0; i < particles.size(); i++) {
		particles[i].resetForce();
		//particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}

	for (int i = 0; i < particles.size(); i++)
	{
		polyLine.addVertex(particles[i].pos.x, particles[i].pos.y);
	}
	ball.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//The loudness is a very small number, to see it, we're going to map it with a much larger number of the screen width
	//polyLine.draw();
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].draw();
	}
	//ball.drawCircle();
	
/*ofSetColor(0, 0, 0);
    if(loudness_history.size() > 2) {
        for(int i = 0; i < loudness_history.size() - 1; i++) {
            float y1 = ofMap(loudness_history[i], 0, 1, ofGetHeight(), 0);
            float y2 = ofMap(loudness_history[i + 1], 0, 1, ofGetHeight(), 0);

            ofDrawLine(i, y1, i, y2);
        }
    }*/
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
