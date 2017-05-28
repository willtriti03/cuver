#ifndef _NEWFILE_H_
#define _NEWFILE_H_

#include "ISceneNode.h"
class NewFile :public ISceneNode{
private:
public:
	NewFile();
	~NewFile();

	void update(float eTime);
	void render();

};
#endif