#ifndef _TOOLBAR_H_
#define _TOOLBAR_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include "GUIButton.h"
#include "ToolBtn.h"
#include "PathMgr.h"


#define BTN_WIDTH 40
#define BTN_HEIGHT 48
#define BOX_WIDTH 95
#define BOX_HEIGHT 60
#define DISTENCE 15
#define BOX_DISTENCE 25
#define BTN_TOP_DISTENCE 240
#define BTN_MARGINE 15
#define BOX_MARGINE 10

class ToolBar :public ISceneNode{
private:
	bool btn_click = false;
	int PasteBtn = 0;
	int SQ_paste = 0;
	GUIButton	*m_pCircleBTN[7];
	GUIButton	*m_pSquarBTN[8];
	Sprite		*m_pline;
	Sprite		*m_pBlackTri;
	Sprite		*m_pGreenTri;

	void ToolBoxClear();
public:
	ToolBar();
	~ToolBar();

	/////////////////////UserBtn FucTion//////////////////////////
	

	//////////////////////////////////////////////////////////////

	void update(float eTime);
	void render();
};

#endif