#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "InputManager.h"
#include "GUIButton.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Edit:public ISceneNode
{

private:
	string name;
	string path;
	string mapPath;

	Sprite *m_pMap;

	int mouseMode = 0;
	int move;
	int charCnt = 0;;
	int fanCnt=0;
	int fireCnt=0;
	int npcCnt=0;
	int phillaCnt=0;
	int stickCnt=0;
	int touchCnt=0;
	int windCnt=0;
	
	D3DXVECTOR2		*firePoint;
	D3DXVECTOR2		*windPoint;
	D3DXVECTOR2		*npcPoint;
	D3DXVECTOR2		*phillaPoint;
	D3DXVECTOR2		*stickPoint;
	D3DXVECTOR2		*touchPoint;
	D3DXVECTOR2		*fanPoint;

	GUIButton		*m_pfire;
	GUIButton		*m_pwind;
	GUIButton		*m_pnpc;
	GUIButton		*m_pphilla;
	GUIButton		*m_pstick;
	GUIButton		*m_ptouch;
	GUIButton		*m_pfan;
public:


	Edit();
	~Edit();

	void update(float eTime);
	void render();
	void Load();
	void Save();
};

