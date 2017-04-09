#include "ofApp.h"
#include "ofMain.h"
#include "cv.h"

using namespace cv;


//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);
	camWidth = 320;
	camHeight = 240;

	cam.setup(camWidth, camHeight);
	colorImg.allocate(320, 240);
	grayImage.allocate(320, 240);
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);

	bLearnBakground = true;
	threshold = 80;
	ofEnableAlphaBlending();

	Particle p;
	//p.setInitialCondition(x, y, 0, 0);
	p.radius = 2;
	//p.a = cur.getBrightness();
	particles.push_back(p);
}

//--------------------------------------------------------------
void ofApp::update() {
	bool bNewFrame = false;

	cam.update();
	bNewFrame = cam.isFrameNew();
	
	if (bNewFrame) {

		GoodFeaturesToTrackDetector detector;
		vector<KeyPoint> keyPoints;
		//detectorC.detect(m, keyPoints);
		cv::Mat image(h, w, CV_8UC3, (void *)cam.);
		

		grayImage = colorImg;
		if (bLearnBakground == true) {
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
	}


	for (int i = 0; i < particles.size(); i++) {
		particles[i].resetForce();
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();

	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.draw(0, 0);


	/*
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
	*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].vel.set(ofRandom(-2, 2), ofRandom(1, 5));
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
