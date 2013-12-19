#pragma once
#include "Character.h"
class CPC: public CCharacter
{
public:
	CPC(void);
	~CPC(void);
	void TakeSleep( int hourSleep );
};

