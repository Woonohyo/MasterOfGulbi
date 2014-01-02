#include "stdafx.h"
#include "GameManager.h"
#include <windows.h>
#include <time.h>

#define POWER_OFFSET 3

CGameManager* CGameManager::m_instance = nullptr;

CGameManager::CGameManager(void):
	m_GameState(NORMAL) {
		m_PC = new CPC();
		m_Day = 2;
		m_Hour = 8;
		m_NumOfWeek = 0;
		std::string m_DayNameTemp[] = {"월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일"};
		for(int i = 0; i < DAYNAME_COUNT; i++)
			m_DayName[i] = m_DayNameTemp[i];
}


CGameManager::~CGameManager(void)
{
	delete m_PC;
}

void CGameManager::Init() {            
	system("cls");
	printf_s("##     ##    ###     ######  ######## ######## ########      #######  ########     ######   ##     ## ##       ########  ####\n");
	printf_s("###   ###   ## ##   ##    ##    ##    ##       ##     ##    ##     ## ##          ##    ##  ##     ## ##       ##     ##  ## \n");
	printf_s("#### ####  ##   ##  ##          ##    ##       ##     ##    ##     ## ##          ##        ##     ## ##       ##     ##  ## \n");
	printf_s("## ### ## ##     ##  ######     ##    ######   ########     ##     ## ######      ##   #### ##     ## ##       ########   ## \n");
	printf_s("##     ## #########       ##    ##    ##       ##   ##      ##     ## ##          ##    ##  ##     ## ##       ##     ##  ## \n");
	printf_s("##     ## ##     ## ##    ##    ##    ##       ##    ##     ##     ## ##          ##    ##  ##     ## ##       ##     ##  ## \n");
	printf_s("##     ## ##     ##  ######     ##    ######## ##     ##     #######  ##           ######    #######  ######## ########  ####\n\n");
	printf_s("　 ＼　　　　　　　＿＿＿＿＿＿＿＿__／ゝ\n");
	printf_s("　　　＼　　,,ー‐‐丶;:;:;:;:;:;:;:;;:;:;ヽ;:;:;:;:;:;:;:;:;:;:;:ヽ' 　ゝ\n");
	printf_s("　　　　　X/~゜'＼ヾ （●）;:;:;:;:;:;:ヽ;:;:;:;:;:;:;:;:;:;:;:;:;ヽ' ゝ\n");
	printf_s("　　　　　ヽ＼　　 ＼ゝ:;:;:;:;:;:;:;:;:;:;:;|;:;:;::　＿＿;:;:;:;ヽ' ゝ\n");
	printf_s("　　　　　　 | |＼　　 》　　　　;:;:;:丿;:;／　 ,／;:;:;:;;:;＼/\n");
	printf_s("　　　　　　//,,　＼〃ゝ　 　　丿(〆　 _／;i|!|;:;::;:;:;:;:;＼\n");
	printf_s("　　　　　（二二ノゾ　 　 　 ノ　　 ⌒￣;:;:;;::;:;:|!|i:;:;;;:;:;:;:;|\n");
	printf_s("　　　　　　ヽー-ニニーーー'''''´　　　　　　　 ;:;:;:;;:;!|i|:;:;:;:;:;:;|\n");
	printf_s("　　　　　　　　　ヽーーヽ_　　_　　 　　　　　　 ;:;:;::;|!|!:;:;:;:|\n");
	printf_s("　　　　　　´ 　　　　　　　￣＼_　　＜￣,,/ 　 　 ;:;:;i|!:;:;|\n");
	printf_s("　　　　　　　゜ 　　　　　　　　 　｀＼_　＼/　　　 　.:;:;:;|i!|\n");
	printf_s("　　　　　　;　　　　　 　 　'　　　　 　 ｀'ヽ　　　 　　.;:;:/　　　　　　　　゜\n");
	printf_s("　　　　　　　　　、　 　　 　゜　　　　　　　 ｀'ヽ　　　,/　　｀　　　　　　　　´\n");
	printf_s("　　　　　。　 　　　　　　　　　　　　　　_＿＿__ソ:::　,/　　　。\n");
	printf_s("　　　　　　　　　　　　　　　　　　　　　＼:;;::;::;::;　 ,/　;゜　 、\n");
	printf_s("　　　　　　　　　　;´　　　　　　　゜　。　　 ゞ,;:;:;:;:/\n");
	printf_s("당신의 이름은 무엇인가요?\n");
	std::string strInput;
	getline(std::cin, strInput);
	m_PC->SetName(strInput);
	printf_s("내 이름은 %s.\n", m_PC->GetName().c_str());
	printf_s("201x년 9월. NEXT에서 바쁜 2학기가 끝나고 3주간의 가을방학이 시작되었다.\n");
	printf_s("하지만 그와 동시에 나에겐 우편물이 하나 날아왔고..\n");
	printf_s("그건 이전에 미처 갚지 못한 학자금이었다.\n");
	printf_s("인터넷에서 알바 자리를 찾던 나는 백화점 명절 알바를 찾게 되었고, 결국 백화점 내 굴비 코너에서 일하게 되었다.\n");
	printf_s("내게 남은 방학 기간은 20여일.. 이 기간 동안 200만원을 모아야 한다!\n\n");
	getchar();
	system("cls");
	printf_s("지금부터 게임설명을 해드리겠습니다.\n");
	printf_s("본 게임은 9월 2일(월)부터 9월 22일(일)까지 21일간 S백화점의 굴비 코너에서 추석 명절 아르바이트를 해서 돈을 모으는 게임입니다.\n");
	printf_s("도움말을 보려면 '도움'을 입력하시면 됩니다.");

	m_PC -> SetPosition(0, 0);
	m_PC -> PrintPosition();
	m_PC -> GoHome();
}

