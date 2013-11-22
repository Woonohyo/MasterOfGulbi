// Master of Gulbi.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GameManager.h"

int _tmain(int argc, _TCHAR* argv[]) {
	CGameManager gameManager;

	gameManager.Init();
	gameManager.Run();
	gameManager.Release();

	getchar();
	return 0;
}

