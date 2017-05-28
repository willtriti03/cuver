#include "EditText.h"

EditText::EditText(int x,int y){
	m_pInput = new CFont(_MAX_PATH,y);
	m_pInput->setString("");
	pushScene(m_pInput,false);
	this->x = x;
	this->y = y;
}
EditText::~EditText(){

}

bool EditText::OnMouseClicked() {
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 2) {
		return true;
	}

	return false;
}

bool EditText::OnMouseEnter() {
	RECT tmp;
	GetCursorPos(&currentMousePoint);
	GetWindowRect(GameApp->GetHWND(), &tmp);
	ScreenToClient(GameApp->GetHWND(), &currentMousePoint);
	int x = currentMousePoint.x;
	int y = currentMousePoint.y;

	if (x > collision.left && x < collision.right &&
		y > collision.top && y < collision.bottom){
		return true;
	}
	return false;
}
void EditText::updateCollision(int x,int y) {
	collision.left = m_pInput->getPosition().x;
	collision.top = m_pInput->getPosition().y;
	collision.right = m_pInput->getPosition().x + x;
	collision.bottom = m_pInput->getPosition().y + y;
}
void EditText::InputStart(){}

void EditText::update(float eTime){
	ISceneNode::update(eTime);
	m_pInput->update(eTime);
	updateCollision(x,y);				//��ư�� �浹������ ������Ʈ����
	static float currentTime = 0.f;
	if (OnMouseEnter()) {			//���콺�� ��ư���� �ö�Դٸ�
		btn_state = 1;				//��ư�� ���¸� 1 : (���콺�� �ö��) ���·� ����
	}
	else {							//�ƴ϶��
		btn_state = 0;				//��ư�� ���¸� 0 : (����) ���·� ����
	}
	if (OnMouseClicked()){
		EditStart = true;
	}
	if (EditStart){
		press[1] = press[0];
		press[0] = InputMgr->keyPress();
		if (press[0] != 256){
			if ('A' <= press[0] && 'Z' >= press[0]){
				if (press[1]==16)
				str += (char)InputMgr->keyPress();
				else {
					str += 'a'+((char)InputMgr->keyPress())-'A';
				}
				m_pInput->setString(str);
			}
		}
	}
}

void EditText::render(){
	ISceneNode::render();
	m_pInput->render();
}