//
//  ExplodeAnimation.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#include "ExplodeAnimation.h"


void ExplodeAnimation::set_color(ofColor color){
    this->color = color;
}

void ExplodeAnimation::set_speed_range(float range){
    speed_range = range;
}

void ExplodeAnimation::set_position(ofVec2f pos){
    position = pos;
    for(int i =0;i<triangles.size();i++){
        triangles.at(i).set_position(pos);
    }
}

void ExplodeAnimation::init(){
    triangles.clear();
    triangleconnections.clear();
    for(int i=0;i<DEFAULT_NUM;i++){
        triangles.push_back(TriangleElement());
        triangles.back().set_color(color);
        triangles.back().set_position(position);
        triangles.back().set_speed(ofVec2f(ofRandom(-speed_range,speed_range),ofRandom(-speed_range,speed_range)));
    }
    int random_max = triangles.size();
    int index1,index2,index3;
    for(int i =0;i<DEFAULT_NUM;i++){
        index1 = ofRandom(random_max);
        index2 = ofRandom(random_max);
        index3 = ofRandom(random_max);
        
        connections.push_back(Connection());
        connections.back().set_node(triangles.at(index1).get_position(), triangles.at(index2).get_position());
    }
    
    for(int i =0;i<DEFAULT_NUM;i++){
        index1 = ofRandom(random_max);
        index2 = ofRandom(random_max);
        index3 = ofRandom(random_max);
        
        triangleconnections.push_back(TriangleConnection());
        triangleconnections.back().set_color(color);
        triangleconnections.back().set_3_pos(triangles.at(index1).get_position(), triangles.at(index2).get_position(), triangles.at(index3).get_position());
    }
}

void ExplodeAnimation::update(){
    int random_max = triangles.size();
    int index1 = ofRandom(random_max),index2,index3;
    for(int i =0;i<connections.size();i++){
        index2 = ofRandom(random_max);
        index3 = ofRandom(random_max);
        connections.at(i).set_node(triangles.at(index1).get_position(), triangles.at(index2).get_position());
    }
}

void ExplodeAnimation::draw(){
    update();

    ofPushStyle();
    ofSetCircleResolution(60);
    for(int i=0;i<triangles.size();i++){
        triangles.at(i).draw();
    }
    ofSetColor(color,100);
    ofSetLineWidth(0.5);
    for(int i =0;i<connections.size();i++){
        connections.at(i).draw();
    }
    ofFill();
    for(int i =0;i<triangleconnections.size();i++){
        triangleconnections.at(i).draw();
    }
    ofPopStyle();
}