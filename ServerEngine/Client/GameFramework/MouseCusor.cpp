#include "MouseCusor.h"

MouseCusor::MouseCusor(){
	m_pCusor = new Sprite();
	m_pCusor->Create("");
	pushScene(m_pCusor, false);
	

	
};
MouseCusor::~MouseCusor(){};
void MouseCusor::update(float eTime){
	ISceneNode::update(eTime);

	m_pCusor->update(eTime);

	RECT tmp;
	GetCursorPos(&currentMousePoint);      
	GetWindowRect(GameApp->GetHWND(), &tmp);
	x = currentMousePoint.x - tmp.left;
	y = currentMousePoint.y - tmp.top;
	m_pCusor->setPosition(D3DXVECTOR2(x - 10, y - 30 + 0.05*(y % (tmp.bottom - tmp.top))));
}
void MouseCusor::render(){
	m_pCusor->render();
}
