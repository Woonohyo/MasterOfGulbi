// Master of Gulbi.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

