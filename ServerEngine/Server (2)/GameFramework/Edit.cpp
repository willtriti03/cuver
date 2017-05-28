#include "Edit.h"


Edit::Edit()
{
	Load();
	move = 0;
	m_pMap = new Sprite();
	m_pMap->Create(mapPath);
	m_pMap->setPosition(D3DXVECTOR2(0, 0));
}


Edit::~Edit()
{
}
void Edit::Load(){
	ifstream inFile("Data/setting.txt");
	inFile >> name >> path >> mapPath;


}
void Edit::Save(){
	ofstream outFile;
	outFile.open(path + "mapFan/" + name + ".mdatF");
	outFile.close();
	outFile.open(path + "mapFire/" + name + ".mdatFi");
	outFile.close();
	outFile.open(path + "mapLine/" + name + ".mdatL");
	outFile.close();
	outFile.open(path + "mapNpc/" + name + ".mdatN");
	outFile.close();
	outFile.open(path + "mapPhilla/" + name + ".mdatP");
	outFile.close();
	outFile.open(path + "mapStick/" + name + ".mdatS");
	outFile.close();
	outFile.open(path + "mapTouch/" + name + ".mdatT");
	outFile.close();
	outFile.open(path + "mapWind/" + name + ".mdatW");
	outFile.close();
	outFile.open(path + "mapChar/" + name + ".mdatC");
	outFile.close();

}
void Edit::update(float eTime){
	ISceneNode::update(eTime);
	if (InputMgr->keyState('D')==4){
		move += 4;
	}
	if (InputMgr->keyState('A') == 4){
		move -= 4;
	}
}
void Edit::render(){
	ISceneNode::render();
}

