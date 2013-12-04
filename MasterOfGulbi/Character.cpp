﻿#include "stdafx.h"
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
		printf_s("[�õ�â�� �� ���� ��ġ: %d, %d]\n", m_position.x, m_position.y);
	else
		printHere();
}

void CCharacter::HitCheck(AttackResult result, int damage) {
	switch (result) {
	case ATTACK_HIT:
<<<<<<< HEAD
		printf_s("-- %s는 굴비 손질을 통해 %d만큼의 체력을 소모했다.\n\n", GetName().c_str(), damage);
=======
		printf_s("-- %s�� ���� ������ �Ͽ� %d��ŭ�� ü���� �Ҹ��ߴ�.\n\n", GetName().c_str(), damage);
>>>>>>> 맵 간 이동 구현
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

void CCharacter::printHere() {
	switch(m_mapState) {
	case HOME:
		printf_s("������ ����� ���� �ֽ��ϴ�.\n");
		break;
	case STORAGE:
		printf_s("�õ�â�� ���Խ��ϴ�. ������ �ٶ��� ���� �����ϴ�.\n");
		printf_s("���ݺ��� ���� ã�� ���� �� �̵��� ���������ϴ�.\n");
		break;
	case DEPARTMENT:
		printf_s("��ȭ������ ���Խ��ϴ�.\n");
		break;
	case SUBWAY:
		printf_s("����ö�� ž���߽��ϴ�.\n");
		break;
	default:
		break;
	}
}