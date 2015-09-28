//
//  CircularVertexes.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/27.
//
//

#include "CircularVertexes.h"

void CircularVertexes::set_vertex_num(int num){
    this->vertex_num = num;
}

void CircularVertexes::set_circular_mode(bool mode){
    this->circular_mode = mode;
}


void CircularVertexes::add_center_position(float x, float y){
    position.push_back(ofVec2f(x, y));
}

void CircularVertexes::setup(){
    set_circular_mode(true);
    set_vertex_num(20);
    float random_x;
    float random_y;
    for(int i=0;i<vertex_num;i++){
        float random_x = ofRandom(ofGetWidth());
        float random_y = ofRandom(ofGetHeight());
        add_center_position(random_x,random_y);
    }
}

void CircularVertexes::draw(){
    ofNoFill();
    float center_vec_x,center_vec_y;
    float angle,radius;
    int vertex_size;
    for(int i=0;i<position.size();i++){
        center_vec_x = position.at(i).x;
        center_vec_y = position.at(i).y;
        vertex_size = 100*sin(ofRandom(0,PI));
        ofBeginShape();
        for(int i=0;i<vertex_size;i++){
            angle = ofMap(i, 0, vertex_size, 0, 2*PI) * ofGetElapsedTimef();
            radius = ofRandom(100);
            ofVertex(center_vec_x+radius*cos(angle),center_vec_y+radius*sin(angle));
        }
        ofEndShape();
    }
}