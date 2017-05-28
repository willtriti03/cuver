#pragma once
#ifndef _RIGHTTOOL_H_
#define _RIGHTTOOL_H_

#include "ISceneNode.h"
#include "GUIButton.h"
#include "Sprite.h"
class RightTool:public ISceneNode
{
private:
	Sprite		*m_plogo;
	Sprite		*m_pFileList;
	GUIButton	*m_pFileName;
	

public:
	RightTool();
	~RightTool();

	void render();
	void update(float eTime);
};
#endif

