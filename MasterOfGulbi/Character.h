#pragma once

struct Position {
	int x;
	int y;
};


enum DIRECTION {
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

enum AttackResult {
	ATTACK_HIT,
	ATTACK_MISS,
	ATTACK_GUARD,
	ATTACK_COUNT
};

class CCharacter
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);

	Position GetPosition() {return m_position;}
	Position Move(DIRECTION dir);

	void SetPosition(Position pos) {m_position = pos;}
	void SetPosition(int x, int y);
	void PrintPosition();

	void SetName(std::string name) {m_Name = name;}
	std::string GetName() {return m_Name;}

	int HP() const { return m_HP; }
	void HP(int val) { m_HP = val; }
	int Power() const { return m_Power; }
	void Power(int val) { m_Power = val; }
	int Exp() const { return m_Exp; }
	void GetExp(int val) { m_Exp += val; }

	bool IsAlive() { return m_HP > 0; }
	void HitCheck(AttackResult result, int damage);

	void goHome() {m_mapState = HOME;}
	void goDepartment() {m_mapState = DEPARTMENT;}
	void goSubway() {m_mapState = SUBWAY;}
	void goStorage() {m_mapState = STORAGE;}\
	void printHere();
	bool isSubway() {if(m_mapState==SUBWAY) return true;}
	bool isStorage() {if(m_mapState==STORAGE) return true;}
	bool isHome() {if(m_mapState==HOME) return true;}
	bool isDepartment() {if(m_mapState==DEPARTMENT) return true;}


protected:
	Position m_position;
	MapState m_mapState;
	std::string m_Name;
	int m_HP;
	int m_Power;
	int m_Exp;
};

