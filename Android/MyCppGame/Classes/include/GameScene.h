#pragma once
#include "PauseMenuScene.h"
#include "GameOverScene.h"
#include "cocos2d.h"
#include"GameData.h"
#include "GameStates.h"

class GameScene : public cocos2d::Layer
{
public:
	GameStates m_gameState;
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);
	//add background
	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);
	CREATE_FUNC(GameScene);
};