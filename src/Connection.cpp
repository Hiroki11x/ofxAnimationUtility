//
//  Connection.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#include "Connection.h"

void Connection::set_node(ofVec2f* start, ofVec2f* end){
    start_pos = start;
    end_pos = end;
}


void Connection::init(){
    
}
void Connection::draw(){
//    ofSetColor(255);
    ofLine(*start_pos, *end_pos);
}