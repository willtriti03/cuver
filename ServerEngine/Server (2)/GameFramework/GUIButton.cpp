
#include "GUIButton.h"
#include "Application.h"
#include "InputManager.h"

GUIButton::GUIButton() {
	/*Image[0] = new Sprite();
	Image[0]->Create("resource/deck_btn.png");
	pushScene(Image[0], false);

	Image[1] = new Sprite();
	Image[1]->Create("resource/clicked.png");
	pushScene(Image[1], false);*/
	Image[0] = Image[1] = nullptr;
	btn_state = 0;
}
GUIButton::~GUIButton() {
}
void GUIButton::AddUsualButtonImage(std::string path) {
	if (Image[0]) popScene(Image[0], true);	//���� ��ư�� �̹����� ����
	Image[0] = new Sprite();				//�ٽ� ���� ��������Ʈ �Ҵ�
	Image[0]->Create(path);					//�̹��� ����
	pushScene(Image[0], false);

}
void GUIButton::AddOnButtonImage(std::string path) {
	if (Image[1]) popScene(Image[1], true);	//���� ��ư�� �̹����� ����
	Image[1] = new Sprite();				//�ٽ� ���� ��������Ʈ �Ҵ�
	Image[1]->Create(path);					//�̹��� ����
	pushScene(Image[1], false);
}

void GUIButton::update(float eTime) {
	ISceneNode::update(eTime);			//��ư�� �浹������ ������Ʈ����
	static float currentTime = 0.f;
	if (OnMouseEnter()) {			//���콺�� ��ư���� �ö�Դٸ�
		btn_state = 1;				//��ư�� ���¸� 1 : (���콺�� �ö��) ���·� ����
	}
	else {							//�ƴ϶��
		btn_state = 0;				//��ư�� ���¸� 0 : (����) ���·� ����
	}
}
void GUIButton::render() {
	ISceneNode::render();

	if (OnReleased()){

		Image[1]->render();

	}
	else if (InClick()){
		
	}
	else Image[0]->render();
	//���� ��ư���¿� �ش��ϴ� �̹����� ��������
}
void GUIButton::updateCollision() {
	collision.left =getPosition().x;
	collision.top = getPosition().y;
	collision.right = getPosition().x + Image[0]->GetRect().right;
	collision.bottom = getPosition().y + Image[0]->GetRect().bottom;

	//printf("%d %d %d %d\n", collision.left, collision.top, Image[0]->getPosition().x, Image[0]->getPosition().y);
}
bool GUIButton::OnMouseEnter() {
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
bool GUIButton::OnMouseClicked() {
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 2) {
		return true;
	}

	return false;
}
bool GUIButton::OnReleased(){
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 3) {
		return true;
	}

	return false;
}

bool GUIButton::InClick(){
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 4) {
		return true;
	}

	return false;
}
/*
bool GUIButton::OnDoubleClicked(){
if (!btn_state) {

return false;
}
else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 4) {

return true;

}
return false;
}*/