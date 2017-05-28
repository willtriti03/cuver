#include "SplashScene.h"
#include "MainScene.h"
#define TIME 150
#include "PathMgr.h"
#include "Edit.h"
SplashScene::SplashScene()
{
	time = 0;
	m_pSplash = new Sprite();
	m_pSplash->Create(PathMgr->splash);
	m_pSplash->setPosition(D3DXVECTOR2(0,0));
	pushScene(m_pSplash, false);

}


SplashScene::~SplashScene()
{
}

void SplashScene::update(float eTime){
	m_pSplash->update(eTime);
	if (time++ == TIME){
		SceneMgr->changeScene(new Edit);
	}
}

void SplashScene::render(){
	m_pSplash->render();
}
