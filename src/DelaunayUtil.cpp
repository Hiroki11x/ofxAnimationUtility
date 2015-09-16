//
//  DelaunayUtil.cpp
//  oF_Fade_Sample
//
//  Created by HirokiNaganuma on 2015/09/16.
//
//

#include "DelaunayUtil.h"

void DelaunayUtil::setup(){
    
    
    ps.push_back(ofPoint(0,0));
    ps.push_back(ofPoint(0,ofGetHeight()));
    ps.push_back(ofPoint(ofGetWidth(),0));
    ps.push_back(ofPoint(ofGetWidth(),ofGetHeight()));
    
    TrianglePoints tp1(0,1,2);
    TrianglePoints tp2(2,1,3);
    
    
    
    ts.push_back(tp1);
    ts.push_back(tp2);
    
}

void DelaunayUtil::draw(){
    /*
     if(DetDelaunay(triangle1,triangle2,triangle3,triangle4)){
     ofSetColor(150,100,150);
     }else{
     ofSetColor(100,200,50);
     }
     */
    ofNoFill();
    
    for(int i =0 ; i < ts.size() ; i++){
        //cout << ps[ts[i].tri1].x << endl;
        ofTriangle(ps[ts[i].tri1].x,ps[ts[i].tri1].y,
                   ps[ts[i].tri2].x,ps[ts[i].tri2].y,
                   ps[ts[i].tri3].x,ps[ts[i].tri3].y);
    }
    
    //ofCircle(triangle4.x,triangle4.y,10);
}

Boolean DelaunayUtil::DetDelaunay(
                           const ofPoint& p0,
                           const ofPoint& p1,
                           const ofPoint& p2,
                           const ofPoint& p3){
    float x = p3.x;
    float y = p3.y;
    float d = (p0.x*p0.x + p0.y*p0.y - x*x - y*y)*((p1.x-x)*(p2.y-y)-(p2.x-x)*(p1.y-y)) +
    (p1.x*p1.x + p1.y*p1.y - x*x - y*y)*((p2.x-x)*(p0.y-y)-(p2.y-y)*(p0.x-x)) +
    (p2.x*p2.x + p2.y*p2.y - x*x - y*y)*((p0.x-x)*(p1.y-y)-(p0.y-y)*(p1.x-x));
    return ( (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x)>0 ) ? d >= 0 : d<=0;
}

void DelaunayUtil::generate(float x, float y){
    ps.push_back(ofPoint(x,y));
    vector<TrianglePoints> ts_new;
    vector<LinePoints> ls_new_push;
    vector<LinePoints> ls_new;
    for(int j = ps.size()-1 ; j < ps.size();j++){
        ls_new.clear();
        ls_new_push.clear();
        ts_new.clear();
        for(int i =0 ; i < ts.size() ; i++){
            if(DetDelaunay(
                           ps[ts[i].tri1],
                           ps[ts[i].tri2],
                           ps[ts[i].tri3],
                           ps[j]
                           )
               ){
                ls_new.push_back(LinePoints(ts[i].tri1,ts[i].tri2));
                ls_new.push_back(LinePoints(ts[i].tri1,ts[i].tri3));
                ls_new.push_back(LinePoints(ts[i].tri2,ts[i].tri3));
            }else{
                ts_new.push_back(ts[i]);
            }
        }
        //cout << ls_new.size() << endl;
        for(int k =0 ; k < ls_new.size() ; k++){
            Boolean boolflag = true;
            
            for(int l = 0 ; l < ls_new.size() ; l++){
                if(l != k && ls_new[k].li1 == ls_new[l].li1 && ls_new[k].li2 == ls_new[l].li2){
                    boolflag = false;
                }
            }
            
            if(boolflag){
                ls_new_push.push_back(ls_new[k]);
            }
        }
        for(int m =0 ; m < ls_new_push.size() ; m++){
            ts_new.push_back(TrianglePoints(ls_new_push[m].li1,ls_new_push[m].li2,j));
        }
        ts.clear();
        ts = ts_new;
    }
}





