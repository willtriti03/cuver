#ifndef _LOADFILE_H_
#define _LOADFILE_H_

#include "ISceneNode.h"
class LoadFile :public ISceneNode{
private:
public:
	LoadFile();
	~LoadFile();

	void update(float eTime);
	void render();


};
#endif
