
#include "ToolBtn.h"
#include "Application.h"
#include "InputManager.h"

ToolBtn::ToolBtn() {
	/*Image[0] = new Sprite();
	Image[0]->Create("resource/deck_btn.png");
	pushScene(Image[0], false);

	Image[1] = new Sprite();
	Image[1]->Create("resource/clicked.png");
	pushScene(Image[1], false);*/
	Image[0] = Image[1] =m_pFloatImage= nullptr;
	btn_state = 0;
}
ToolBtn::~ToolBtn() {
}
void ToolBtn::AddUsualButtonImage(std::string path) {
	if (Image[0]) popScene(Image[0], true);	//이전 버튼의 이미지는 지움
	Image[0] = new Sprite();				//다시 새로 스프라이트 할당
	Image[0]->Create(path);					//이미지 생성
	pushScene(Image[0], false);
	Image[1] = Image[0];
}
void ToolBtn::AddOnButtonImage(std::string path) {
	if (Image[1]) popScene(Image[1], true);	//이전 버튼의 이미지는 지움
	Image[1] = new Sprite();				//다시 새로 스프라이트 할당
	Image[1]->Create(path);					//이미지 생성
	pushScene(Image[1], false);
}
void ToolBtn::FloatImageSet(std::string path) {
	if (m_pFloatImage) popScene(m_pFloatImage, true);	//이전 버튼의 이미지는 지움
	m_pFloatImage = new Sprite();				//다시 새로 스프라이트 할당
	m_pFloatImage->Create(path);					//이미지 생성
	//m_pFloatImage->setPosition(D3DXVECTOR2((getPosition().x - m_pFloatImage->GetRect().right) / 2, (getPosition().y - Image[0]->GetRect().bottom) / 2));
	pushScene(m_pFloatImage, false);
}
void ToolBtn::update(float eTime) {
	ISceneNode::update(eTime);			//버튼의 충돌영역을 업데이트해줌
	static float currentTime = 0.f;
	if (OnMouseEnter()) {			//마우스가 버튼위에 올라왔다면
		btn_state = 1;				//버튼의 상태를 1 : (마우스가 올라옴) 상태로 지정
	}
	else {							//아니라면
		btn_state = 0;				//버튼의 상태를 0 : (보통) 상태로 지정
	}
	m_pFloatImage->update(eTime);
}
void ToolBtn::render() {
	ISceneNode::render();

	if (OnReleased()){

		Image[1]->render();
		

	}
	else if (InClick()){

	}
	else{
		Image[0]->render();
		
	}
	m_pFloatImage->render();
	//현재 버튼상태에 해당하는 이미지를 렌더링함
}
void ToolBtn::updateCollision() {
	collision.left = getPosition().x;
	collision.top = getPosition().y;
	collision.right = getPosition().x + Image[0]->GetRect().right;
	collision.bottom = getPosition().y + Image[0]->GetRect().bottom;

	//printf("%d %d %d %d\n", collision.left, collision.top, Image[0]->getPosition().x, Image[0]->getPosition().y);
}
bool ToolBtn::OnMouseEnter() {
	RECT tmp;
	updateCollision();
	GetCursorPos(&currentMousePoint);
	ScreenToClient(GameApp->GetHWND(), &currentMousePoint);

	int x = currentMousePoint.x;
	int y = currentMousePoint.y;

	if (x > collision.left && x < collision.right &&
		y > collision.top && y < collision.bottom){
		return true;
	}
	return false;
}
bool ToolBtn::OnMouseClicked() {
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 2) {
		return true;
	}

	return false;
}
bool ToolBtn::OnReleased(){
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 3) {
		return true;
	}

	return false;
}

bool ToolBtn::InClick(){
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 4) {
		return true;
	}

	return false;
}
/*
bool ToolBtn::OnDoubleClicked(){
if (!btn_state) {

return false;
}
else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 4) {

return true;

}
return false;
}*/