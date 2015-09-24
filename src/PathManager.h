//
//  PathManager.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/23.
//
//

#ifndef __ofxAnimationUtility__PathManager__
#define __ofxAnimationUtility__PathManager__

#include <stdio.h>
#include "ofMain.h"

class PathManager{
private:
    int num;
    vector<ofPath > path;
    vector<ofVec2f > position;
    vector<ofVec2f > tri1;
    vector<ofVec2f > tri2;
    vector<ofVec2f > tri3;
    ofColor color;
    float width;
    float size;
    
    void set_path_position();
    void generate_path();
    
    ofVec2f calculate_column_row(int num);
    void generate_position();
    void set_size(int size);
    void set_path_width(float width);
    void set_num(int num);
    
    void update_size();
    
public :
    PathManager(){};
    
    void set_path_color(ofColor color);
    
    void setup_path(int num);
    void update_path();
    void draw_path();
    
};

#endif /* defined(__ofxAnimationUtility__PathManager__) */
