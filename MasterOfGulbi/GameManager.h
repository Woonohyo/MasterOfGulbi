#pragma once
#include "GameMap.h"
#include "PC.h"

enum GameState {
	NORMAL,
	BATTLE
};

enum BattleResult {
	BATTLE_WIN,
	BATTLE_LOSE
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
	BattleResult StartBattle(CGulbi * pGulbi);
	CGameMap m_Map;
	CPC * m_PC;
	GameState m_GameState;
};