void CGameManager::Run() {
	while(InputProc()) {
		CheckMap();
	}
}

void CGameManager::Release() {
	printf_s("[게임이 끝났습니다.]\n");
}

bool CGameManager::InputProc() {
	std::string strInput;
	getline(std::cin, strInput);

	printf_s("어떤 행동을 하시겠습니까?: %s\n", strInput.c_str());        
	if(m_PC->IsStorage()) {
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
	}

	if(strInput == "여기") {
		m_PC->PrintHere();
	}

	if(strInput == "정보") {
		printf_s("현재 체력은 %d입니다.\n", m_PC->HP());
		printf_s("현재 경험치는 %d입니다.\n", m_PC->Exp());
		printf_s("지금은 9월 %d일 %s입니다.\n현재 시각은 %d시입니다.\n", m_Day, m_DayName[m_NumOfWeek].c_str(), m_Hour);
	}

	if (strInput == "이동") {
		int userSelect = 0;
		printf_s("어디로 이동하시겠습니까?\n");
		printf_s("1.집  2.지하철  3.백화점  4.냉동창고\n");
		scanf_s("%d", &userSelect);
		m_PC->MoveCharacter(userSelect);
		if (m_PC->IsStorage()) 
			CreateGulbies();
	}

	if (strInput == "도움") {
		system("cls");
		printf_s("정보: 현재 체력, 경험치, 시각을 확인합니다.\n");
		printf_s("이동: 집, 지하철, 백화점, 냉동창고 등으로 이동합니다.\n");
		printf_s("여기: 현재 위치하고 있는 장소를 표시합니다.\n");
	}

// 	if(strInput == "집") {
// 		if(m_PC->IsSubway()) {
// 			m_PC->GoHome();
// 			m_PC->PrintHere();
// 		}
// 		else if (m_PC->IsHome()) {
// 			printf_s("현재 집에 위치해 있습니다.\n");
// 		}
// 		else {
// 			NonMovable();
// 		}
// 	}

	if(strInput == "잠자기") {
		int hourSleep = 0;
		if (m_PC->IsHome()) {
			printf_s("몇 시간동안 잠을 자겠습니까?");
			scanf_s("%d", &hourSleep);
			
			if ( hourSleep < 0 )
				printf_s("음수로 어떻게 잠을 자나요ㅡ_ㅡ\n\n");
			//else if ( hourSleep + m_Hour > 8 )
			//	printf_s("그렇게 잤다가는 지각하고 말걸요..\n\n");
			else
				m_PC->TakeSleep(hourSleep);
		}
	}

// 	if(strInput == "백화점") {
// 		if (m_PC->IsSubway() || m_PC->IsStorage()) {
// 			m_PC->GoDepartment();
// 			m_PC->PrintHere();
// 		}
// 		else if (m_PC->IsDepartment()) {
// 			printf_s("현재 백화점에 위치해 있습니다.\n");
// 		}
// 		else {
// 			NonMovable();
// 		}
// 	}

// 	if(strInput == "창고") {
// 		if (m_PC->IsDepartment()) {
// 			m_PC->GoStorage();
// 			m_PC->PrintHere();
// 			srand((unsigned)time(NULL));
// 			CreateGulbies();
// 		}
// 		else if (m_PC->IsStorage()) {
// 			printf_s("현재 창고에 위치해 있습니다.\n");
// 		}
// 		else { 
// 			NonMovable();
// 		}
// 	}
// 
// 	if(strInput == "지하철") {
// 		if (m_PC->IsHome() || m_PC->IsDepartment()) {
// 			m_PC->GoSubway();
// 			m_PC->PrintHere();
// 		}
// 		else if (m_PC->IsSubway()) {
// 			printf_s("현재 지하철에 위치해 있습니다.\n");
// 		}
// 		else {
// 			NonMovable();
// 		}
// 	}

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

	if(pMapInfo->pGulbi && pMapInfo->pGulbi->IsAlive()) {  //이른 종결이 되므로 Null Ptr 참조 에러가 발생하지 않는다.
		m_GameState = BATTLE;
		BattleResult result = StartBattle(pMapInfo->pGulbi);
		if (result == BATTLE_WIN) {
			delete pMapInfo->pGulbi;
			pMapInfo->pGulbi = nullptr;
		}
		else if (result == BATTLE_LOSE) {
			m_PC->GoHome();
		}
	}
}

