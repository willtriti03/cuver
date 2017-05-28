#include "Block.h"
#include "Application.h"
#include "InputManager.h"
#include "BroadCast.h"


Block::Block(){

	moveLock = false;
	clickBool = false;
	m_pBase = nullptr;
	m_pMotherBlock = m_pInput = nullptr;

}

Block::~Block(){}

string Block::ReturnCode(){
	return inform;
}

bool Block::OnMouseEnter() {

	GetCursorPos(&currentMousePoint);
	ScreenToClient(GameApp->GetHWND(), &currentMousePoint);

	x = currentMousePoint.x;
	y = currentMousePoint.y;

	if (x > collision.left && x < collision.right &&
		y > collision.top && y < collision.bottom){
		return true;
	}
	return false;

}
bool Block::OnMouseClicked() {

	if (!moveLock&&!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 2) {
		return true;
	}
	return false;

}
bool Block::OnReleased(){

	if (!moveLock&&!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 3) {
		return true;
	}
	return false;

}
bool Block::InClick(){

	if (!moveLock&&!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 4) {
		return true;
	}
	return false;

}
bool Block::CrashCheck(Block *m_pFlyTile){

	tmp_collision = m_pFlyTile->collision;

	if (tmp_collision.left > collision.left && tmp_collision.left < collision.right &&
		tmp_collision.top > collision.top && tmp_collision.top < collision.bottom){
		return true;
	}

	else if (tmp_collision.left > collision.left && tmp_collision.left < collision.right &&
		tmp_collision.bottom > collision.top && tmp_collision.bottom < collision.bottom){
		return true;
	}

	else if (tmp_collision.right > collision.left && tmp_collision.right < collision.right &&
		tmp_collision.top > collision.top && tmp_collision.top < collision.bottom){
		return true;
	}

	else if (tmp_collision.right > collision.left && tmp_collision.right < collision.right &&
		tmp_collision.bottom > collision.top && tmp_collision.bottom < collision.bottom){
		return true;
	}
	return false;

}

void Block::InputCode(string code){
	inform = code;
}
void Block::AddBlockImage(std::string path){

	if (m_pBase)
		popScene(m_pBase, true);

	m_pBase = new Sprite();
	m_pBase->Create(path);
	pushScene(m_pBase, false);

	m_pBase->setPosition(D3DXVECTOR2(0, 0));

	updateCollision();				//버튼의 충돌영역을 업데이트해줌

}
void Block::InputAdd(Block *m_pInputItem){
	m_pInput = new Block();
	m_pInput = m_pInputItem;
	//m_pInput->MoveLock();
	sv_point_x = m_pBase->getPosition().x;
	sv_point_y = m_pBase->getPosition().y;

	m_pInput->setPos(sv_point_x + 40, sv_point_y + 40);
	BroadMgr->blockUp = false;

}
void Block::setPos(int x, int y){

	m_pBase->setPosition(D3DXVECTOR2(x, y));
	updateCollision();

}
void Block::updateCollision() {

	collision.left = m_pBase->getPosition().x;
	collision.top = m_pBase->getPosition().y;
	collision.right = m_pBase->getPosition().x + m_pBase->GetRect().right;
	collision.bottom = m_pBase->getPosition().y + m_pBase->GetRect().bottom;
	//printf("%d %d %d %d %d %d\n", collision.left, collision.right, collision.top, collision.bottom,collision.right-collision.left ,collision.top-collision.bottom);
}
void Block::MoveLock(){
	moveLock = !moveLock;
}
void Block::GiveIdentity(int kind, int num){
	identity[0] = kind;
	identity[1] = num;
}
void Block::YourMotherBlock(Block *m_pMother){
	m_pMotherBlock = m_pMother;
	//printf("%d %d %d\n", this, m_pMotherBlock, m_pInput);
}
void Block::YourBabyBlock(Block *m_pBa){
	m_pInput = m_pBa;
	//printf("%d %d %d\n", this, m_pMotherBlock, m_pInput);
}
void Block::DeleteBlock(){
	if (m_pInput != nullptr)
		m_pInput->YourMotherBlock(nullptr);
	if (m_pMotherBlock != nullptr)
		m_pMotherBlock->YourBabyBlock(nullptr);
	//printf("%d", this);
	BroadMgr->PleasePop(this);

}
void Block::update(float eTime){
	ISceneNode::update(eTime);
	m_pBase->update(eTime);

	updateCollision();

	GetCursorPos(&currentMousePoint);
	ScreenToClient(GameApp->GetHWND(), &currentMousePoint);

	x = currentMousePoint.x;
	y = currentMousePoint.y;

	if (OnMouseEnter()) {			//마우스가 버튼위에 올라왔다면
		btn_state = 1;				//버튼의 상태를 1 : (마우스가 올라옴) 상태로 지정
	}
	else {							//아니라면
		btn_state = 0;				//버튼의 상태를 0 : (보통) 상태로 지정
	}
	if (BroadMgr->mouseMode == 2 && InClick()){
		DeleteBlock();
	}
	if (BroadMgr->mouseMode == 1 && InClick()){
		sv_x = x;
		sv_y = y;

		sv_point_x = m_pBase->getPosition().x;
		sv_point_y = m_pBase->getPosition().y;

		clickBool = true;

		BroadMgr->blockUp = true;
		BroadMgr->m_pSelectedBlock = this;
	}



	if (clickBool&&InputMgr->keyState(VK_LBUTTON) == 2){
		clickBool = false;
		BroadMgr->blockUp = false;
	}



	if (clickBool){
		m_pBase->setPosition(D3DXVECTOR2(sv_point_x + (x - sv_x), sv_point_y + (y - sv_y)));

		sv_x = x;
		sv_y = y;

		sv_point_x = m_pBase->getPosition().x;
		sv_point_y = m_pBase->getPosition().y;

		//m_pInput->setPosition(D3DXVECTOR2(sv_point_x + 30, sv_point_y + 30));
	}


	if (m_pInput){
		sv_point_x = m_pBase->getPosition().x;
		sv_point_y = m_pBase->getPosition().y;

		m_pInput->setPos(sv_point_x + 40, sv_point_y + 40);
	}


	if (BroadMgr->blockUp){

		if (BroadMgr->m_pSelectedBlock != m_pInput&&CrashCheck(BroadMgr->m_pSelectedBlock) && BroadMgr->m_pSelectedBlock != m_pMotherBlock&& m_pInput == nullptr){
			InputAdd(BroadMgr->m_pSelectedBlock);
			BroadMgr->m_pSelectedBlock->YourMotherBlock(this);


		}
		else if (BroadMgr->m_pSelectedBlock == m_pInput){
			m_pInput->YourMotherBlock(nullptr);
			m_pInput = nullptr;
			BroadMgr->blockUp = false;

		}

	}
	//printf("%d %d\n", sv_point_x,sv_point_y);
	if (InputMgr->keyState('A') == 2)
		printf("%d %d %d\n", this, m_pMotherBlock, m_pInput);
}
void Block::render(){
	ISceneNode::render();
	m_pBase->render();
	//m_pInput->render();
}


