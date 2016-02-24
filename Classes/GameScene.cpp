//
//  GameScene.cpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#include "GameScene.hpp"
#include "BoardLayer.hpp"
#include "PlayerController.hpp"

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
    
    int boardX = 20;
    int boardY = 30;
    
    boardSize = Size(boardX, boardY);
    mathSize = winSize.width/boardSize.width;
    
    // create board
    bl = BoardLayer::create();
    bl->createBoard(boardSize.width, boardSize.height);
    this->addChild(bl);
    
    // create player
    int playerSize = mathSize * 0.7; //1マス * 0.7
    randPlayerPos();
    createPlayer(playerPos, playerSize);
    
    // touch
    touch();
    
    // Debug log
//    showDebug();
    
    return true;
}

void GameScene::createPlayer(int pos, int size) {
    player = Sprite::create("simaumar03.png");
    player->setPosition(getMapPos(pos));
    auto bSize = player->getContentSize();
    auto aSize = Size(size,size);
    player->setScale(aSize.width/bSize.width, aSize.height/bSize.height);
    this->addChild(player);
}
void GameScene::randPlayerPos() {
    playerPos = random(0,(int)(boardSize.width * boardSize.height) - 1);
    // 壁なら
    if (bl->getAllNode().at(playerPos)->getKind() == 1) {
        randPlayerPos();
    }
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
void GameScene::moveCharactor(int num) {
//    log("search S:0 G:%d", num);
    Vector<NodeLayer*> route = bl->searchRoute(playerPos, num);
    for (auto dist: bl->getAllNode().at(num)->getNeighborNodeDist()) {
//        log("距離:%d", dist);
    }
    if (route.size() == 0) { //壁等に引っかかった場合終了
        log("かべ");
        return;
    }
    Vector<MoveTo*> moves;
    Sequence* seq;
    int firstFlag = true;
    for (auto Node: route) {
        auto move = MoveTo::create(0.05, getMapPos(Node->getId()));
        if (firstFlag) {
            firstFlag = false;
            seq = Sequence::create(move, NULL);
        } else {
            seq = Sequence::create(seq, move, NULL);
        }
    }
    playerPos = route.at(route.size()-1)->getId();
    player->runAction(seq);
}
int GameScene::posToArrayNum(Vec2 pos) {
        // タッチ位置より2次元配列データ取得
       Vec2 touchArray = getArrayFromPos(pos);
        // マスからはみ出てなければ
        if (touchArray.y < boardSize.height) {
            // タッチ位置より1次元配列データ取得
            moveCharactor(getNumFromArray(touchArray));
        }
    return 0;
}
/**
 *  xy座標より2次元配列を求める
 *  @param pos xy座標
 *  @return 2次元配列
 */
Vec2 GameScene::getArrayFromPos(Vec2 pos) {
    // /の右の式はマスのサイズ
        int ax = pos.x / mathSize;
        int ay = pos.y / mathSize;
    return Vec2(ax, ay);
}
/**
 *  2次元配列よりマス番号を求める
 *  @param array 2次元配列
 *  @return マスの番号
 */
int GameScene::getNumFromArray(Vec2 array) {
    // *の右の式はy軸の要素数
    int num = array.y + (array.x * (winSize.width/(winSize.width/boardSize.height)));
    return num;
}
/**
 *  マス番号より2次元配列を求める
 *  @param num マス番号
 *  @return 2次元配列
 */
Vec2 GameScene::getArrayFromNum(int num) {
    return Vec2(num/(int)boardSize.height, num % (int)boardSize.height);
}
/**
 *  マス上の位置を取得する
 *  @param num マス番号
 *  @return 位置
 */
Vec2 GameScene::getMapPos(int num) {
    Vec2 vec = getArrayFromNum(num);
    vec.x = vec.x * mathSize + (mathSize/2);
    vec.y = vec.y * mathSize + (mathSize/2);
    return vec;
}

void GameScene::showDebug() {
    
    string numStr = "";
    for (int i=0; i<boardSize.width; i++){
        for (int j=0; j<boardSize.height; j++){
            numStr = std::to_string(j + (i * (int)boardSize.height));
            auto numText = Label::createWithSystemFont(numStr, "HiraKakuProN-W6", 20);
            numText->setColor(Color3B::BLACK);
            numText->setPosition(Point(mathSize*i + mathSize/2, mathSize*j + mathSize/2));
            this->addChild(numText);
        }
    }
}