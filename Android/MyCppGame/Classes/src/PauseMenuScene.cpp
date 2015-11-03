#include "PauseMenuScene.h"

USING_NS_CC;

Scene* PauseMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = PauseMenuScene::create();
	auto label = Label::createWithSystemFont("Pause", "Arial", 96);
	label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
	//layer->addChild(label, 1);
	scene->addChild(layer);

	return scene;
}
void PauseMenuScene::resume(Ref *pSender)
{
	Director::getInstance()->popScene();
}

void PauseMenuScene::activateMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseMenuScene::retry(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}
bool PauseMenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto resumeItem =
		MenuItemImage::create("PauseMenuScene/Resume_Button.png",
		"PauseMenuScene/Resume_Button(Click).png",
		CC_CALLBACK_1(PauseMenuScene::resume, this));
	auto retryItem =
		MenuItemImage::create("PauseMenuScene/Retry_Button.png",
		"PauseMenuScene/Retry_Button(Click).png",
		CC_CALLBACK_1(PauseMenuScene::retry, this));
	auto mainMenuItem =
		MenuItemImage::create("PauseMenuScene/Menu_Button.png",
		"PauseMenuScene/Menu_Button(Click).png",
		CC_CALLBACK_1(PauseMenuScene::activateMainMenuScene, this));
	auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	this->addChild(menu);

	return true;
}