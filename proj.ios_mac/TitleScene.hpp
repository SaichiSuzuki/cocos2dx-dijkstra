//
//  TitleScene.hpp
//  Dijkstra
//
//  Created by saichi on 2016/02/24.
//
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include <stdio.h>
#include "ui/CocosGUI.h"

USING_NS_CC;

class TitleScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(TitleScene);
private:
    void buttonTouchEventListener(Ref* pSender, ui::Widget::TouchEventType type);
};

#endif