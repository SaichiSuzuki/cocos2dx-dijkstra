//
//  PlayerController.cpp
//  Dijkstra
//
//  Created by saichi on 2016/02/23.
//
//

#include "PlayerController.hpp"

USING_NS_CC;

PlayerController* PlayerController::create(int pos){
    PlayerController* p = new PlayerController();
    if(p && p -> init(pos)){
        p -> autorelease();
        return p;
    }
    CC_SAFE_DELETE(p);
    return nullptr;
}
bool PlayerController::init(int pos){
    // ボードのサイズよりposの2次元配列を求め，位置を決める
//    this->setSpriteFrame("simaumar03.png");
    CCTexture2D *pTexture = CCTextureCache::sharedTextureCache()->addImage("simaumar03.png");
//    this->setTexture("simaumar03.png");
    this->setTexture(pTexture);
    return true;
}