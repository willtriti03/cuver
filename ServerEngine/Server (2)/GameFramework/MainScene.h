#ifndef _MAINSCENE_H_
#define _MAINSCENE_H_

#include"ISceneNode.h"
#include "Sprite.h"
#include "Font.h"
#include "Block.h"
#include "PathMgr.h"
#include "MouseCusor.h"
#include "EditText.h"
#include "TopBar.h"
#include "PlayBoard.h"
#include "ToolBar.h"
#include "RightTool.h"

#include <string>
#include <list>
using namespace std;

class MainScene : public ISceneNode{
private:
public:
	string name;
	string path;
	string mapPath;


	EditText *m_pEdit;
	MouseCusor *m_pCursor;
	TopBar	*m_pTopBar;
	ToolBar	*m_pToolBar;
	PlayBoard *m_pPlayBoard;
	RightTool *m_pRightTool;
public:

	MainScene();
	~MainScene();

	void render();
	void update(float eTime);

};

#endif