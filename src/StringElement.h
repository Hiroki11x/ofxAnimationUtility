//
//  StringElement.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/11.
//
//

#ifndef __ofxAnimationUtility__StringElement__
#define __ofxAnimationUtility__StringElement__

#include "ofMain.h"

class StringElement{
public:
    void setString(string arg);
    void drawString(float x, float y);
private:
    string arg;
    
};

#endif /* defined(__ofxAnimationUtility__StringElement__) */
