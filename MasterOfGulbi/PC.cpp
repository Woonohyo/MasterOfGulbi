#include "stdafx.h"
#include "PC.h"


CPC::CPC(void)
{
	m_Power = 50;
	m_Name = "�̿�ȿ";
	m_Exp = 0;
}


CPC::~CPC(void)
{
}

bool CPC::isSubway() {
	if(m_mapState == SUBWAY)
	return true;

}
