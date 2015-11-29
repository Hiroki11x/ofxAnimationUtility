//
//  JsonReceiver.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#ifndef __ofxAnimationUtility__JsonReceiver__
#define __ofxAnimationUtility__JsonReceiver__

#include "ofxJSON.h"
#include "ofMain.h"
#include "ofxSuperLogUtil.h"

class JsonReceiver {
    
    /**
     *jsonElement["user"]["name"].asCString()
     *であればuser{}内のnameタグ？についての取得
     */
    

    
public:
    struct UserInfo{//Usernameと画像情報を持つ構造体
        string text;//つぶやいた内容(これだけ["user"]内ではない)
        string userName;
        string userId;//screen_name @アカウント名
        int friends_count;//フォローしてるアカウント数
        int statuses_count;//つぶやいてる数
        int followers_count;
        ofImage icon;
    };
    

    
    static string cachedTweetId;
    
    static ofxJSONElement jsonElement;
    static vector<UserInfo> usersInfo;
    
    static void recieve(){
        
//        bool parsingSuccessful = jsonElement.openLocal("MAU_twit/twitter.json");//Nodeで取得したJSON
        //Nodeを　プロジェクトディレクトリとおなじ階層にいれた
        
        bool parsingSuccessful = jsonElement.openLocal("../../../MAU_twit/twitter.json");//Nodeで取得したJSON

//        parsingSuccessful =false; // Node動かさないときはこのコメントを外す
        
        static ofxSuperLogUtil log;
        
        if (parsingSuccessful){
            if(checkUpdateJson()){//新規キャッシュの際はパース
                log.set_log(parseJson());
                log.set_log("parse end");
            }
        }else{
            cout << "Failed to parse JSON" << endl;
        }
    };
    static string parseJson(){//userInfonい貯めていく
        ofImage img;
        img.loadImage(jsonElement["user"]["profile_image_url"].asCString());
        if(img.getWidth() == 0){return;}
        usersInfo.push_back((UserInfo){
            jsonElement["text"].asCString(),
            jsonElement["user"]["name"].asCString(),
            jsonElement["user"]["screen_name"].asCString(),
            jsonElement["user"]["friends_count"].asInt(),
            jsonElement["user"]["statuses_count"].asInt(),
            jsonElement["user"]["followers_count"].asInt(),
            img});
        return ofToString(jsonElement);
    };
    static bool checkUpdateJson(){
        if(jsonElement["id_str"].asCString() != cachedTweetId){//JSONで読んだidがキャッシュされていなかったらキャッシュ
            cachedTweetId = jsonElement["id_str"].asCString();
            return true;
        }else{
            return false;
        }
    };
    
private:
    JsonReceiver(){};
};

#endif /* defined(__ofxAnimationUtility__JsonReceiver__) */
