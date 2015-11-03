#pragma once
#include "GameScene.h"
#include "MainMenuScene.h"
#include "cocos2d.h"

class PauseMenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when resume is selected.
	void resume(Ref *pSender);
	// Called when main menu is selected.
	void activateMainMenuScene(Ref *pSender);
	// Called when retry is selected.
	void retry(Ref *pSender);
	CREATE_FUNC(PauseMenuScene);
};