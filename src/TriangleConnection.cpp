//
//  TriangleConnection.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#include "TriangleConnection.h"

void TriangleConnection::set_3_pos(ofVec2f* pos1, ofVec2f* pos2,ofVec2f* pos3){
    this->pos1 = pos1;
    this->pos2 = pos2;
    this->pos3 = pos3;
}

void TriangleConnection::set_color(ofColor arg_color){
    color = arg_color;
}


void TriangleConnection::init(){
    
}
void TriangleConnection::draw(){
    ofFill();
    ofSetColor(color,ofRandom(3,8));
    ofTriangle(*pos1, *pos2, *pos3);
}
