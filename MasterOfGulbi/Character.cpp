#include "stdafx.h"
#include "Character.h"
#include "GameMap.h"

CCharacter::CCharacter(void):m_HP(100) {
	m_position.x = m_position.y = 0;
}


CCharacter::~CCharacter(void) {
}

Position CCharacter::Move(DIRECTION dir) {

	// agebreak : 이동시에 0 ~ 10까지 가는 버그가 있습니다. (0 ~ 9까지 가야됨)
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
	if(m_mapState == STORAGE)
		printf_s("[현재 창고 내에서의 위치: %d, %d]\n", m_position.x, m_position.y);
	else
		PrintHere();
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

void CCharacter::PrintHere() {
	switch(m_mapState) {
	case HOME:
		printf_s("편안한 집입니다. [잠자기]를 통해 체력을 회복할 수 있습니다.\n");
		printf_s("[잠자기]를 통해 시간당 체력을 10 회복할 수 있습니다.\n")
		break;
	case STORAGE:
		printf_s("굴비를 보관 중인 냉동창고입니다. 이 곳에서는 이동할 때마다 체력이 감소합니다.\n");
		printf_s("w, a, s, d의 입력을 통해 이동할 수 있습니다.\n");
		break;
	case DEPARTMENT:
		printf_s("손님을 맞이할 수 있는 백화점입니다. [호객]을 통해 손님을 맞이할 수 있습니다.\n");
		printf_s("[호객]은 30분의 시간을 소모합니다.\n");
		break;
	case SUBWAY:
		printf_s("백화점과 집 사이를 오갈 수 있는 지하철입니다.\n[탑승]을 통해 반대편으로 갈 수 있습니다. \n");
		printf_s("백화점과 집은 편도 1시간이 걸립니다.");
		break;
	default:
		break;
	}
}

void CCharacter::recoverHp(int hours) {
	m_HP = m_HP + hours * 10;
}


