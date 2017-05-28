#ifndef _EDITTEXT_H_
#define _EDITTEXT_H_
#include "ISceneNode.h"
#include "Sprite.h"
#include "Font.h"
#include "InputManager.h"
#include <string>
#include <iostream>
using namespace std;
class EditText : public ISceneNode{
private:
	RECT	 collision;
	POINT	 currentMousePoint;
	CFont	 *m_pInput;

	string	str;

	int		btn_state = 0;
	int		x, y, press[2] = {};

	void updateCollision(int x,int y);

	bool OnMouseClicked();
	bool OnMouseEnter();
	bool EditStart=false;
	bool Upper = false;
public:
	EditText(int x,int y);
	~EditText();

	void InputStart();
	void update(float eTime);
	void render();




};

#endif 