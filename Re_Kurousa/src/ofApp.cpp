#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofToggleFullscreen();
    sound.load("hibikase.mp3");
    sound.play();

    r = 15;
    for (int i=0; i<NUM; i++){
        msy[i].setPosition(ofRandom(-500,500),ofRandom(-500,500),ofRandom(-500,500));
        msp[i].setPosition(ofRandom(-500,500),ofRandom(-500,500),ofRandom(-500,500));
        msg[i].setPosition(ofRandom(-500,500),ofRandom(-500,500),ofRandom(-500,500));
        msy[i].set(r, 50);
        msp[i].set(r, 50);
        msg[i].set(r, 50);
    }
    
    light.enable();
    light.setPosition(-100, 0, 100);
    light.setPosition(-100, 0, 100);
    ofSetFrameRate(30);  //フレームレートは60fps
    ofBackground(0);  //背景は黒
    ofEnableDepthTest();  //深度テストを有効に
    cam.setDistance(120);  //カメラの位置と注目点の距離を120に設定
    this->circle.set(50,50);  //立方体の大きさ(100,100,100)
    this->circle.setResolution(10);  //数値が大きいほど立方体を構成するメッシュの量が増える
    mesh = this->circle.getMesh();  //boxの頂点情報群を取得しmeshに格納
    ofSetLineWidth(20);
    
    glPointSize(3);
    wave = ofSpherePrimitive(10,10).getMesh();
    wave2 = ofSpherePrimitive(60,60).getMesh();
    
    for(int i = 0; i < mesh.getVertices().size(); i++){  //各々の頂点に対して
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));  //色情報初期化
        ofVec3f loc = mesh.getVertices()[i] * ofRandom(0.5,1.0);  //位置情報を0.5~1.0で掛ける
        mesh.setVertex(i, loc);  //新しい位置情報としてセット
        ofColor c;
        c.setHsb(ofRandom(255),255,255);  //HSBで色定義
        mesh.setColor(i,c);  //新しい色情報としてセット
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    volume = ofSoundGetSpectrum(1);
    wave2 = ofSpherePrimitive(volume[0]*200,60).getMesh();
    for (int i=0; i<wave.getVertices().size(); i++){
        ofVec3f point = wave.getVertices()[i] / 400.0;
        float z = ofNoise(point.x,point.y,ofGetElapsedTimef() * 200,0);
        float z2 = ofNoise(point.x,point.y,ofGetElapsedTimef() * 20,0);
        wave.setVertex(i, ofVec3f(wave.getVertices()[i].x, wave.getVertices()[i].y, z*10));
        //wave2.setVertex(i, ofVec3f(wave.getVertices()[i].x, wave.getVertices()[i].y, z*10));
        }
    //wave2.getVertices()[i].x, wave2.getVertices()[i].y, z2*1000
}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();  //カメラ起動
    //wave.setMode(OF_PRIMITIVE_POINTS);
    //wave.drawWireframe();
    //wave.draw();
    ofRotateY(ofGetElapsedTimef()*10);
    ofRotateZ(ofGetElapsedTimef()*10);
    for (int i=0; i<NUM;i++){
        //ofSetColor(249, 209,216); pink
        ofSetColor(255, 255, 255);
        msp[i].draw();
        ofSetColor(51,255,204);
        msg[i].draw();
        ofSetColor(255, 241,0);
        msy[i].draw();
    }
    
    
    ofSetColor(0, 250, 250);
    wave2.setMode(OF_PRIMITIVE_POINTS);
    wave2.draw();
    mesh.drawWireframe();
    //メッシュのフレームを描画
    this->cam.end();
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
