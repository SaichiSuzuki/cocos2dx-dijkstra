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

USING_NS_CC;

class GameScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(GameScene);
private:
    void update(float delta);
};

#endif /* GameScene_hpp */
