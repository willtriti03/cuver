#include "RightTool.h"
#include "PathMgr.h"

#define SIDE 1236

RightTool::RightTool()
{
	m_pFileList = new Sprite();
	m_pFileList->Create(PathMgr->filelist);
	m_pFileList->setPosition(D3DXVECTOR2(SIDE,215));
	pushScene(m_pFileList, false);

	m_pFileName = new GUIButton();
	m_pFileName->AddUsualButtonImage(PathMgr->file_name);
	m_pFileName->AddOnButtonImage(PathMgr->file_name);
	m_pFileName->setPosition(D3DXVECTOR2(SIDE+1,175));

	m_plogo = new Sprite();
	m_plogo->Create(PathMgr->logo);
	m_plogo->setPosition(D3DXVECTOR2(SIDE,7));
}


RightTool::~RightTool()
{
}

void RightTool::update(float eTime){
	ISceneNode::update(eTime);
	m_pFileList->update(eTime);
	m_pFileName->update(eTime);
	m_plogo->update(eTime);
}

void RightTool::render(){
	ISceneNode::render();
	m_pFileList->render();
	m_pFileName->render();
	m_plogo->render();
}
