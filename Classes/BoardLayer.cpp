//
//  BoardLayer.cpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#include "BoardLayer.hpp"

USING_NS_CC;
using namespace std;

//Scene* BoardLayer::createScene(){
//    auto scene = Scene::create();
//    auto layer = BoardLayer::create();
//    scene->addChild(layer);
//    
//    return scene;
//}
bool BoardLayer::init(){
    if(!Layer::init()){
        return false;
    }
    winSize = Director::getInstance()->getVisibleSize();
    return true;
}

void BoardLayer::createBoard(int x, int y){
    // ボード(背景)作成
    auto bg = LayerColor::create(Color4B(200, 250, 230, 255), winSize.width, winSize.width);
    this->addChild(bg);
    // ノード(マス)作成
    createNode(x, y);
}
void BoardLayer::createNode(int x, int y){
    log("%d * %d マスで生成します", x, y);
    int id = 0;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            id ++;
        }
    }
}