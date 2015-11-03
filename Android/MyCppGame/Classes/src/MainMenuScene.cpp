#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	auto label = Label::createWithSystemFont("MainMenu", "Arial", 96);
	label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
	//layer->addChild(label, 1);
	scene->addChild(layer);

	return scene;
}
void MainMenu::activateGameScene(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto menuTitle =
		MenuItemImage::create("MainMenuScene/Game_Title.png",
		"MainMenuScene/Game_Title.png");
	auto playItem =
		MenuItemImage::create("MainMenuScene/Play_Button.png",
		"MainMenuScene/Play_Button(Click).png",
		CC_CALLBACK_1(MainMenu::activateGameScene, this));
	auto menu = Menu::create(menuTitle, playItem, NULL);

	// Returns visible size of OpenGL window in points.
	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height /4);
	//menu->alignItemsHorizontallyWithPadding(visibleSize.width / 8);
	
	menu->setScale(1);
	this->addChild(menu);

	return true;
}