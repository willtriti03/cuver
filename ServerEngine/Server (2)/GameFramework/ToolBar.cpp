#include "ToolBar.h"

ToolBar::ToolBar(){
	for (int i = 0; i < 7; ++i){
		m_pCircleBTN[i] = new GUIButton();
		m_pCircleBTN[i]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[i]->AddOnButtonImage(PathMgr->toolCir_g);
		m_pCircleBTN[i]->setPosition(D3DXVECTOR2(DISTENCE, BTN_TOP_DISTENCE + BTN_HEIGHT*i + BTN_MARGINE*i));
	
		pushScene(m_pCircleBTN[i], false);
	}
	for (int i = 0; i < 8; ++i){
		m_pSquarBTN[i] = new GUIButton();
		m_pSquarBTN[i]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[i]->AddOnButtonImage(PathMgr->toolBox_g);
		m_pSquarBTN[i]->setPosition(D3DXVECTOR2(BOX_DISTENCE+DISTENCE+BTN_WIDTH, BTN_TOP_DISTENCE + BOX_HEIGHT*i + BOX_MARGINE*i-10));

		pushScene(m_pSquarBTN[i], false);
	}

	m_pline = new Sprite();
	m_pline->Create(PathMgr->line);
	m_pline->setPosition(D3DXVECTOR2(BOX_DISTENCE + DISTENCE + BTN_WIDTH-30, BTN_TOP_DISTENCE - 10));
	pushScene(m_pline, false);


	m_pBlackTri = new Sprite();
	m_pBlackTri->Create(PathMgr->line_left);
	m_pBlackTri->setPosition(D3DXVECTOR2(BOX_DISTENCE + DISTENCE + BTN_WIDTH - 30, BTN_TOP_DISTENCE - 6));
	pushScene(m_pBlackTri, false);

	m_pGreenTri = new Sprite();
	m_pGreenTri->Create(PathMgr->line_right);
	m_pGreenTri->setPosition(D3DXVECTOR2(BOX_DISTENCE + DISTENCE + BTN_WIDTH - 30, BTN_TOP_DISTENCE - 6));
	pushScene(m_pGreenTri, false);

}

ToolBar::~ToolBar(){
}

void ToolBar::ToolBoxClear(){
	for (int i = 0; i < 8; ++i){
		m_pSquarBTN[i]->AddUsualButtonImage(PathMgr->toolBox);
	}
}

void ToolBar::update(float eTime){
	ISceneNode::update(eTime);
	m_pline->update(eTime);

	for (int i = 0; i < 7; ++i){
		m_pCircleBTN[i]->update(eTime);
	}
	for (int i = 0; i < 8; ++i){
		m_pSquarBTN[i]->update(eTime);
	}
	

	if (m_pCircleBTN[0]->OnMouseClicked()){
		m_pCircleBTN[PasteBtn]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[0]->AddUsualButtonImage(PathMgr->toolCir_g);
		PasteBtn = 0;
		ToolBoxClear();
	}
	else if (m_pCircleBTN[1]->OnMouseClicked()){
		m_pCircleBTN[PasteBtn]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[1]->AddUsualButtonImage(PathMgr->toolCir_g);
		PasteBtn = 1;
		ToolBoxClear();
	}
	else if (m_pCircleBTN[2]->OnMouseClicked()){
		m_pCircleBTN[PasteBtn]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[2]->AddUsualButtonImage(PathMgr->toolCir_g);
		PasteBtn = 2;
		ToolBoxClear();
	}
	else if (m_pCircleBTN[3]->OnMouseClicked()){
		m_pCircleBTN[PasteBtn]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[3]->AddUsualButtonImage(PathMgr->toolCir_g);
		PasteBtn = 3;
		ToolBoxClear();
	}
	else if (m_pCircleBTN[4]->OnMouseClicked()){
		m_pCircleBTN[PasteBtn]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[4]->AddUsualButtonImage(PathMgr->toolCir_g);
		PasteBtn = 4;
		ToolBoxClear();
	}
	else if (m_pCircleBTN[5]->OnMouseClicked()){
		m_pCircleBTN[PasteBtn]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[5]->AddUsualButtonImage(PathMgr->toolCir_g);
		PasteBtn = 5;
		ToolBoxClear();
	}
	else if (m_pCircleBTN[6]->OnMouseClicked()){
		m_pCircleBTN[PasteBtn]->AddUsualButtonImage(PathMgr->toolCir);
		m_pCircleBTN[6]->AddUsualButtonImage(PathMgr->toolCir_g);
		PasteBtn = 6;
		ToolBoxClear();
	}




	if (m_pSquarBTN[0]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[0]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 0;
	}
	else if (m_pSquarBTN[1]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[1]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 1;
	}
	else if (m_pSquarBTN[2]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[2]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 2;
	}
	else if (m_pSquarBTN[3]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[3]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 3;
	}
	else if (m_pSquarBTN[4]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[4]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 4;
	}
	else if (m_pSquarBTN[5]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[5]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 5;
	}
	else if (m_pSquarBTN[6]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[6]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 6;
	}
	else if (m_pSquarBTN[7]->OnMouseClicked()){
		m_pSquarBTN[SQ_paste]->AddUsualButtonImage(PathMgr->toolBox);
		m_pSquarBTN[7]->AddUsualButtonImage(PathMgr->toolBox_g);
		SQ_paste = 7;
	}



}

void ToolBar::render(){
	ISceneNode::render();
	for (int i = 0; i < 7; ++i){
		m_pCircleBTN[i]->render();
	}
	for (int i = 0; i < 8; ++i){
		m_pSquarBTN[i]->render();
	}
	m_pline->render();
}
