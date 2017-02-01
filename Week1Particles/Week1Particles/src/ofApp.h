#pragma once

#include "ofMain.h"
#include "Particle.hpp"

// Example from Zach Lieberman, http://github.com/ofZach/algo2012
// https://github.com/ofZach/algo2012/tree/master/week4/drawingWithParticles

const int windowWidth = 1000;
const int windowHeight = 800;


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
		void addWaterParticles();
		void addFireParticles();
		void addPurpleParticles();
		void raisePurple();
    
        // let's make a vector of them
        vector <Particle> fireParticles;
		vector <Particle> waterParticles;
		vector <Particle> purpleParticles;
		int heightOfPurple;
};
