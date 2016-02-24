//
//  PlayerController.hpp
//  Dijkstra
//
//  Created by saichi on 2016/02/23.
//
//

#ifndef PlayerController_hpp
#define PlayerController_hpp

#include <stdio.h>

USING_NS_CC;

class PlayerController : public cocos2d::Sprite{
public:
    static PlayerController* create(int pos);
    virtual bool init(int pos);
private:
};

#endif /* PlayerController_hpp */