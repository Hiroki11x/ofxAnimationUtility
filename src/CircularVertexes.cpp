//
//  CircularVertexes.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/27.
//
//

#include "CircularVertexes.h"

void CircularVertexes::set_radius(float radius){
    this->radius = radius;
}


void CircularVertexes::set_vertex_num(int num){
    this->vertex_num = num;
}

void CircularVertexes::set_circular_mode(bool circular_mode){
    this->circular_mode = circular_mode;
}

void CircularVertexes::set_angle_mode(bool angle_mode){
    this->angle_mode = angle_mode;
}

float CircularVertexes::update_angle(bool angle_mode, int i, int vertex_size){
    float angle;
    if(angle_mode){
        angle = ofMap(i, 0, vertex_size, 0, 2*PI) * ofGetElapsedTimef();//ランダムな感じ
    }else{
        angle = PI/6.0f *i *ofGetElapsedTimef();//収束していく感じでなる
    }
    return angle;
}

void CircularVertexes::add_center_position(float x, float y){
    position.push_back(ofVec2f(x, y));
}

void CircularVertexes::setup(){
    set_circular_mode(true);
    set_vertex_num(10);
    set_radius(100);
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
    float angle;
    float temp_radius = radius;
    int vertex_size;
    for(int i=0;i<position.size();i++){
        center_vec_x = position.at(i).x;
        center_vec_y = position.at(i).y;
        vertex_size = 100*sin(ofRandom(0,PI));
        if(!circular_mode)temp_radius *= sin(ofRandom(0,PI));//円自体の大きさを変化させる
        ofBeginShape();
        for(int i=0;i<vertex_size;i++){
            angle = update_angle(angle_mode, i, vertex_size);
            ofVertex(center_vec_x+temp_radius*cos(angle),center_vec_y+temp_radius*sin(angle));
        }
        ofEndShape();
    }
}