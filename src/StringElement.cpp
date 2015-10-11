//
//  StringElement.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/11.
//
//

#include "StringElement.h"

void StringElement::drawString(float x, float y){
    ofDrawBitmapString(arg, x,y);
}

void StringElement::setString(string arg){
    this->arg = arg;
}