#include "stdafx.h"
#include "GameManager.h"
#include <windows.h>
#include <time.h>

#define POWER_OFFSET 3


CGameManager::CGameManager(void):
	m_GameState(NORMAL) {
		m_PC = new CPC();
}


CGameManager::~CGameManager(void)
{
	delete m_PC;
}

void CGameManager::Init() {
	printf("[������ ���۵Ǿ����ϴ�.]\n");
	printf("201x�� 9��. NEXT���� �ٻ� 2�бⰡ ������ 3�ְ��� ���������� ���۵Ǿ���\n.");
	printf("����� �̸��� �Է����ּ���: ");
	std::string strInput;
	getline(std::cin, strInput);
	m_PC->SetName(strInput);
	printf("%s���̱���. �˰ڽ��ϴ�.\n", strInput.c_str());


	srand((unsigned)time(NULL));
	CreateGulbies();

	m_PC -> SetPosition(0, 0);
	m_PC -> PrintPosition();
}

void CGameManager::Run() {
	while(InputProc()) {
		CheckMap();
	}
}

void CGameManager::Release() {
	printf("[������ �������ϴ�.]\n");
}

bool CGameManager::InputProc() {
	std::string strInput;
	getline(std::cin, strInput);

	printf("Input : %s\n", strInput.c_str());        

	if(strInput == "W" || strInput == "w") {
		m_PC->Move(DIR_UP);
	}
	else if(strInput == "A" || strInput == "a") {
		m_PC->Move(DIR_LEFT);
	}
	else if(strInput == "S" || strInput == "s") {
		m_PC->Move(DIR_DOWN);
	}
	else if(strInput == "D" || strInput == "d") {
		m_PC->Move(DIR_RIGHT);
	}

	if(strInput == "c" || strInput == "C") {
		printf("���� ü���� %d�Դϴ�.\n", m_PC->HP());
		printf("���� ����ġ�� %d�Դϴ�.\n", m_PC->Exp());
	}

	m_PC->PrintPosition();

	if(strInput == "Q" || strInput == "q")
		return false;

	return true;
}

void CGameManager::CreateGulbies() {
	char buf[32] = {0,};

	int gulbiCount = (MAP_SIZE * MAP_SIZE) / 4;
	while (gulbiCount > 0) {
		int x = rand() % MAP_SIZE;
		int y = rand() % MAP_SIZE;

		MapInfo* pMapInfo = m_Map.GetMapInfo(x, y);

		if(pMapInfo->pGulbi == nullptr) {
			pMapInfo->pGulbi = new CGulbi();                        

			// �̸� ����       
			sprintf_s(buf, "Gulbi %d", gulbiCount);
			pMapInfo->pGulbi->SetName(buf);

			--gulbiCount;
		}
	}

	printf_s("<< �õ�â�� ���� �����Ǿ����ϴ�. >>\n");
}

void CGameManager::CheckMap() {
	Position pos = m_PC->GetPosition();
	MapInfo* pMapInfo = m_Map.GetMapInfo(pos.x, pos.y);
	if(!pMapInfo)
		return;

	if(pMapInfo->pGulbi && pMapInfo->pGulbi->IsAlive()) {  //�̸� ������ �ǹǷ� Null Ptr ���� ������ �߻����� �ʴ´�.
		m_GameState = BATTLE;
		BattleResult result = StartBattle(pMapInfo->pGulbi);
		if (result == BATTLE_WIN) {
			delete pMapInfo->pGulbi;
			pMapInfo->pGulbi = nullptr;
		}
	}
}

//Map�� �ѱ�ų� ���� �����͸� ����ϴ� ���� �ټ� ������� ���ϴ�.
BattleResult CGameManager::StartBattle( CGulbi* pGulbi) {
	BattleResult battleResult = (BattleResult)NULL;
	if (!m_PC->IsAlive()) {
		printf_s(" ���� ���¿����� ���� ������ �� �����ϴ�.\n ");
		m_GameState = NORMAL;
	}

	while (m_PC->IsAlive() && pGulbi->IsAlive()) {
		printf_s("< ���� �����մϴ�. >\n");                
		AttackResult result = (AttackResult)(rand() % ATTACK_COUNT);

		// POWER_OFFSET��ŭ �������� +- �Ѵ�. ���� ���̴� ���!
		int damage = m_PC->Power() + (rand() % POWER_OFFSET * 2) - POWER_OFFSET;
		pGulbi->HitCheck(result, damage);

		//�÷��̾� �Ͽ� �÷��̾ ��� �ִ� �� üũ�ϴ� �� �ǹ̰� ����.
		// �÷��̾� �Ͽ��� ������ ���� ���θ� �Ǵ��ؾ� �Ѵ�.
		if(!pGulbi->IsAlive()) {
			printf_s("����(%s) ������ �Ϸ��߽��ϴ�!!\n", pGulbi->GetName().c_str());
			printf_s("����ġ�� %d ����߽��ϴ�.\n", pGulbi->Exp());
			m_PC->GetExp(pGulbi->Exp());
			battleResult = BATTLE_WIN;
			break;
		}

		// ���� ��
		printf_s("< ����(%s)���ÿ� ���� �񸮰� ���ҽ��ϴ�. >\n", pGulbi->GetName().c_str());
		result = (AttackResult)(rand() % ATTACK_COUNT);
		damage = pGulbi->Power() + (rand() % POWER_OFFSET * 2) - POWER_OFFSET;
		m_PC->HitCheck(result, damage);                

		if(!m_PC->IsAlive()) {
			printf_s(" ���η� ���� ������ ������ ���ҽ��ϴ�. \n");
			battleResult = BATTLE_LOSE;
		}
		

		Sleep(250);
	}

	printf_s("<<<<< ������ ���� ������ �������־����ϴ�. >>>>>>\n");
	m_GameState = NORMAL;
	return battleResult;
}
