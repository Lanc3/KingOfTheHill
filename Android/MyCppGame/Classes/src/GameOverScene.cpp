#include "GameOverScene.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	auto label = Label::createWithSystemFont("OVER", "Arial", 96);
	label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
	//layer->addChild(label, 1);
	scene->addChild(layer);

	return scene;
}
void GameOverScene::activateGameScene(cocos2d::Ref *pSender)
{
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOverScene::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
bool GameOverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto menuTitle =
		MenuItemImage::create("GameOverScene/Game_Over.png",
		"GameOverScene/Game_Over.png");
	auto retryItem =
		MenuItemImage::create("GameOverScene/Retry_Button.png",
		"GameOverScene/Retry_Button(Click).png",
		CC_CALLBACK_1(GameOverScene::activateGameScene, this));
	auto mainMenuItem =
		MenuItemImage::create("GameOverScene/Menu_Button.png",
		"GameOverScene/Menu_Button(Click).png",
		CC_CALLBACK_1(GameOverScene::activateMainMenuScene, this));
	auto menu = Menu::create(menuTitle, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	this->addChild(menu);

	return true;
}