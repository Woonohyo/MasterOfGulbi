#include "stdafx.h"
#include "PC.h"


CPC::CPC(void)
{
	m_Power = 50;
	m_Name = "±è¹Ö¹Ö";
	m_Exp = 0;
}


CPC::~CPC(void)
{
}

void CPC::TakeSleep( int hourSleep )
{
	m_recoverHp(hourSleep);
	
}
