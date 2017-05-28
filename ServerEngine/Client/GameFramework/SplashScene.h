#ifndef _SPLASHSCNEN_H_
#define _SPLASHSCENE_H_

#include "ISceneNode.h"
#include "Sprite.h"
class SplashScene:public ISceneNode{
private:
	int time;
	Sprite *m_pSpriteImg;
	Sprite *m_pBack;

public:
	SplashScene();
	~SplashScene();

	void update(float eTime);
	void render();



};
#endif	_SPLASHSCENE_H_