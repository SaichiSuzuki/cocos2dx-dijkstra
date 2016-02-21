//
//  GameScene.cpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#include "GameScene.hpp"
#include "BoardLayer.hpp"

USING_NS_CC;
using namespace std;

Scene* GameScene::createScene(){
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    
    return scene;
}
bool GameScene::init(){
    if(!Layer::init()){
        return false;
    }
    
    Size winSize = Director::getInstance()->getVisibleSize();
    auto bg = LayerColor::create(Color4B(200, 230, 250, 255), winSize.width, winSize.height);
    this->addChild(bg);
    
    // create board
    auto bl = BoardLayer::create();
    bl->createBoard(10, 10);
    this->addChild(bl);
    
    this->scheduleUpdate();
    return true;
}

void GameScene::update(float delta){
//    log("call me %d", rand()%10);
}
