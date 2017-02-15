//
//  TimedSound.cpp
//  cim594_18_audioout
//
//  Created by Clay Ewing on 2/8/17.
//
//


#include "TimedSound.hpp"


TimedSound::TimedSound(int Row){
	row = Row;
	yPos = 0;
	played = false;
}

void TimedSound::draw() {
    ofDrawCircle(row*200 + 200, yPos, 20);
}

void TimedSound::update() {
	switch (row)
	{
	case 0:
		ofSetColor(ofColor::red);
		break;
	case 1:
		ofSetColor(ofColor::green);
		break;
	case 2:
		ofSetColor(ofColor::yellow);
		break;
	case 3:
		ofSetColor(ofColor::blue);
		break;
	default:
		break;
	}
	yPos += 0.5;
}
