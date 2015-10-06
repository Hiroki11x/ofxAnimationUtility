//
//  TriangleConnection.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#ifndef __ofxAnimationUtility__TriangleConnection__
#define __ofxAnimationUtility__TriangleConnection__

#include "ofMain.h"

class TriangleConnection{
private:
    ofVec2f pos1,pos2,pos3;
    ofColor color;
public:
    void set_color(ofColor arg_color);
    void set_3_pos(ofVec2f pos1, ofVec2f pos2,ofVec2f pos3);
    void init();
    void draw();
    ofVec2f get_pos1();
    ofVec2f get_pos2();
    ofVec2f get_pos3();
};

#endif /* defined(__ofxAnimationUtility__TriangleConnection__) */
