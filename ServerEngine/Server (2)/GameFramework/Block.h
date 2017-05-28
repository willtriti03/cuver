#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include "GUIButton.h"
#include <string>
class BroadCast;
using namespace std;
class Block :public ISceneNode{
private:
	Sprite	*m_pBase;

	Block	*m_pInput;
	Block	*m_pMotherBlock;
	RECT	tmp_collision;

	POINT	currentMousePoint;
	
	int		btn_state = 0;
	int		sv_x, sv_y,x,y,sv_point_x,sv_point_y;
	int		identity[2];

	bool    clickBool;
	bool	moveLock;

	bool	OnMouseEnter();
	bool	CrashCheck(Block *m_pBlock);

	void	updateCollision();
public:
	Block();
	~Block();

	RECT	collision;

	string	inform;

	bool	OnMouseClicked();
	bool	OnReleased();
	bool	InClick();

	string	ReturnCode();

	void	AddBlockImage(std::string path);
	void	InputAdd(Block *m_pInputItem);
	void	setPos(int x,int y);
	void	MoveLock();
	void	GiveIdentity(int kind,int num);
	void	YourMotherBlock(Block *m_pMother);
	void	YourBabyBlock(Block *m_pBaby);
	void	InputCode(string code);
	void	DeleteBlock();

	void	update(float eTime);
	void	render();

};

#endif
