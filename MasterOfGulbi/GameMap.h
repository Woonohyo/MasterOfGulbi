#pragma once

#include "Gulbi.h"
#include "NPC.h"

#define MAP_SIZE 10

enum MapState {
	HOME,
	SUBWAY,
	DEPART,
	STORAGE
};

struct MapInfo {
	CGulbi * pGulbi;
	CNPC * pNPC;
	MapState m_MapState;
	//∏  ≈∏¿‘ √ﬂ∞°
};

class CGameMap {
public:
	CGameMap(void);
	~CGameMap(void);
	MapInfo * GetMapInfo(int x, int y);

protected:
	MapInfo m_Mapinfo[MAP_SIZE][MAP_SIZE];
};

