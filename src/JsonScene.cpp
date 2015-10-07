//
//  JsonScene.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#include "JsonScene.h"

void JsonScene::init(){
    
}
void JsonScene::update(){
    JsonReceiver::recieve();
}
void JsonScene::draw(){
    float x,y;
    float offset;
    for(int i = 0; i < JsonReceiver::usersInfo.size(); i++){
        x = i ;
        y = ((100 * i)/(int)ofGetWidth());
        offset = ofGetWidth()*y;
        JsonReceiver::usersInfo.at(i).icon.draw( 100 * x -offset  , 100 * y, 100, 100);
    }
}