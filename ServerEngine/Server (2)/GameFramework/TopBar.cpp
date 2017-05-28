#include "TopBar.h"

TopBar::TopBar(){
	m_pFile		=new GUIButton();
	m_pOption 	=new GUIButton();
	m_pEdit		=new GUIButton();
	m_pHelp		=new GUIButton();

	m_pFile		->AddUsualButtonImage(PathMgr->file_n);
	m_pOption	->AddUsualButtonImage(PathMgr->tool_n);
	m_pEdit		->AddUsualButtonImage(PathMgr->option_n);
	m_pHelp		->AddUsualButtonImage(PathMgr->help_n);

	m_pFile		->AddOnButtonImage(PathMgr->file_c);
	m_pOption	->AddOnButtonImage(PathMgr->tool_c);
	m_pEdit		->AddOnButtonImage(PathMgr->option_c);
	m_pHelp		->AddOnButtonImage(PathMgr->help_c);

	m_pFile		->setPosition(D3DXVECTOR2(MG_LEFT,MG_TOP));
	m_pOption	->setPosition(D3DXVECTOR2(MG_LEFT,MG_TOP+HEIGHT+MARGINE));
	m_pEdit		->setPosition(D3DXVECTOR2(MG_LEFT, MG_TOP + HEIGHT*2 + MARGINE*2));
	m_pHelp		->setPosition(D3DXVECTOR2(MG_LEFT, MG_TOP + HEIGHT*3 + MARGINE*3));

	pushScene(m_pOption,false); 
	pushScene(m_pFile  ,false);
	pushScene(m_pEdit  ,false);
	pushScene(m_pHelp  ,false);

}

TopBar::~TopBar(){}

void TopBar::update(float eTime){
	ISceneNode::update(eTime);
	m_pFile		->update(eTime);
	m_pOption	->update(eTime);
	m_pEdit		->update(eTime);
	m_pHelp		->update(eTime);
}

void TopBar::render(){
	ISceneNode::render();
	m_pFile		->render();
	m_pOption	->render();
	m_pEdit		->render();
	m_pHelp		->render();
}