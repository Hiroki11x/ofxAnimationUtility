//
//  PathManager.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/23.
//
//

#include "PathManager.h"

void PathManager::set_size(int size){
    this->size = size;
}

void PathManager::set_num(int num){
    this->num = num;
}

void PathManager::set_path_color(ofColor color){
    this->color = color;
}

void PathManager::set_path_width(float width){
    this->width = width;
}


void PathManager::setup_path(int num){
    set_num(num);
    set_size(50);
    set_path_width(0.1);
    calculate_column_row(num);
    generate_position();
    generate_path();
}


ofVec2f PathManager::calculate_column_row(int num){
    int x = (int)sqrt(num);
//    cout << "x: " << x<<endl;
    int y = num/x;
//    cout << "y: " << y<<endl;
    this->num = x*y;
//    cout << "num: " << num<<endl;
    return ofVec2f(x,y);
}

void PathManager::generate_position(){
    float mergin = 50;
    float base_x,base_y;
    ofVec2f temp = calculate_column_row(num);
    float x = temp.x;
    float y = temp.y;
    float width = ofGetWidth()/x;
    float height = ofGetHeight()/y;
    for(int i = 0; i < x ; i++){
        for(int j = 0; j < y ; j++){
            base_x = i*width+mergin;
            base_y = j*height+mergin;
            position.push_back(ofVec2f(base_x,base_y));
            tri1.push_back(ofVec2f(size*cos(PI)+base_x, size*sin(PI)+base_y));
            tri2.push_back(ofVec2f(size*cos(PI/3)+base_x, size*sin(PI/3)+base_y));
            tri3.push_back(ofVec2f(size*cos(-PI/3)+base_x, size*sin(-PI/3)+base_y));
        }
    }
}


void PathManager::generate_path(){
    for(int i = 0; i < num ; i++){
        path.push_back(ofPath());
        path.back().setMode(ofPath::POLYLINES);
        path.back().setStrokeColor(color);
        path.back().setStrokeWidth(width);
        path.back().setFilled(false);
        path.back().setCircleResolution(60);
    }
}
void PathManager::update_size(){
    size = ofRandom(60);
}

void PathManager::update_path(){
    for(int i = 0; i < num ; i++){
        path.at(i).clear();//Meshと同様に頂点情報を消していく
        
        tri1.at(i) = tri1.at(i).rotateRad(ofGetElapsedTimef()/10, position.at(i));
        tri2.at(i) = tri2.at(i).rotateRad(ofGetElapsedTimef()/10, position.at(i));
        tri3.at(i) = tri3.at(i).rotateRad(ofGetElapsedTimef()/10, position.at(i));
        
        path.at(i).lineTo(tri2.at(i));
        path.at(i).moveTo(tri1.at(i));
        path.at(i).arc(0+ofGetWidth()/2, 0+ofGetHeight()/2, 200, 200, 10*ofGetElapsedTimef(), 10*ofGetElapsedTimef()+1);
        path.at(i).lineTo(tri3.at(i));
        path.at(i).arc(0+ofGetWidth()/2, 0+ofGetHeight()/2, 200, 200, 10*ofGetElapsedTimef()+180, 10*ofGetElapsedTimef()+181);
        path.at(i).lineTo(tri1.at(i));
        //path.at(i).triangle(tri1.at(i),tri2.at(i),tri3.at(i));
        
    }
    
}

void PathManager::draw_path(){
    for(int i = 0; i < num ; i++){
        path.at(i).draw();
    }
}