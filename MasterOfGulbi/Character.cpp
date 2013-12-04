#include "stdafx.h"
#include "Character.h"
#include "GameMap.h"

CCharacter::CCharacter(void):m_HP(100) {
	m_position.x = m_position.y = 0;
}


CCharacter::~CCharacter(void) {
}

Position CCharacter::Move(DIRECTION dir) {

	// agebreak : ì´ë™ì‹œì— 0 ~ 10ê¹Œì§€ ê°€ëŠ” ë²„ê·¸ê°€ ìˆìŠµë‹ˆë‹¤. (0 ~ 9ê¹Œì§€ ê°€ì•¼ë¨)
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
		printf_s("[³Ãµ¿Ã¢°í ³» ÇöÀç À§Ä¡: %d, %d]\n", m_position.x, m_position.y);
	else
		printHere();
}

void CCharacter::HitCheck(AttackResult result, int damage) {
	switch (result) {
	case ATTACK_HIT:
<<<<<<< HEAD
		printf_s("-- %sëŠ” êµ´ë¹„ ì†ì§ˆì„ í†µí•´ %dë§Œí¼ì˜ ì²´ë ¥ì„ ì†Œëª¨í–ˆë‹¤.\n\n", GetName().c_str(), damage);
=======
		printf_s("-- %s´Â ±¼ºñ ¼ÕÁúÀ» ÇÏ¿© %d¸¸Å­ÀÇ Ã¼·ÂÀ» ¼Ò¸ğÇß´Ù.\n\n", GetName().c_str(), damage);
>>>>>>> ë§µ ê°„ ì´ë™ êµ¬í˜„
		m_HP -= damage;
		break;
	case ATTACK_MISS:  
		printf_s("-- %sëŠ” ë¬´ì‚¬íˆ êµ´ë¹„ ì†ì§ˆì„ í•˜ì˜€ë‹¤.\n\n", GetName().c_str());
		break;
	case ATTACK_GUARD:
		printf_s("-- %sëŠ” ìˆ™ë ¨ëœ êµ´ë¹„ ì†ì§ˆì„ í†µí•´ í‰ì†Œì˜ ì ˆë°˜ì¸ %dë§Œí¼ì˜ ì²´ë ¥ì„ ì†Œëª¨í–ˆìŠµë‹ˆë‹¤.\n\n", GetName().c_str(), damage / 2);
		m_HP -= damage / 2;
		break;        
	default:
		break;
	}
}

void CCharacter::printHere() {
	switch(m_mapState) {
	case HOME:
		printf_s("Áö±İÀº Æí¾ÈÇÑ Áı¿¡ ÀÖ½À´Ï´Ù.\n");
		break;
	case STORAGE:
		printf_s("³Ãµ¿Ã¢°í¿¡ µé¾î¿Ô½À´Ï´Ù. Â÷°¡¿î ¹Ù¶÷¿¡ ¸öÀÌ ¶³¸³´Ï´Ù.\n");
		printf_s("Áö±İºÎÅÍ ±¼ºñ¸¦ Ã£±â À§ÇÑ ¸Ê ÀÌµ¿ÀÌ °¡´ÉÇØÁı´Ï´Ù.\n");
		break;
	case DEPARTMENT:
		printf_s("¹éÈ­Á¡À¸·Î µé¾î¿Ô½À´Ï´Ù.\n");
		break;
	case SUBWAY:
		printf_s("ÁöÇÏÃ¶¿¡ Å¾½ÂÇß½À´Ï´Ù.\n");
		break;
	default:
		break;
	}
}