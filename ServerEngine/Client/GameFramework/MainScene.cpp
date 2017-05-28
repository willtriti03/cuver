#include"MainScene.h"
#include <conio.h>
#include "Wheel.h"
MainScene::MainScene(){

}

MainScene::~MainScene(){

}

void MainScene::update(float eTime){
	printf("%d\n", WHEEL->valueWheel());

}

void MainScene::render(){

}
