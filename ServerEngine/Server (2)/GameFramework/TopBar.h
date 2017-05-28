#ifndef _TOPBAR_H_
#define _TOPBAR_H_

#include "ISceneNode.h"
#include "GUIButton.h"
#include "PathMgr.h"

#define HEIGHT		35
#define WIDTH		164
#define MARGINE		5
#define MG_LEFT		15
#define MG_TOP      50

class TopBar :public ISceneNode{
private:
public:
	TopBar();
	~TopBar();
	
	GUIButton *m_pOption;
	GUIButton *m_pFile;
	GUIButton *m_pEdit;
	GUIButton *m_pHelp;

	void update(float eTime);
	void render();

};
#endif
