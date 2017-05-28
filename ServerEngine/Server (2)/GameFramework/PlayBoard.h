#ifndef _PLAYBOARD_H_
#define _PLAYBOARD_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include "GUIButton.h"
#include "PathMgr.h"

class PlayBoard :public ISceneNode{
private:
	Sprite		*m_pPlat;

	GUIButton	*m_pSelectBTN;
	GUIButton	*m_pCloseBTN;
public:
	PlayBoard();
	~PlayBoard();
	
	void	NewPage();
	void	ClosePage();
	
	int		PageLocation();

	void	update(float eTime);
	void	render();

};
#endif
