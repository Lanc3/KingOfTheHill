#include "GameScene.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameScene::create();
	auto label = Label::createWithSystemFont("GameScene", "Arial", 96);
	label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
	//layer->addChild(label, 1);
	scene->addChild(layer);

	return scene;
}
void GameScene::activatePauseScene(Ref *pSender)
{
	auto scene = PauseMenuScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScene::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto pauseItem =
		MenuItemImage::create("GameScene/Pause_Button.png",
		"GameScene/Pause_Button(Click).png",
		CC_CALLBACK_1(GameScene::activatePauseScene, this));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	// Add this line here:
	//addBackGroundSprite(visibleSize, origin);
	m_gameState = GameStates::PlaceGunTower;
	return true;
}

void GameScene::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto backgroundSprite = Sprite::create(ptr->m_backgroundTextureFile);

	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
}