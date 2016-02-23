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
    
    winSize = Director::getInstance()->getVisibleSize();
    auto bg = LayerColor::create(Color4B(200, 230, 250, 255), winSize.width, winSize.height);
    this->addChild(bg);
    
    int boardX = 5;
    int boardY = 8;
    
    boardSize = Size(boardX, boardY);
    
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
        this->posToArrayNum(pos);
        return true;
    };
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
int GameScene::posToArrayNum(Vec2 pos) {
        // タッチ位置より2次元配列データ取得(/の右の式はマスのサイズ)
        int ax = pos.x / (winSize.width/boardSize.width);
        int ay = pos.y / (winSize.width/boardSize.width);
        // マスからはみ出てなければ
        if (ay < boardSize.height) {
            // タッチ位置より1次元配列データ取得(*の右の式はy軸の要素数)
            int num = ay + (ax * (winSize.width/(winSize.width/boardSize.height)));
            moveCharactor(num);
        }
    return 0;
}

void GameScene::moveCharactor(int num) {
    log("search S:0 G:%d", num);
    Vector<NodeLayer*> route = bl->searchRoute(0, num);
    log("route: ");
    for (auto node: route) {
        log("%d, ", node->getId());
    }
    // vecがあれば
    // forでvec回してsequenceで絶対位置に移動
    // アニメーションスタート
}