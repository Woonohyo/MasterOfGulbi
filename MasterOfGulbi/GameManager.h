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

enum GulbiPart {
	HEAD,
	FIN,
	TAIL,
	NUM_OF_PARTS
};

enum DayName {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
	DAYNAME_COUNT
};

class CGameManager
{
public:
	CGameManager(void);
	~CGameManager(void);
	void Init();
	void Run();
	void Release();
	void NumHoursLater(int hours);
	int m_Day;
	int m_Hour;
	std::string m_DayName[DAYNAME_COUNT];
	int m_NumOfWeek;

	static CGameManager* GetInstance();

protected:
	bool InputProc();
	void CreateGulbies();
	void CheckMap();
	void NonMovable();
	BattleResult StartBattle(CGulbi * pGulbi);
	void TypePart();
	CGameMap m_Map;
	CPC * m_PC;
	GameState m_GameState;

	static CGameManager* m_instance;
	
	
};