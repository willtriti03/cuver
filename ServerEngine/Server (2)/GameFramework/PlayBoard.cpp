#include "PlayBoard.h"

PlayBoard::PlayBoard(){
	m_pPlat			= new Sprite();

	m_pSelectBTN	= new GUIButton();
	m_pCloseBTN		= new GUIButton();

	m_pPlat->Create(PathMgr->task_pane);
	m_pPlat->setPosition(D3DXVECTOR2(190,60));
	
	m_pSelectBTN->AddOnButtonImage(PathMgr->task_green);
	m_pSelectBTN->AddUsualButtonImage(PathMgr->task);
	m_pSelectBTN->setPosition(D3DXVECTOR2(190, 32));
}

PlayBoard::~PlayBoard(){}


void PlayBoard::NewPage(){}

void PlayBoard::ClosePage(){}

int PlayBoard::PageLocation(){
	return 0;
}

void PlayBoard::update(float eTime){
	ISceneNode::update(eTime);
	m_pPlat->update(eTime);
	m_pSelectBTN->update(eTime);
}

void PlayBoard::render(){
	ISceneNode::render();
	m_pPlat->render();
	m_pSelectBTN->render();
}

