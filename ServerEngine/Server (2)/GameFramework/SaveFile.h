#ifndef _SAVEFILE_H_
#define _SAVEFILE_H_

#include "ISceneNode.h"
class SaveFile :public ISceneNode{
private:
public:
	SaveFile();
	~SaveFile();

	void update(float eTime);
	void render();

};
#endif
