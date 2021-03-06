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
    bool circular_mode,angle_mode;
    int vertex_num;
    float radius;
    
    void set_radius(float radius);
    void set_vertex_num(int num);//図形を何個書くか
    void set_angle_mode(bool angle_mode);
    void set_circular_mode(bool circular_mode);
    void add_center_position(float x, float y);
    float update_angle(bool angle_mode, int i,  int vertex_size);
public:
    void setup();
    void draw();
};

#endif /* defined(__ofxAnimationUtility__CircularVertexes__) */
