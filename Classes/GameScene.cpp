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
    
    boardSize = Size(10, 10);
    
    // create board
    bl = BoardLayer::create();
    bl->createBoard(boardSize.width, boardSize.height);
    this->addChild(bl);
    
    // touch
    touch();
    
    return true;
}
void GameScene::touch() {
    //イベントリスナーを作成
    auto listener = EventListenerTouchOneByOne::create();
    //タッチ開始
    listener->onTouchBegan = [this](Touch* touch, Event* event){
        Vec2 pos = touch->getLocation();
        // タッチ位置よりid取得
        log("(%f, %f)", pos.x, pos.y);
        int ax = pos.x/boardSize.width;
        int ay = pos.y/boardSize.height;
        log("(%d, %d)", ax, ay);
        bl->searchRoute(1);
        return true;
    };
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