//Map을 넘기거나 이중 포인터를 사용하는 것은 다소 우아하지 못하다.
BattleResult CGameManager::StartBattle( CGulbi* pGulbi) {
	BattleResult battleResult = (BattleResult)NULL;
	if (!m_PC->IsAlive()) {
		printf_s("기절 상태에서는 굴비를 손질할 수 없습니다.\n ");
		m_GameState = NORMAL;
	}

	while (m_PC->IsAlive() && pGulbi->IsAlive()) {
		printf_s("< 굴비를 손질합니다. >\n");
		srand((unsigned)time(NULL));
		TypePart();
		
		AttackResult result = (AttackResult)(rand() % ATTACK_COUNT);

		// POWER_OFFSET만큼 데미지에 +- 한다. 많이 쓰이는 기법!
		int damage = m_PC->Power() + (rand() % POWER_OFFSET * 2) - POWER_OFFSET;
		pGulbi->HitCheck(result, damage);

		//플레이어 턴에 플레이어가 살아 있는 지 체크하는 건 의미가 없다.
		// 플레이어 턴에는 몬스터의 생사 여부를 판단해야 한다.
		if(!pGulbi->IsAlive()) {
			printf_s("굴비(%s) 손질을 완료했습니다!!\n", pGulbi->GetName().c_str());
			printf_s("경험치가 %d 상승했습니다.\n", pGulbi->Exp());
			m_PC->GetExp(pGulbi->Exp());
			battleResult = BATTLE_WIN;
			break;
		}

		// 몬스터 턴
		printf_s("< 굴비(%s)가시에 손을 찔리고 말았습니다. >\n", pGulbi->GetName().c_str());
		result = (AttackResult)(rand() % ATTACK_COUNT);
		damage = pGulbi->Power() + (rand() % POWER_OFFSET * 2) - POWER_OFFSET;
		m_PC->HitCheck(result, damage);                

		if(!m_PC->IsAlive()) {
			printf_s(" 과로로 인해 기절해 버리고 말았습니다. \n");
			printf_s("집으로 강제로 이송되어 체력이 모두 회복될 때까지 잠을 자게 됩니다.\n");			
			battleResult = BATTLE_LOSE;
		}
		Sleep(250);
	}

	printf_s("<<<<< 손질한 굴비를 고객에게 전달해주었습니다. >>>>>>\n");
	m_GameState = NORMAL;
	return battleResult;
}

void CGameManager::NonMovable()
{
	printf_s("현재 장소에서는 그 곳으로 이동할 수 없습니다.");
}

void CGameManager::TypePart() {
	//머리, 지느러미, 꼬리를 선택하기 위한 난수 생성
	// 머리 = HEAD = 0
	// 지느러미 = FIN = 1
	// 꼬리 = TAIL = 2
	std::string partInput;
	int randNum;

	while (true) {
		randNum = rand() % NUM_OF_PARTS;	
		switch (randNum) {
		case HEAD: {
			printf_s("머리를 잘라야합니다: ");
			getline(std::cin, partInput);
			if (partInput == "머리") {
				printf_s("머리를 무사히 잘랐습니다.\n\n");
				return;
			}
			else 
				printf_s("으악! 잘못 잘라서 직원에게 쿠사리를 먹었습니다.\n\n");
				   }
		case FIN: {
			printf_s("지느러미를 잘라야합니다: ");
			getline(std::cin, partInput);
			if (partInput == "지느러미") {
				printf_s("지느러미를 무사히 잘랐습니다.\n");
				return;
			}
			else 
				printf_s("으악! 잘못 잘라서 직원에게 쿠사리를 먹었습니다.\n\n");
				  }
		case TAIL: {
			printf_s("꼬리를 잘라야합니다: ");
			getline(std::cin, partInput);
			if (partInput == "꼬리") {
				printf_s("꼬리를 무사히 잘랐습니다.\n\n");
				return;
			}
			else 
				printf_s("으악! 잘못 잘라서 직원에게 쿠사리를 먹었습니다.\n\n");
				   }
		}
	}
}

void CGameManager::NumHoursLater(int hours) {
	m_Hour = m_Hour + hours;
	if (m_Hour > 24) {
		m_Hour -= 24;
		m_Day++;
		m_NumOfWeek++;
		if(m_NumOfWeek == 7)
			m_NumOfWeek = 0;
	}
}

CGameManager* CGameManager::GetInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new CGameManager;
	}

	return m_instance;
}