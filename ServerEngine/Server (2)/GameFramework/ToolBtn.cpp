
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
	if (Image[0]) popScene(Image[0], true);	//���� ��ư�� �̹����� ����
	Image[0] = new Sprite();				//�ٽ� ���� ��������Ʈ �Ҵ�
	Image[0]->Create(path);					//�̹��� ����
	pushScene(Image[0], false);
	Image[1] = Image[0];
}
void ToolBtn::AddOnButtonImage(std::string path) {
	if (Image[1]) popScene(Image[1], true);	//���� ��ư�� �̹����� ����
	Image[1] = new Sprite();				//�ٽ� ���� ��������Ʈ �Ҵ�
	Image[1]->Create(path);					//�̹��� ����
	pushScene(Image[1], false);
}
void ToolBtn::FloatImageSet(std::string path) {
	if (m_pFloatImage) popScene(m_pFloatImage, true);	//���� ��ư�� �̹����� ����
	m_pFloatImage = new Sprite();				//�ٽ� ���� ��������Ʈ �Ҵ�
	m_pFloatImage->Create(path);					//�̹��� ����
	//m_pFloatImage->setPosition(D3DXVECTOR2((getPosition().x - m_pFloatImage->GetRect().right) / 2, (getPosition().y - Image[0]->GetRect().bottom) / 2));
	pushScene(m_pFloatImage, false);
}
void ToolBtn::update(float eTime) {
	ISceneNode::update(eTime);			//��ư�� �浹������ ������Ʈ����
	static float currentTime = 0.f;
	if (OnMouseEnter()) {			//���콺�� ��ư���� �ö�Դٸ�
		btn_state = 1;				//��ư�� ���¸� 1 : (���콺�� �ö��) ���·� ����
	}
	else {							//�ƴ϶��
		btn_state = 0;				//��ư�� ���¸� 0 : (����) ���·� ����
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
	//���� ��ư���¿� �ش��ϴ� �̹����� ��������
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