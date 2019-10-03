#pragma once
#define NUM 25
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"


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

    ofEasyCam cam;  //カメラ
    ofBoxPrimitive box;
    ofSpherePrimitive circle;
    //立方体
    ofMesh mesh;
    ofMesh wave;
    ofMesh wave2;
    ofLight light;
    ofSoundPlayer sound;
    ofImage BackgroundImage;
    ofSpherePrimitive sphere, msp[NUM];
    ofSpherePrimitive spherey, msy[NUM];
    ofSpherePrimitive sphereg, msg[NUM];
    ofBoxPrimitive stars, mbox[NUM];
    int r;
    float *volume;
    float *fftSmooth;
    int nBandsToGet;
		
};
