#pragma once

#include "Gulbi.h"
#include "NPC.h"

#define MAP_SIZE 10

struct MapInfo {
	CGulbi * pGulbi;
	CNPC * pNPC;
};

class CGameMap {
public:
	CGameMap(void);
	~CGameMap(void);
	MapInfo * GetMapInfo(int x, int y);

protected:
	MapInfo m_Mapinfo[MAP_SIZE][MAP_SIZE];
};

