#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true); ofEnableBlendMode(OF_BLENDMODE_ADD); ofToggleFullscreen(); mySound.loadSound("01 ヒカリへ.mp3");
    mySound.setLoop(true); mySound.play();
    // FFT解析初期化
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    nBandsToGet = 15;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    volume=ofSoundGetSpectrum(nBandsToGet);
    csize=volume[0]*500;
    //FFT解析を行い、音量の平均を出す
    for (int i = 0; i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < volume[i]) fftSmoothed[i] = volume[i];
        avgSound += fftSmoothed[i];
    }
    //volumeに値を丸める avgSound /= nBandsToGet;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //グラフ
    ofBackground(0, 0, 0);
    ofSetColor(100, 100, 100);
    ofRect(0,0,300,300);
    int start_x = 0;
    int base_y = 300;
    ofSetColor(55, 190, 200);
    float width = (float)(200) / nBandsToGet;
    for (int i = 0;i < nBandsToGet; i++){
//        if (fftSmoothed[i] * 300>200)fftSmoothed[i]=0.745;
        ofRect(start_x + i * width, base_y, width, - (fftSmoothed[i] * 300));
      
    }
    //円
//    ofBackground(0, 0, 0);
    ofSetColor(55, 190, 200);
    //                ofRect(0, 0,300,300);
    
    ofCircle(300, 600, csize/4);
    
    //四角
//    ofBackground(0, 0, 0);
//    ofSetColor(100, 100, 100);
//    ofRect(0, 300,300,300);
    ofSetColor(55, 190, 200);
    //                ofRect(0, 0,300,300);
    ofRect(900-csize/2, 500-csize/2,csize, csize);


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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
