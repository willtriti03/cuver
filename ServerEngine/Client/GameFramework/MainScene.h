#ifndef _MAINSCENE_H_
#define _MAINSCENE_H_

#include"ISceneNode.h"
#include "Sprite.h"
#include "Font.h"
#include <string>
class MainScene : public ISceneNode{
private:

	
public:

	MainScene();
	~MainScene();

	void render();
	void update(float eTime);

};

#endif