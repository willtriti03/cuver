#include "Application.h"
#include "Console.h"
#include "SceneManager.h"
#include "SplashScene.h"


#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

Console g_Console;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	GameApp->RegisterWindowSize(1440, 810);
	GameApp->SetAppName(L"SRV");
	GameApp->InitializeApp();
	GameApp->InitDirect3D();

	//SetWindowLong(GameApp->GetHWND(), GWL_STYLE, 0); //remove all window styles, check MSDN for details
	ShowWindow(GameApp->GetHWND(), SW_SHOWDEFAULT);
	UpdateWindow(GameApp->GetHWND());
	//DragAcceptFiles(GameApp->GetHWND(), true);//파일 드래그
	ShowCursor(false);//커서숨김

	//사운드 관련 초기화


	//게임씬
	SceneMgr->changeScene(new SplashScene);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while(msg.message != WM_QUIT) {
		if(PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			GameApp->Render();
		}
	}
	UnregisterClass(GameApp->GetAppName(), GetModuleHandle(NULL));

	
	return 0;
}