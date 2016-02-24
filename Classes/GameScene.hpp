//
//  GameScene.hpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "BoardLayer.hpp"

USING_NS_CC;

class GameScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
private:
    Size winSize;
    int posToArrayNum(Vec2 pos);
    Size boardSize;
    int mathSize;
    BoardLayer *bl;
    Sprite *player;
    int playerPos;
    void createPlayer(int pos, int size);
    void randPlayerPos();
    void moveCharactor(int num);
    void movePos();
    void touch();
    Vec2 getArrayFromPos(Vec2 pos);
    int getNumFromArray(Vec2 array);
    Vec2 getArrayFromNum(int num);
    Vec2 getMapPos(int num);
    void showDebug();
};

#endif /* GameScene_hpp */
