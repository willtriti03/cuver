#pragma once

#ifndef _SPLASHSCENE_H_
#define _SPLASHSCENE_H_


#include "ISceneNode.h"
#include "Sprite.h"
#include "SceneManager.h"
class SplashScene:public ISceneNode
{
private:
	int time;
	Sprite *m_pSplash;
public:
	SplashScene();
	~SplashScene();

	void update(float eTime);
	void render();
};

#endif

