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
	printf("[게임이 시작되었습니다.]\n");
	printf("당신의 이름을 입력해주세요: ");
	std::string strInput;
	getline(std::cin, strInput);
	m_PC->SetName(strInput);
	printf("%s님이군요. 알겠습니다.\n", strInput.c_str());


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
	printf("[게임이 끝났습니다.]\n");
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
		printf("현재 체력은 %d입니다.\n", m_PC->HP());
		printf("현재 경험치는 %d입니다.\n", m_PC->Exp());
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

			// 이름 설정       
			sprintf_s(buf, "Gulbi %d", gulbiCount);
			pMapInfo->pGulbi->SetName(buf);

			--gulbiCount;
		}
	}

	printf_s("<< 냉동창고에 굴비가 생성되었습니다. >>\n");
}

void CGameManager::CheckMap() {
	Position pos = m_PC->GetPosition();
	MapInfo* pMapInfo = m_Map.GetMapInfo(pos.x, pos.y);
	if(!pMapInfo)
		return;

	if(pMapInfo->pGulbi) {
		m_GameState = BATTLE;
		StartBattle(pMapInfo->pGulbi);
	}
}

void CGameManager::StartBattle( CGulbi* pGulbi ) {
	printf_s("<<<< 고객이 왔습니다. 굴비 손질을 시작합니다. >>>\n");

	while (m_PC->IsAlive() && pGulbi->IsAlive()) {
		printf_s("< 굴비를 손질합니다. >\n");                
		AttackResult result = (AttackResult)(rand() % ATTACK_COUNT);
		int damage = m_PC->Power() + (m_PC->Power() % POWER_OFFSET * 2) - POWER_OFFSET;
		pGulbi->HitCheck(result, damage);

		if(!m_PC->IsAlive()) {
			printf_s(" 과로로 인해 기절해버리고 말았습니다. \n");
			break;
		}

		// 몬스터 턴
		printf_s("< 굴비(%s)가시에 손을 찔리고 말았습니다. >\n", pGulbi->GetName().c_str());
		result = (AttackResult)(rand() % ATTACK_COUNT);
		damage = pGulbi->Power() + (m_PC->Power() % POWER_OFFSET * 2) - POWER_OFFSET;
		m_PC->HitCheck(result, damage);                

		if(!pGulbi->IsAlive()) {
			printf_s("굴비(%s) 손질을 완료했습니다!!\n", pGulbi->GetName().c_str());
			printf_s("경험치가 %d 상승했습니다.\n", pGulbi->Exp());
			m_PC->Exp(pGulbi->Exp());
			break;
		}

		Sleep(500);
	}

	printf_s("<<<<< 손질한 굴비를 고객에게 전달해주었습니다. >>>>>>\n");
	m_GameState = NORMAL;
}
