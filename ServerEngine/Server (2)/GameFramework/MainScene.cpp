#include"MainScene.h"
#include <conio.h>
#include "Wheel.h"
#include "BroadCast.h"
#include "InputManager.h"
#include "DebugFile.h"
#include <iostream>
#include <fstream>

MainScene::MainScene(){




	m_pCursor = new MouseCusor();
	m_pTopBar = new TopBar();
	m_pToolBar = new ToolBar();
	m_pPlayBoard = new PlayBoard();
	m_pRightTool = new RightTool();

	(BroadMgr->CppFileName).push_back("main.cpp");
	(BroadMgr->HeaderFileName).push_back("main.h");
	BroadMgr->mouseMode = 1;
	//	Debugs->Debug();

}

MainScene::~MainScene(){

}

void MainScene::update(float eTime){
	ISceneNode::update(eTime);
	m_pTopBar->update(eTime);
	m_pToolBar->update(eTime);
	m_pPlayBoard->update(eTime);
	m_pRightTool->update(eTime);
	m_pCursor->update(eTime);

	if (InputMgr->keyState('S')==2){
		BroadMgr->mouseMode = 2;
	}
	if (InputMgr->keyState('D') == 2){
		BroadMgr->mouseMode = 1;
	}

}

void MainScene::render(){
	ISceneNode::render();

	m_pTopBar->render();
	m_pToolBar->render();
	m_pPlayBoard->render();
	m_pRightTool->render();
	m_pCursor->render();

}
