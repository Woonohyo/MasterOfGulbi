#pragma once
#include "GameMap.h"
#include "PC.h"

enum GameState {
	NORMAL,
	BATTLE
};

class CGameManager
{
public:
	CGameManager(void);
	~CGameManager(void);

	void Init();
	void Run();
	void Release();

protected:
	bool InputProc();
	void CreateGulbies();
	void CheckMap();
	void StartBattle(CGulbi * pGulbi);
protected:
	CGameMap m_Map;
	CPC * m_PC;
	GameState m_GameState;
};

