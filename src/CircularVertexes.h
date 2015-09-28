//
//  CircularVertexes.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/27.
//
//

#ifndef __ofxAnimationUtility__CircularVertexes__
#define __ofxAnimationUtility__CircularVertexes__

#include <stdio.h>
#include "ofMain.h"

class CircularVertexes{
private:
    vector<ofVec2f>position;
    bool circular_mode;
    int vertex_num;
public:
    void set_vertex_num(int num);
    void set_circular_mode(bool mode);
    void add_center_position(float x, float y);
    void setup();
    void draw();
};

#endif /* defined(__ofxAnimationUtility__CircularVertexes__) */
