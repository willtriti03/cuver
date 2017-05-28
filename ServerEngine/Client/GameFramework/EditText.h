#ifndef _EDITTEXT_H_
#define _EDITTEXT_H_
#include "ISceneNode.h"
#include "Sprite.h"
#include "GUIButton.h"
#include "Font.h"
class EditText : public ISceneNode{
private:
	GUIButton *m_pEditText;

	CFont *m_pInput;
public:
	EditText();
	~EditText();

	void InputStart();
	void update(float eTime);
	void render();




};

#endif 