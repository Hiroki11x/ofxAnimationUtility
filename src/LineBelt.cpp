//
//  LineBelt.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/24.
//
//

#include "LineBelt.h"

void LineBelt::set_mode(){
    mode = !mode;
}

void LineBelt::set_center_y(float y){
    pos_center_y = y;
}

void LineBelt::set_line_num(int line_num){
    this->line_num = line_num;
}

void LineBelt::generate_position(){
    for(int i = 0;i<line_num;i++){
        position.push_back(ofRandom(ofGetWidth()));
    }
}

void LineBelt::generate_color(){
    for(int i = 0;i<line_num;i++){
        color.push_back(ofColor::fromHsb(ofRandom(255), 190, 190));
    }
}


void LineBelt::set_line_length(float line_length){
    this->line_length = line_length;
}


void LineBelt::setup_belt(int num){
    set_line_num(num);
    set_line_length(200);
    set_center_y(ofGetHeight()/2);
    generate_position();
    generate_color();
}

void LineBelt::update_belt(){
    
    JsonReceiver::recieve();
    
    for(int i = 0;i<line_num;i++){
        float addition_x = ofRandom(-100,100);
        if(!(position.at(i)+addition_x >ofGetWidth()) && !(position.at(i)+addition_x <0)){
            if(mode==false){//元はこれ
                position.at(i)+=addition_x;
            }else{
                addition_x = ofRandom(-0.1,0.1);
                position.at(i)+=addition_x;
//                position.at(i)= position.at(i%20)+addition_x;
            }
        }
    }
}

void LineBelt::mouseMoved(int x, int y){
    this->mouse_x = x;
}

void LineBelt::draw_belt(){
    for(int i = 0;i<line_num;i++){
        ofSetColor(color.at(i));
        if(this->mouse_x == (int)position.at(i)){//mouseXとおなじX座標の線があれば
            ofRect(position.at(i)-5, pos_center_y-line_length, 10, line_length*2);
            ofDrawBitmapString("pos index: "+ofToString(i),position.at(i)-10,pos_center_y-line_length-10);
        }else{
            ofLine(position.at(i), pos_center_y-line_length/2, position.at(i), pos_center_y+line_length/2);
        }
    }
    
    ofSetColor(255);
    for(int i = 0; i < JsonReceiver::usersInfo.size(); i++){
        JsonReceiver::usersInfo.at(i).icon.draw(position.at(i)-50, pos_center_y-line_length, 20, 20);
    }
}