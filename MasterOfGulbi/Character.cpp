#include "stdafx.h"
#include "Character.h"
#include "GameMap.h"

CCharacter::CCharacter(void):m_HP(100) {
	m_position.x = m_position.y = 0;
}


CCharacter::~CCharacter(void) {
}

Position CCharacter::Move(DIRECTION dir) {
	switch (dir) {
	case DIR_UP:
		m_position.y = __max(m_position.y - 1, 0);
		break;
	case DIR_DOWN:
		m_position.y = __min(m_position.y + 1, MAP_SIZE);
		break;
	case DIR_LEFT:
		m_position.x = __max(m_position.x - 1, 0);
		break;
	case DIR_RIGHT:
		m_position.x = __min(m_position.x + 1, MAP_SIZE);
		break;
	default:
		break;
	}

	return m_position;
}

void CCharacter::SetPosition(int x, int y) {
	Position pos;
	pos.x = x;
	pos.y = y;
	SetPosition(pos);
}

void CCharacter::PrintPosition() {
	printf_s("[Current Position: %d, %d]\n", m_position.x, m_position.y);
}

void CCharacter::HitCheck(AttackResult result, int damage) {
	switch (result) {
	case ATTACK_HIT:
		printf_s("-- %s는 굴비 손질을 통해 %d만큼의 체력을 소모했다.\n\n", GetName().c_str(), damage);
		m_HP -= damage;
		break;
	case ATTACK_MISS:  
		printf_s("-- %s는 무사히 굴비 손질을 하였다.\n\n", GetName().c_str());
		break;
	case ATTACK_GUARD:
		printf_s("-- %s는 숙련된 굴비 손질을 통해 평소의 절반인 %d만큼의 체력을 소모했습니다.\n\n", GetName().c_str(), damage / 2);
		m_HP -= damage / 2;
		break;        
	default:
		break;
	}
}