//
//  TitleScene.cpp
//  Dijkstra
//
//  Created by saichi on 2016/02/24.
//
//

#include "TitleScene.hpp"
#include "GameScene.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace std;

Scene* TitleScene::createScene(){
    auto scene = Scene::create();
    auto layer = TitleScene::create();
    scene->addChild(layer);
    
    return scene;
}
bool TitleScene::init(){
    if(!Layer::init()){
        return false;
    }
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // テキストフィールド
    auto textField = ui::TextField::create();
    textField->setPosition(Point(200, winSize.height/2));
    textField->setColor(Color3B::WHITE);
    textField->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
    });
    this->addChild(textField);
    
    // テキストフィールド置きたい
    // 変数として内容使う
    // ピッカーでもいいかも
    // シーン間の値受け渡し
    // 永久保存
    
    // start button
    auto button = ui::Button::create();
    button->loadTextures("CloseSelected.png", "CloseSelected.png", "CloseSelected.png");
    button->setPosition(Point(winSize.width/2, winSize.height/2));
    button->addTouchEventListener(CC_CALLBACK_2(TitleScene::buttonTouchEventListener, this));
    this->addChild(button);
    
    return true;
}

void TitleScene:: buttonTouchEventListener(Ref* pSender, ui::Widget::TouchEventType type)
{
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::MOVED:
            break;
        case ui::Widget::TouchEventType::CANCELED:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(GameScene::createScene());
            break;
        default:
            break;
    }
}
