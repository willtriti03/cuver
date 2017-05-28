#include "MouseCusor.h"
#include "PathMgr.h"
MouseCusor::MouseCusor(){
	m_pCusor = new Sprite();
	m_pCusor->Create(PathMgr->cursor);
	pushScene(m_pCusor, false);
	

	
};
MouseCusor::~MouseCusor(){};
void MouseCusor::update(float eTime){
	ISceneNode::update(eTime);

	m_pCusor->update(eTime);

	GetCursorPos(&currentMousePoint);      
	ScreenToClient(GameApp->GetHWND(), &currentMousePoint);

	x = currentMousePoint.x;
	y = currentMousePoint.y;
	m_pCusor->setPosition(D3DXVECTOR2(x ,y));
}
void MouseCusor::render(){
	m_pCusor->render();
}
