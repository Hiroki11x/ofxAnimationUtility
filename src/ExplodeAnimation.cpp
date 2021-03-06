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

ofVec2f ExplodeAnimation::speed_generator(float range){//0に近いスピードができないように
    ofVec2f speed = ofVec2f(1,1);
    float angle = ofRandom(2*PI);
    float radius = ofRandom(range/2,range);
    speed.x = radius * cos(angle);
    speed.y = radius * sin(angle);
    return speed;
}

void ExplodeAnimation::set_position(ofVec2f pos){
    position = pos;
    for(int i =0;i<triangles.size();i++){
        triangles.at(i).set_position(pos);
    }
}



void ExplodeAnimation::init(){
    triangles.clear();
    connections.clear();
    triangleconnections.clear();
    
    for(int i=0;i<DEFAULT_PARTICLE_NUM;i++){
        triangles.push_back(TriangleElement());
        triangles.back().set_color(color);
        triangles.back().set_position(position);
        triangles.back().set_speed(speed_generator(speed_range));
    }
    
    int random_max = triangles.size();
    int index1,index2,index3;
    for(int i =0;i<DEFAULT_PARTICLE_NUM;i++){
        index1 = ofRandom(random_max);
        index2 = ofRandom(random_max);
        index3 = ofRandom(random_max);
        
        connections.push_back(Connection());
        connections.back().set_node(triangles.at(index1).get_position(), triangles.at(index2).get_position());
    }
    
    for(int i =0;i<DEFAULT_PARTICLE_NUM;i++){
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
    int index1,index2,index3;
    for(int i =0;i<connections.size();i++){
        index1 = ofRandom(random_max);
        index2 = ofRandom(random_max);
        index3 = ofRandom(random_max);
        connections.at(i).set_node(triangles.at(index1).get_position(), triangles.at(index2).get_position());
    }
}

void ExplodeAnimation::draw(){
    update();

    ofPushStyle();
    //Particle
    ofSetCircleResolution(60);
    bool isfade = false ;
    bool isclear =true ;
    for(int i=0;i<triangles.size();i++){
        triangles.at(i).draw();
        cout <<i <<": is fade :"<< triangles.at(i).is_fade()<<endl;
        isfade |= triangles.at(i).is_fade();
        isclear &= triangles.at(i).is_fade();//全部
    }
    
    cout <<"triangles.size"<<triangles.size()<<endl;
    cout <<"isfade"<<isfade<<endl;
    cout <<"isclear"<<isclear<<endl;
    
    if(isclear){//そもそも全てのparticleがはみ出たらvector削除
        
        triangles.clear();
        connections.clear();
        triangleconnections.clear();
        
    }else if(!isfade){//Particleがはみ出てたらTriangle表示しない
        //Line
        ofSetColor(color,100);
        ofSetLineWidth(0.5);
        for(int i =0;i<connections.size();i++){
            connections.at(i).draw();
        }
        
        //Triangle
        ofFill();
        for(int i =0;i<triangleconnections.size();i++){
            triangleconnections.at(i).draw();
        }
        
    }else{//particleは表示させない
        //Line
        ofSetColor(color,50);
        ofSetLineWidth(0.5);
        for(int i =0;i<connections.size();i++){
            connections.at(i).draw();
        }
    }
    ofPopStyle();
}