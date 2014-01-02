// Master of Gulbi.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GameManager.h"

int _tmain(int argc, _TCHAR* argv[]) {
	CGameManager::GetInstance();

	CGameManager::GetInstance()->Init();
	CGameManager::GetInstance()->Run();
	CGameManager::GetInstance()->Release();

	getchar();
	return 0;
}

