#include"����.h"

using namespace std;

#pragma region ȫ�ֱ���

HINSTANCE hInst;   // ��ǰ����ʵ��
DWORD	  g_tPre=0,g_tNow=0;	  // ����������������¼ʱ��,g_tPre��¼��һ�λ�ͼ��ʱ�䣬g_tNow��¼�˴�׼����ͼ��ʱ��

HBITMAP bmp_Background_Start;			//��ʼ����ͼ����Դ
HBITMAP bmp_Background_Stage1;			//��һ�ر���ͼ����Դ
HBITMAP bmp_Background_Stage2;			//�ڶ��ر���ͼ����Դ
HBITMAP bmp_Help_Background;		//��Ϸ��������ͼ����Դ
HBITMAP bmp_Choice_Background;	//ѡ�ر���ͼ����Դ
HBITMAP bmp_Background_Pause;	//��ͣ����ͼ����Դ
HBITMAP bmp_Background_Failed;	//ʧ�ܱ���ͼ����Դ
HBITMAP bmp_StartButton;		//��ʼ��ťͼ����Դ
HBITMAP bmp_ExitButton;			//�˳���ťͼ����Դ
//HBITMAP bmp_Title;				//��Ϸ����ͼ����Դ
HBITMAP bmp_HelpButton;			//��Ϸ������ťͼ����Դ
HBITMAP bmp_Hero;				//����ͼ����Դ
HBITMAP	bmp_HeroHealth;			//��������ֵͼ����Դ
HBITMAP bmp_Skill;				//���Ǽ��ܣ���սͼ����Դ
HBITMAP bmp_Pause;				//��Ϸ��ͣ��ťͼ����Դ
HBITMAP bmp_Chose1;				//ѡ��ؿ�1��ťͼ����Դ
HBITMAP bmp_Chose2;				//ѡ��ؿ�2��ťͼ����Դ
HBITMAP bmp_BulletHero;			//�����ӵ�ͼ����Դ
HBITMAP bmp_Trap[3];			//��ͼ����ͼ����Դ
HBITMAP bmp_Brick[5];			//��ͼש��ͼ����Դ
HBITMAP bmp_Crash[8];			//��ըͼ����Դ
HBITMAP bmp_Boss1;				//��һ��bossͼ����Դ
HBITMAP bmp_Boss2;				//�ڶ���bossͼ����Դ
HBITMAP bmp_Boss2_Plus;				//�ڶ���bossͼ����Դ
HBITMAP bmp_Boss_Protect;		//�ڶ���boss������ͼ����Դ
HBITMAP bmp_Boss_Bullet1;		//��һ��boss�ӵ�ͼ����Դ
HBITMAP bmp_Boss_Bullet2;		//��һ��boss�ӵ�ͼ����Դ
HBITMAP bmp_Boss_Bullet_Rush;	//�ڶ���boss������ͼ����Դ
HBITMAP bmp_Hero_Attack_Skill[7];		//���ǽ�ս����ͼ����Դ
HBITMAP bmp_Hero_Protect;		//�������˺��޵з���ͼ����Դ/boss1��������Դ
HBITMAP bmp_Skill_Bonus_Ready;		//���Ǹ�������ȴ��ʾͼ����Դ
HBITMAP bmp_StrongButton;   //���Ǹ�����ѡ��ťͼ����Դ
HBITMAP bmp_AttackButton;	//���Ǹ�����ѡ��ťͼ����Դ
HBITMAP bmp_BulletButton;	//���Ǹ�����ѡ��ťͼ����Դ
HBITMAP bmp_MoveButton;	//���Ǹ�����ѡ��ťͼ����Դ
HBITMAP bmp_Enemy1;				//С������1ͼ����Դ
HBITMAP bmp_Enemy2;				//С������2ͼ����Դ
HBITMAP bmp_ChoiceButton;	//����ѡ��ҳ�水ťͼ����Դ
HBITMAP bmp_ContinueButton;	//������ǰ��Ϸͼ����Դ
HBITMAP bmp_TitleButton;	//���ر���ҳ�水ťͼ����Դ
HBITMAP bmp_RetryButton;	//���԰�ťͼ����Դ
HBITMAP bmp_backgroundofstage1;	//�½�һ��������ͼ����Դ
HBITMAP bmp_backgroundofstage2;	//�½ڶ���������ͼ����Դ

Stage* currentStage = NULL; //��ǰ����״̬
Stage preStage;		//������ͣ����ǰ�ĳ���
Hero* theHero = NULL; //����״̬
int skill_bonus = HERO_SKILL_STRONG; //���Ǹ�����
Boss_Condition* Boss = NULL; //boss״̬
vector<Boss_Condition*> Boss_Bonus; //�ڶ���boss�ӳ��� 
vector<Enemy_Condition*> Enemy; //С��
vector<Button*> buttons; //��ť
vector<Bullet_Normal*> Bullet_normal; //�����ӵ�
vector<Trap*> MapTrap; //��ͼ����
vector<Trick*> Brick; //ש��

int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;
bool mouseRDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool keySpaceDown = false;
int message;
bool trap_exist[5] = {};
int num_enemy = 0;		//��boss�ٻ���С������������boss�Ƿ���л���
bool handy_protect_boss = false;  //�Ƿ��������ֶ�����boss�ĺ���
int bullet_kind;		//��Ļ����
int sum_bullet_session = 0;
bool Hero_Skill_Ready = true;	//��ȴ�Ƿ����
int Hero_Skill_Using = 0;	//�����Ƿ�����ʹ��
bool Hero_Skill_Attack = false;  //�ж��Ҽ������Ƿ��boss��ɹ��˺�
bool First_ = true;
TCHAR g_buf[256];   //����Ƶ��
int map_move_x;		//�ڶ����ӽ��ƶ���
int map_move_x_plus;		//�ڶ����ӽ��ƶ���
int num_bonus = 0;		//���popback��size��������
double const PI = acos(double(-1));   //�еĶ��壬��ײ���ʱ��
int stagechoose = 0;	//ѡ��Ĺؿ�

#pragma endregion

#pragma region Win32���

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_WINDOWS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = WINDOW_TITLE;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON_WINDOWS));
    return RegisterClassExW(&wcex);
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPWSTR    lpCmdLine,_In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //ע�ᴰ����
    MyRegisterClass(hInstance);

    // ��������:
	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����
    HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE,
	   WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // ���ô�����ʽ�����ɸı��С���������,
	   CW_USEDEFAULT, 
	   CW_USEDEFAULT,
	   WINDOW_WIDTH,
	   WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
	   nullptr, nullptr, hInstance, nullptr);
    if (!hWnd)
    {
	   MessageBox(hWnd, L"���ڽ���ʧ��", L"��Ϣ����", 0); //ʹ��MessageBox����������һ����Ϣ����
       return FALSE;
    }

	if (First_) 
	{
		//���ſ�����Ƶ	
		wchar_t open_order[300];  
		swprintf_s(open_order, L"open ��Դ/��Ƶ/Ƭͷ.avi type MPEGVideo Alias movie parent %u Style %u notify", hWnd, WS_CHILD);	
		mciSendString(open_order, g_buf, sizeof(g_buf), NULL);
		//mciSendString(L"put Ƭͷ.avi window at 280 100 [720 480]", g_buf, sizeof(g_buf), NULL);
		mciSendString(L"play movie", g_buf, sizeof(g_buf), NULL);
		MoveWindow(hWnd,250,80,720,480,true);
		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);	
		First_ = false;
	}

	Sleep(15000);
	mciSendString(L"close movie", g_buf, sizeof(g_buf), NULL);

	First_ = false;
	InitStage(hWnd, STAGE_STARTMENU);
	MoveWindow(hWnd,250,80,WINDOW_WIDTH,WINDOW_HEIGHT,true);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	srand(time(NULL));

	MSG msg = { 0 };				//���岢��ʼ��msg
	while( msg.message != WM_QUIT )		//ʹ��whileѭ���������Ϣ����WM_QUIT��Ϣ���ͼ���ѭ��
	{
		if( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) )   //�鿴Ӧ�ó�����Ϣ���У�����Ϣʱ�������е���Ϣ�ɷ���ȥ��
		{
			TranslateMessage( &msg );		//���������Ϣת��Ϊ�ַ���Ϣ
			DispatchMessage( &msg );			//�ַ�һ����Ϣ�����ڳ���
		}
	}

	//��6���������ע��
	UnregisterClass(WINDOW_TITLE, hInstance);  //����׼��������ע��������
	return 0;  
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:		// ������Դ+��ʼ����Ϸ����

		if (!Game_Load(hWnd, wParam, lParam)) 
		{
			MessageBox(hWnd, L"��Դ��ʼ��ʧ��", L"��Ϣ����", 0); //ʹ��MessageBox����������һ����Ϣ����
			return FALSE;
		}

		break;
	case WM_KEYDOWN:		// ���̰����¼�

		KeyDown(hWnd, wParam, lParam);

		break;
	case WM_KEYUP:		// �����ɿ��¼�

		KeyUp(hWnd, wParam, lParam);

		break;
	case WM_MOUSEMOVE:		// ����ƶ��¼�

		MouseMove(hWnd, wParam, lParam);

		break;
	case WM_LBUTTONDOWN:		// �����������¼�

		LButtonDown(hWnd, wParam, lParam);

		break;
	case WM_LBUTTONUP:		// �������ɿ��¼�

		LButtonUp(hWnd, wParam, lParam);

		break;
	case WM_RBUTTONDOWN:		// ����Ҽ������¼�

		RButtonDown(hWnd, wParam, lParam);

		break;
	case WM_RBUTTONUP:		// ����Ҽ��ɿ��¼�

		RButtonUp(hWnd, wParam, lParam);

		break;
	case WM_TIMER:		// ��ʱ���¼�

		if(currentStage!=NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);

		break;
    case WM_PAINT:		// ��ͼ

		Game_Paint( hWnd );

        break;
    case WM_DESTROY:
		PostQuitMessage(0);

        break;
    default:		//������case�����������ϣ���ִ�и�default���

        return DefWindowProc(hWnd, message, wParam, lParam);	//����ϵͳԤ����ĵĴ��ڹ���

    }
    return 0;
}

#pragma endregion

#pragma region �¼�����

// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = true;
		break;
	case 'W':
		keyUpDown = true;
		break;
	case VK_DOWN:
		keyDownDown = true;
		break;
	case 'S':
		keyDownDown = true;
		break;
	case VK_LEFT:
		keyLeftDown = true;
		break;
	case 'A':
		keyLeftDown = true;
		break;
	case VK_RIGHT:
		keyRightDown = true;
		break;
	case 'D':
		keyRightDown = true;
		break;
	case VK_ESCAPE:
		if (currentStage == NULL || !(currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_2)) break;
		currentStage->timerOn = false;
		preStage = *currentStage;
		InitStage(hWnd, STAGE_PAUSE);
		break;
	case VK_SPACE:
		keySpaceDown = true; 
		break;
	default:
		break;
	}
}

// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = false;
		break;
	case 'W':
		keyUpDown = false;
		break;
	case VK_DOWN:
		keyDownDown = false;
		break;
	case 'S':
		keyDownDown = false;
		break;
	case VK_LEFT:
		keyLeftDown = false;
		break;
	case 'A':
		keyLeftDown = false;
		break;
	case VK_RIGHT:
		keyRightDown = false;
		break;
	case 'D':
		keyRightDown = false;
		break;
	case VK_SPACE:
		keySpaceDown = false; 
		break;
	default:
		break;
	}
}

// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;

	if (theHero!= NULL) 
	{		
		if (theHero->skill == HERO_SKILL_BULLET) SetTimer(hWnd, HERO_BULLET_TIMER, HERO_BULLET_SKILL_TIMER_ELAPSE, NULL);//��ʼ���ӵ���ʱ��
		else SetTimer(hWnd, HERO_BULLET_TIMER, HERO_BULLET_TIMER_ELAPSE, NULL);//��ʼ���ӵ���ʱ��

		Bullet_Normal* Hero_Bullet = CreateHeroBullet(bmp_BulletHero, HERO_BULLET_ID);
		if (theHero->skill == HERO_SKILL_BULLET) Hero_Bullet->v = BULLET_V_SKILL;
		Bullet_normal.push_back(Hero_Bullet);     //������ӵ�;  //�ӵ������뼼��ʹ��
		
		/*wchar_t open_order[300];  
		swprintf_s(open_order, L"open ��Դ/��Ч/�����ӵ������Ч.wav");	
		mciSendString(open_order, g_buf, sizeof(g_buf), NULL);
		mciSendString(L"play ��Դ/��Ч/�����ӵ������Ч.wav", g_buf, sizeof(g_buf), NULL);*/
		//mciSendString(L"close ��Դ/��Ч/�����ӵ������Ч.wav", g_buf, sizeof(g_buf), NULL);
	}

	for(int i=0;i<buttons.size();i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) 
				{
				case BUTTON_STARTGAME:
				{
					InitStage(hWnd,STAGE_CHOICE);
					//InitStage(hWnd, STAGE_1);
					break;
				}
				case BUTTON_HELP:
				{
					InitStage(hWnd, STAGE_HELP);
					break;
				}
				case BUTTON_PAUSE:
				{
					currentStage->timerOn = false;
					preStage = *currentStage;
					InitStage(hWnd, STAGE_PAUSE);
					break;
				}
				case BUTTON_CHOICESTAGE1:
				{
					if (stagechoose == STAGE_1) InitStage(hWnd, STAGE_1);
					else{
						stagechoose = STAGE_1;
						InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
					}
					break;
				}
				case BUTTON_CHOICESTAGE2:
				{
					if (stagechoose == STAGE_2)	InitStage(hWnd, STAGE_2);
					else{
						stagechoose = STAGE_2;
						InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
					}
					break;
				}
				case HERO_SKILL_ATTACK:
				{
					skill_bonus = HERO_SKILL_ATTACK;
					InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
					break;
				}
				case HERO_SKILL_BULLET:
				{
					skill_bonus = HERO_SKILL_BULLET;
					InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
					break;
				}
				case HERO_SKILL_STRONG:
				{
					skill_bonus = HERO_SKILL_STRONG;
					InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
					break;
				}
				case HERO_SKILL_LIGHTMOVE:
				{
					skill_bonus = HERO_SKILL_LIGHTMOVE;
					InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
					break;
				}
				case BUTTON_EXIT:
				{
					PostQuitMessage(0);
					break;
				}
				case BUTTON_RETRY:
				{
					pause_clear(hWnd);
					InitStage(hWnd, preStage.stageID);
					break;
				}
				case BUTTON_CONTINUE:
				{
					*currentStage = preStage;
					//��Ҫ�Ż����飬�Ӽ�ʱ����ʱ
					currentStage->timerOn = true;
					for(int i=0;i<buttons.size();i++)
					{
						Button* button = buttons[i];
						if (button->buttonID==BUTTON_PAUSE) 
						{
							button->visible = true;
						}
						else
						{
							button->visible = false;
						}
					}
					break;
				}
				case BUTTON_BACKTOTITLE:
				{
					pause_clear(hWnd);
					InitStage(hWnd, STAGE_STARTMENU);
					break;
				}
				case BUTTON_BACKTOCHOICE:
				{
					pause_clear(hWnd);
					InitStage(hWnd, STAGE_CHOICE);
					break;
				}

				default: break;
				}
			}
		}
	}
	
}
// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
	KillTimer(hWnd, HERO_BULLET_TIMER);
}

//����Ҽ������¼�������
void RButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseRDown = true;
	if (theHero!= NULL && Hero_Skill_Ready) 
	{
		if (theHero->skill == HERO_SKILL_ATTACK)
		{
			SetTimer(hWnd, TIMER_HERO_SKILL_LAST_ID, TIMER_HERO_SKILL_LAST, NULL);
			Hero_Skill_Using = 0;
			Hero_Skill_Ready = false;
		}
		if (theHero->skill == HERO_SKILL_LIGHTMOVE)
		{
			SetTimer(hWnd, TIMER_HERO_SKILL_CD_ID, TIMER_HERO_SKILL4_CD, NULL);
			Hero_Skill_Using++;
			Protect_Hero(hWnd);
			for(int i=0;i<Brick.size();i++)
			{
				Trick* brick = Brick[i];
				if (!brick->visible) continue;
				if (currentStage->stageID == STAGE_1  &&  pow(mouseX - brick->x - BRICK_SIZE/2, 2)+pow(mouseY - brick->y - BRICK_SIZE/2, 2) <= pow(HERO_SIZE_X/2 + BRICK_SIZE/2,2) 
					||  currentStage->stageID != STAGE_1  &&  pow(mouseX + map_move_x - brick->x - BRICK_SIZE/2, 2)+pow(mouseY - brick->y - BRICK_SIZE/2, 2) <= pow(HERO_SIZE_X/2 + BRICK_SIZE/2,2)) 
				{
					return;
				}
			}
			if (currentStage->stageID == STAGE_1) theHero->x = mouseX - HERO_SIZE_X/2;
			else {
				int tmp = theHero->x;
				theHero->x = mouseX + map_move_x - HERO_SIZE_X/2;
				map_move_x_plus += theHero->x - tmp;;
				if (abs(map_move_x_plus) <= 400) map_move_x = map_move_x_plus;
				else if (map_move_x_plus < -400) map_move_x = -400;
				else if (map_move_x_plus > 400) map_move_x = 400;
			}
			theHero->y = mouseY - HERO_SIZE_Y/2;
		}
	}
}
//����Ҽ��ɿ��¼�������
void RButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseRDown = false;
}

// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case TIMER_GAMETIMER:
		UpdateHero(hWnd);
		UpdateBoss(hWnd);
		UpdateEnemy(hWnd);
		Bullet_Collision(hWnd);
		break;
	case HERO_BULLET_TIMER:
		if (theHero != NULL){
			Bullet_Normal* Hero_Bullet = CreateHeroBullet(bmp_BulletHero, HERO_BULLET_ID);
			if (theHero->skill == HERO_SKILL_BULLET) Hero_Bullet->v = BULLET_V_SKILL;
			Bullet_normal.push_back(Hero_Bullet);     //������ӵ�
			
			/*wchar_t open_order[300];  
			swprintf_s(open_order, L"open ��Դ/��Ч/�����ӵ������Ч.wav");	
			mciSendString(open_order, g_buf, sizeof(g_buf), NULL);
			mciSendString(L"play ��Դ/��Ч/�����ӵ������Ч.wav", g_buf, sizeof(g_buf), NULL);
			mciSendString(L"close ��Դ/��Ч/�����ӵ������Ч.wav", g_buf, sizeof(g_buf), NULL);*/

			//PlaySound(L"��Դ/��Ч/�����ӵ������Ч.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		break;	
	case TIMER_TRAP:
		if (currentStage->timerOn == true)
		{		
			if (MapTrap.size()>=3)
			{
				trap_exist[MapTrap[0]->trapID-101] = false;
				MapTrap.erase(MapTrap.begin()+0);
			}
			else
			{
				int id;
				do id=(rand()%3) + 101;	while(trap_exist[id-101]);	
				trap_exist[id-101] = true;
				Trap* map_trap = NULL;
				if (currentStage->stageID == STAGE_1) { map_trap = CreateTrap( bmp_Trap[(id%100)-1], rand() % (WINDOW_WIDTH - 2*TRAP_WIDTH), rand() % (WINDOW_HEIGHT - 3*TRAP_WIDTH) + 100, id );}
				else map_trap = CreateTrap( bmp_Trap[(id%100)-1], rand() % (WINDOW_WIDTH + 400 - 2*TRAP_WIDTH) - 400, rand() % (WINDOW_HEIGHT - 3*TRAP_WIDTH) + 100, id );
				MapTrap.push_back(map_trap);
			}
		}
		break;
	case TIMER_PROTECT:
		theHero->protect = false;
		KillTimer(hWnd, TIMER_PROTECT);
		SetTimer(hWnd, TIMER_HERO_UPJUDGE, TIMER_HERO_UPJUDGE_ELAPSE, NULL);
		break;
	case TIMER_HERO_UPJUDGE:
		KillTimer(hWnd, TIMER_HERO_UPJUDGE);
		SetTimer(hWnd, TIMER_HERO_UP, TIMER_HERO_UP_ELAPSE, NULL);
		break;
	case TIMER_HERO_UP:
		if (theHero->skill == HERO_SKILL_STRONG && theHero->health < 6  ||  theHero->health < 4) theHero->health++;
		break;
	case TIMER_BOSS_PROTECT:
		if (!Boss->protect) Boss->protect = true;
		else {
			Boss->protect = false;
			handy_protect_boss = false;
		}
		KillTimer(hWnd, TIMER_BOSS_PROTECT);
		break;
	case TIMER_BOSS1:
		if (Boss->health >= BOSS_HEALTH1) SetTimer(hWnd, TIMER_BOSS1_BULLET, TIMER_BOSS1_BULLET_ELAPSE1, NULL);	
		else if (Boss->health >= BOSS_HEALTH2) SetTimer(hWnd, TIMER_BOSS1_BULLET, TIMER_BOSS1_BULLET_ELAPSE2, NULL);
		else SetTimer(hWnd, TIMER_BOSS1_BULLET, TIMER_BOSS1_BULLET_ELAPSE3, NULL);
		break;
	case TIMER_BOSS1_BULLET:
		{
			if (Boss->skill == BOSS_SKILL1){
				static int action = rand() % 6;
				static bool used = false;
				if ((action == BOSS_LIGHTMOVE || action == BOSS_RANDOM1 || action == BOSS_CALLING) && used == true) {
					action = rand() % 6;
					used = false;
				}
				else if ((action == BOSS_LIGHTMOVE || action == BOSS_RANDOM1 || action == BOSS_CALLING)) used = true;
				else action = rand() % 6;
				sum_bullet_session++;
				Send_Bullet(action, hWnd);
				if (sum_bullet_session>=TIMER_BOSS1_BULLET_SENDNUM){
					KillTimer(hWnd, TIMER_BOSS1_BULLET);
					sum_bullet_session = 0;
				}
			}
			else if (Boss->skill == BOSS_SKILL2){
				static int action = (rand() % 6) + 4;
				sum_bullet_session++;
				action = (rand() % 6) + 4;
				if (Boss->v == BOSS2_MAXV) Boss->v = BOSS2_V;
				Send_Bullet(action, hWnd);
				//Send_Bullet(8, hWnd);
				if (sum_bullet_session>=TIMER_BOSS1_BULLET_SENDNUM){
					sum_bullet_session = 0;
				}
			}
		break;
		}
	case TIMER_HERO_SKILL_CD_ID:
		Hero_Skill_Ready = true;
		Hero_Skill_Attack = false;
		Hero_Skill_Using = 0;
		KillTimer(hWnd, TIMER_HERO_SKILL_CD_ID);
		break;
	case TIMER_HERO_SKILL_LAST_ID:		
		if (Hero_Skill_Using >= 15)
		{
			SetTimer(hWnd, TIMER_HERO_SKILL_CD_ID, TIMER_HERO_SKILL2_CD, NULL);
			KillTimer(hWnd, TIMER_HERO_SKILL_LAST_ID);
			Hero_Skill_Using = 0;
		}
		else Hero_Skill_Using ++;
		break;
	case TIMER_ENEMY_BULLET:		
		if (Enemy.size() > 0)
		{
			for (int i=0; i<Enemy.size(); i++)
			{			
				Enemy_Condition* enemy = Enemy[i];
				if (enemy->skill == ENEMY_SKILL1){
					for (int j=1;j<=2;j++)
					{
						int seed=rand()%20;	
						int dx=theHero->x + HERO_SIZE_X / 2- enemy->x -BOSS_SIZE/2.0;
						int	dy=theHero->y + HERO_SIZE_Y / 2- enemy->y -BOSS_SIZE/2.0;
						Bullet_Normal* enemy_bullet = nullptr;					
						if (seed%11 != 0) enemy_bullet = CreateEnemyBullet(enemy, bmp_Boss_Bullet1, dx + (int)(pow(-1,rand()%10))*rand()%40, dy + (int)(pow(-1,rand()%10))*rand()%40, BOSS_BULLET_ID);
						else enemy_bullet = CreateEnemyBullet(enemy, bmp_Boss_Bullet2, dx + (int)(pow(-1,rand()%10))*rand()%40, dy + (int)(pow(-1,rand()%10))*rand()%40, BOSS_BULLET_ID);
						enemy_bullet->v += rand()%3;
						Bullet_normal.push_back(enemy_bullet);     //������ӵ�
					}
				}
			}
		}
		else KillTimer(hWnd, TIMER_ENEMY_BULLET);
		break;

	default:
		break;
	}
	InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
}


#pragma endregion

#pragma region ��Ϸ������ؿ�
// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)	
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;

	button->visible = false;
	return button;
}
// ������Ǻ���
Hero* CreateHero(HBITMAP img, int x, int y, int health, int skill)		
{
	Hero* hero = new Hero();
	hero->img = img;
	hero->x = x;
	hero->y = y;
	hero->frame = 0;
	hero->vx = 0;
	hero->vy = 0;
	hero->health = health;
	hero->skill = skill;
	hero->protect = false;
	if (skill == HERO_SKILL_STRONG) hero->health += 2;
	return hero;
}
//��������ӵ�����
Bullet_Normal* CreateHeroBullet(HBITMAP img, int ID)
{
	Bullet_Normal* bullet = new Bullet_Normal();
	bullet->ID = ID;
	bullet->inn = false;
	bullet->visible = true;
	bullet->collision = false;
	bullet->x = theHero->x + HERO_SIZE_X / 2 - HERO_BULLET_WIDTH / 2;
	bullet->y = theHero->y + HERO_SIZE_Y / 2 - HERO_BULLET_HEIGHT / 2;
	bullet->img = img;
	bullet->v = BULLET_V;
	if (currentStage->stageID == STAGE_1) {
		bullet->direction_x = mouseX - bullet->x;
		bullet->direction_y = mouseY - bullet->y;
	}
	else {
		bullet->direction_x = mouseX + map_move_x - bullet->x;
		bullet->direction_y = mouseY - bullet->y;
	}
	return bullet;
}

//��ӵ�ͼ���庯��
Trap* CreateTrap(HBITMAP img, int x, int y, int trap_id)		
{
	Trap* trap = new Trap();
	trap->img = img;
	trap->trapID = trap_id;
	trap->health = 5;
	trap->x = x;
	trap->y = y;
	trap->visible = true;
	trap->inn = false;
	return trap;
}

//��ӵ�ͼש�麯��
Trick* CreateBrick(HBITMAP img, int x, int y, int brick_id)		
{
	Trick* trick = new Trick();
	trick->img = img;
	trick->brickID = brick_id;
	trick->health = 10;
	trick->x = x;
	trick->y = y;
	trick->visible = true;

	return trick;
}

//���boss����
Boss_Condition* CreateBoss(HBITMAP img, int x, int y, int direct_x, int direct_y, int skill)
{
	Boss_Condition* boss= new Boss_Condition();
	boss->img = img;
	boss->protect = true;
	if (skill == BOSS_SKILL1) boss->v = BOSS_V;
	else boss->v = BOSS2_V;
	boss->skill = skill;
	boss->x = x;
	boss->y = y;
	boss->direction_x = direct_x;
	boss->direction_y = direct_y;
	if (skill == BOSS_SKILL1) boss->health = BOSS_HEALTH;
	else boss->health = BOSS2_HEALTH;
	return boss;
}

//���boss�ӵ�����
Bullet_Normal* CreateBossBullet(HBITMAP img, int x, int y, int directx, int directy, int ID)
{
	Bullet_Normal* bullet = new Bullet_Normal();
	bullet->ID = ID;
	bullet->inn = false;
	bullet->visible = true;
	bullet->x = x + BOSS_SIZE / 2;
	bullet->y = y + BOSS_SIZE / 2;
	bullet->img = img;
	if (ID == BOSS_BULLET_RUSH_ID) bullet->v = BOSS_BULLET_RUSH_V;
	else bullet->v = BOSS_BULLET_V;
	bullet->direction_x = directx;
	bullet->direction_y = directy;
	return bullet;
}

//���С������
Enemy_Condition* CreateEnemy(HBITMAP img, int x, int y, int direct_x, int direct_y, int skill, HWND hWnd, int ID)
{
	if (Enemy.size()>=8) return NULL;
	Enemy_Condition* enemy= new Enemy_Condition();
	enemy->img = img;
	if (currentStage->stageID == STAGE_1) enemy->v = ENEMY_V;
	else enemy->v = ENEMY_V2;
	enemy->protect = false;
	enemy->skill = skill;
	enemy->x = x;
	enemy->y = y;
	enemy->direction_x = direct_x;
	enemy->direction_y = direct_y;
	enemy->ID = ID;
	enemy->health = ENEMY_HEALTH;
	if (enemy->skill == ENEMY_SKILL2) enemy->health --;
	SetTimer(hWnd, TIMER_ENEMY_BULLET, TIMER_ENEMY_BULLET_ELAPSE, NULL);
	if (enemy->ID == ENEMY_ID1) num_enemy++;
	return enemy;
}
//���С���ӵ�����
Bullet_Normal* CreateEnemyBullet(Enemy_Condition* enemy, HBITMAP img, int directx, int directy, int ID)
{
	Bullet_Normal* bullet = new Bullet_Normal();
	bullet->ID = ID;
	bullet->inn = false;
	bullet->visible = true;
	bullet->x = enemy->x + ENEMY_SIZE / 2;
	bullet->y = enemy->y + ENEMY_SIZE / 2;
	bullet->img = img;
	bullet->v = ENEMY_BULLET_V;
	bullet->direction_x = directx;
	bullet->direction_y = directy;
	return bullet;
}


// ��ʼ����Ϸ��������
void InitStage(HWND hWnd, int stageID)	
{
	// ��ʼ������ʵ��
	if (stageID != STAGE_PAUSE)	
	{	
		if (currentStage != NULL) delete currentStage;
		currentStage = new Stage();
		

		//��ʼ����������		
		Hero_Skill_Ready = true;	//��ȴ�Ƿ����
		Hero_Skill_Using = 0;	//�����Ƿ�����ʹ��
		Hero_Skill_Attack = false;
	}
	currentStage->stageID = stageID;
	mouseX = 0;
	mouseY = 0;	
	mouseDown = false;
	keyUpDown = false;
	keyDownDown = false;
	keyLeftDown = false;
	keyRightDown = false;
	keySpaceDown = false;
	if (stageID == STAGE_STARTMENU) 
	{
		currentStage->background = bmp_Background_Start;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		if (theHero != NULL) delete theHero;
		//��ʾ��ʼ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (((button->buttonID / 1000)==1))    //ͨ��ȡģ���жϰ�ť�����Ĺؿ�
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}

		//��ʾ����
		TCHAR str[] = TEXT("NieR Automata");
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint(hWnd, &ps);
		TextOut(hDC, 10, 10, str, _tcslen(str));
		EndPaint(hWnd, &ps);
		
		//��������
		PlaySound(L"��Դ\\bgm\\�������뤫�� (Long Version).wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);	
	}
	else if(stageID == STAGE_1) 
	{
		currentStage->background = bmp_Background_Stage1;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		SetTimer(hWnd, TIMER_TRAP, TIMER_TRAP_ELAPSE, NULL);//��ʼ�������ʱ��

		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID / 1000 == 2) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}

		// ��ʼ������
		if (theHero != NULL) delete theHero;
		theHero = CreateHero(bmp_Hero, 200, 400, 4, skill_bonus);

		Protect_Hero(hWnd); 
		//theHero->protect = true;  //������

		// ��ʼ��boss
		if (Boss != NULL) delete Boss;
		Boss = CreateBoss(bmp_Boss1, 650, 200, 650 - theHero->x , 200 - theHero->y, BOSS_SKILL1);
		SetTimer(hWnd, TIMER_BOSS1, TIMER_BOSS1_ELAPSE1, NULL);

		//������ͨ?ש��
		srand(time(NULL));
		int sseed = rand()%5;
		if (sseed != 0){
		int seed=rand()%3;
		if (seed == 0){
			for (int i=0;i<=2;i++) 
			{
				int seed2 = rand()%6;
				Trick* brick=NULL;
				if (seed2 == 0) brick= CreateBrick(bmp_Brick[3], 350, 100+i*200, BRICK_KIND3);
				else brick= CreateBrick(bmp_Brick[1], 350, 100+i*200, BRICK_KIND1);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[2], 350, 200+i*200, BRICK_KIND2);
				Brick.push_back(brick);
			}
		}
		else if (seed == 1){
			for (int i=0;i<=2;i++) 
			{
				int seed2 = rand()%6;
				Trick* brick=NULL;
				if (seed2 == 0) brick= CreateBrick(bmp_Brick[3], 50+i*200, 250, BRICK_KIND3);
				else brick= CreateBrick(bmp_Brick[1], 50+i*200, 250, BRICK_KIND1);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[2], 150+i*200, 250, BRICK_KIND2);
				Brick.push_back(brick);
			}
		}
		else{
			for (int i=0;i<=2;i++) 
			{
				int seed2 = rand()%6;
				Trick* brick=NULL;
				if (seed2 == 0) brick= CreateBrick(bmp_Brick[3], 350, 100+i*200, BRICK_KIND3);
				else brick= CreateBrick(bmp_Brick[1], 350, 100+i*200, BRICK_KIND1);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[2], 350, 200+i*200, BRICK_KIND2);
				Brick.push_back(brick);
			}
			for (int i=0;i<=2;i++) 
			{
				int seed2 = rand()%6;
				Trick* brick=NULL;
				if (seed2 == 0) brick= CreateBrick(bmp_Brick[3], 50+i*200, 250, BRICK_KIND3);
				else brick= CreateBrick(bmp_Brick[1], 50+i*200, 250, BRICK_KIND1);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[2], 150+i*200, 250, BRICK_KIND2);
				Brick.push_back(brick);
			}
		}
		//���û���ש��
		seed = rand()%6;
		if (seed == 0)
		{
			Trick* brick= CreateBrick(bmp_Brick[3], 0, 40, BRICK_KIND3);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[3], 0, 90, BRICK_KIND3);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[3], 0, 500, BRICK_KIND3);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[3], 50, 500, BRICK_KIND3);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[3], 740, 40, BRICK_KIND3);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[3], 690, 40, BRICK_KIND3);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[3], 740, 500, BRICK_KIND3);
			Brick.push_back(brick);		
			brick= CreateBrick(bmp_Brick[3], 740, 450, BRICK_KIND3);
			Brick.push_back(brick);		
		}
		else if (seed == 2  || seed == 4)
		{
			for (int i=0;i<=16;i++) 
			{
				Trick* brick= CreateBrick(bmp_Brick[3], i*50, 500, BRICK_KIND3);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[3], i*50, 40, BRICK_KIND3);
				Brick.push_back(brick);
			}
		}
		else if (seed == 1  ||  seed == 3)
		{
			for (int i=0;i<=11;i++) 
			{
				Trick* brick= CreateBrick(bmp_Brick[3], 0, 40+i*50, BRICK_KIND3);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[3], 740, 40+i*50, BRICK_KIND3);
				Brick.push_back(brick);
			}
		}

		}	

		//����С��
		for (int i=1;i<=3;i++)
		{
			int x,y;
			do {  x = (rand()%(WINDOW_WIDTH-ENEMY_SIZE-30))+5;
				y = (rand()%(WINDOW_HEIGHT-ENEMY_SIZE-100))+60;
			} while ((pow((Boss->x- x), 2)+pow((Boss->y - y), 2)) <= pow(BOSS_SIZE+100, 2)  ||  (pow((theHero->x- x), 2)+pow((theHero->y - y), 2)) <= pow(BOSS_SIZE+100, 2));
			Enemy_Condition* enemy=CreateEnemy(bmp_Enemy1, x, y, theHero->x + HERO_SIZE_X - x - ENEMY_SIZE/2.0, 
				theHero->y + HERO_SIZE_Y - y - ENEMY_SIZE/2.0, ENEMY_SKILL1, hWnd, ENEMY_ID1);
			//ש����ײ
			for(int i=0;i<Brick.size();i++)
			{
				Trick* brick = Brick[i];
				if (!brick->visible) continue;
				if (pow(enemy->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
					<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +10,2) ) 
				{
					if (enemy->ID == ENEMY_ID1) num_enemy--;
					Enemy_Condition* enemy2 = enemy;
					enemy = NULL;
					delete(enemy2);
					break;
				}
			}
			if (enemy != NULL) Enemy.push_back(enemy);
			else Boss->health += 2;
		}
		Enemy_Condition* enemy=CreateEnemy(bmp_Enemy1, 100, 100, theHero->x + HERO_SIZE_X - 100 - ENEMY_SIZE/2.0, 
			theHero->y + HERO_SIZE_Y - 100 - ENEMY_SIZE/2.0, ENEMY_SKILL1, hWnd, ENEMY_ID1);
		Enemy.push_back(enemy);
		enemy=CreateEnemy(bmp_Enemy2, 600, 400, theHero->x + HERO_SIZE_X - 600 - ENEMY_SIZE/2.0, 
			theHero->y + HERO_SIZE_Y - 400 - ENEMY_SIZE/2.0, ENEMY_SKILL1, hWnd, ENEMY_ID1);
		Enemy.push_back(enemy);

		//��������
		PlaySound(L"��Դ\\bgm\\TAMUSIC - only my railgun.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
	}
	else if(stageID == STAGE_2) 
	{
		currentStage->background = bmp_Background_Stage2;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		SetTimer(hWnd, TIMER_TRAP, TIMER_TRAP_ELAPSE, NULL);//��ʼ�������ʱ��

		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID / 1000 == 2) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}

		// ��ʼ������
		if (theHero != NULL) delete theHero;
		theHero = CreateHero(bmp_Hero, 400, 300, 4, skill_bonus);
		map_move_x = 0;
		map_move_x_plus = 0;

		Protect_Hero(hWnd); 
		//theHero->protect = true;   //������

		// ��ʼ��boss
		if (Boss != NULL) delete Boss;
		Boss = CreateBoss(bmp_Boss2, 700, 200, 700 - theHero->x , 200 - theHero->y, BOSS_SKILL2);
		SetTimer(hWnd, TIMER_BOSS1_BULLET, TIMER_BOSS2_BULLET_ELAPSE, NULL);
		for (int i=0; i<5; i++)
		{
			Boss_Condition* boss = CreateBoss(bmp_Boss2_Plus, Boss->x + BOSS2_SIZE*0.6 + BOSS_SIZE*i, Boss->y + BOSS2_SIZE*0.2, 0, 0, BOSS_SKILL2);
			Boss_Bonus.push_back(boss);
			num_bonus++;
		}
		
		
		srand(time(NULL));
		int sseed = rand()%5;
		if (sseed != 0){
		//���û���ש��
		int seed = rand()%3;
		if (seed == 0)
		{
			Trick* brick= CreateBrick(bmp_Brick[3], 0, 40, BRICK_KIND3);
			Brick.push_back(brick);
		/*	brick= CreateBrick(bmp_Brick[3], 0, 90, BRICK_KIND3);
			Brick.push_back(brick);*/
			brick= CreateBrick(bmp_Brick[3], 0, 500, BRICK_KIND3);
			Brick.push_back(brick);
		/*	brick= CreateBrick(bmp_Brick[3], 50, 500, BRICK_KIND3);
			Brick.push_back(brick);*/
			brick= CreateBrick(bmp_Brick[3], 740, 40, BRICK_KIND3);
			Brick.push_back(brick);
		/*	brick= CreateBrick(bmp_Brick[3], 690, 40, BRICK_KIND3);
			Brick.push_back(brick);*/
			brick= CreateBrick(bmp_Brick[3], 740, 500, BRICK_KIND3);
			Brick.push_back(brick);		
		/*	brick= CreateBrick(bmp_Brick[3], 740, 450, BRICK_KIND3);
			Brick.push_back(brick);	*/
			brick= CreateBrick(bmp_Brick[3], -380, 450, BRICK_KIND3);
			Brick.push_back(brick);	
			brick= CreateBrick(bmp_Brick[3], -380, 500, BRICK_KIND3);
			Brick.push_back(brick);	
			brick= CreateBrick(bmp_Brick[3], -380, 40, BRICK_KIND3);
			Brick.push_back(brick);	
			brick= CreateBrick(bmp_Brick[3], -330, 40, BRICK_KIND3);
			Brick.push_back(brick);	
			brick= CreateBrick(bmp_Brick[3], 1120, 450, BRICK_KIND3);
			Brick.push_back(brick);	
			brick= CreateBrick(bmp_Brick[3], 1120, 500, BRICK_KIND3);
			Brick.push_back(brick);	
			brick= CreateBrick(bmp_Brick[3], 1120, 40, BRICK_KIND3);
			Brick.push_back(brick);	
			brick= CreateBrick(bmp_Brick[3], 1120, 40, BRICK_KIND3);
			Brick.push_back(brick);	
		}
		else if (seed == 1)
		{
			for (int i=0;i<=11;i++) 
			{
				Trick* brick= CreateBrick(bmp_Brick[3], 40+i*50, 40, BRICK_KIND3);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[3], 40+i*50, 500, BRICK_KIND3);
				Brick.push_back(brick);
			}

		}
		else if (seed == 2)
		{
			for (int i=0;i<=9;i++) 
			{
				Trick* brick= CreateBrick(bmp_Brick[3], -380, 40+i*50, BRICK_KIND3);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[3], 1120, 40+i*50, BRICK_KIND3);
				Brick.push_back(brick);
			}
		}
		//������ͨ?ש��
		seed=rand()%3;
		if (seed == 0){
			for (int i=0;i<=2;i++) 
			{
				Trick* brick= CreateBrick(bmp_Brick[2], -80, 250+i*50, BRICK_KIND2);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[2], 900, 140+i*50, BRICK_KIND2);
				Brick.push_back(brick);
			}
			Trick* brick= CreateBrick(bmp_Brick[1], -80, 150, BRICK_KIND1);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[1], -80, 200, BRICK_KIND1);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[1], 900, 290, BRICK_KIND1);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[1], 900, 340, BRICK_KIND1);
			Brick.push_back(brick);
		}
		else if (seed == 1){
			for (int i=0;i<=2;i++) 
			{
				Trick* brick= CreateBrick(bmp_Brick[2], -80, 140+i*50, BRICK_KIND2);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[2], 900, 250+i*50, BRICK_KIND2);
				Brick.push_back(brick);
			}
			Trick* brick= CreateBrick(bmp_Brick[1], 900, 150, BRICK_KIND1);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[1], 900, 200, BRICK_KIND1);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[1], -80, 290, BRICK_KIND1);
			Brick.push_back(brick);
			brick= CreateBrick(bmp_Brick[1], -80, 340, BRICK_KIND1);
			Brick.push_back(brick);
		}
		else if (seed == 2){
			for (int i=0;i<=2;i++) 
			{
				Trick* brick= CreateBrick(bmp_Brick[1], -100+i*50, 300, BRICK_KIND1);
				Brick.push_back(brick);
				brick= CreateBrick(bmp_Brick[1], 800+i*50, 200, BRICK_KIND1);
				Brick.push_back(brick);
			}
		}
		
		}

		//����С��
		for (int i=1;i<=3;i++)
		{
			int x,y;
			do {  x = (rand()%(WINDOW_WIDTH-ENEMY_SIZE-30))+5;
				y = (rand()%(WINDOW_HEIGHT-ENEMY_SIZE-100))+60;
			} while ((pow((Boss->x- x), 2)+pow((Boss->y - y), 2)) <= pow(BOSS_SIZE+100, 2)  ||  (pow((theHero->x- x), 2)+pow((theHero->y - y), 2)) <= pow(BOSS_SIZE+100, 2));
			Enemy_Condition* enemy=CreateEnemy(bmp_Enemy1, x, y, theHero->x + HERO_SIZE_X - x - ENEMY_SIZE/2.0, 
				theHero->y + HERO_SIZE_Y - y - ENEMY_SIZE/2.0, ENEMY_SKILL1, hWnd, ENEMY_ID1);
			//ש����ײ
			for(int i=0;i<Brick.size();i++)
			{
				Trick* brick = Brick[i];
				if (!brick->visible) continue;
				if (pow(enemy->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
					<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +10,2) ) 
				{
					if (enemy->ID == ENEMY_ID1) num_enemy--;
					Enemy_Condition* enemy2 = enemy;
					enemy = NULL;
					delete(enemy2);
					break;
				}
			}
			if (enemy != NULL) Enemy.push_back(enemy);
			else Boss->health += 2;
		}

		//��������
		PlaySound(L"��Դ\\bgm\\TAMUSIC - only my railgun.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
	}
	else if(stageID == STAGE_HELP)
	{
		currentStage->background = bmp_Help_Background;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = false;
		if (theHero != NULL) 
		{
			delete theHero;
			theHero = NULL;
		}	
		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID==BUTTON_BACKTOTITLE) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		//��������
		PlaySound(L"��Դ\\bgm\\AIR - ��Ӱ.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
	}
	else if(stageID == STAGE_CHOICE)
	{
		currentStage->background = bmp_Choice_Background;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = false;
		if (theHero != NULL) 
		{
			delete theHero;
			theHero = NULL;
		}
		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID / 1000 == 4  ||  button->buttonID <=10  ||  button->buttonID == BUTTON_BACKTOTITLE) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		//��������
		PlaySound(L"��Դ\\bgm\\AIR - ��Ӱ.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
	}
	else if (stageID == STAGE_FAILED  ||  stageID == STAGE_SUCCESS)
	{
		currentStage->background = bmp_Background_Failed;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = false;
		if (theHero != NULL) 
		{
			delete theHero;
			theHero = NULL;
		}
		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID / 1000 == 3  &&  button->buttonID != BUTTON_CONTINUE) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_PAUSE)
	{
		currentStage->background = bmp_Background_Pause;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = false;
		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID / 1000 == 3) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}

	//ˢ����ʾ
	InvalidateRect(hWnd, NULL, FALSE);
}

// ˢ������״̬����
void UpdateHero(HWND hWnd)
{
	if (theHero != NULL && currentStage->timerOn == true) 
	{
		Hero hero_pre = *theHero; 
		//�����Ƿ��ڵ���״̬��������
		int v_max = 0;
		if (keySpaceDown) v_max = HERO_LOW_MAXSPEED;
		else v_max = HERO_MAXSPEED;
		//y�����ٶ�
		if (keyUpDown && !keyDownDown && theHero->vy > -1 * v_max)
			theHero->vy -= HERO_ACCELERATION;
		else if (!keyUpDown && keyDownDown && theHero->vy < v_max)
			theHero->vy += HERO_ACCELERATION;
		else if (theHero->vy > 0)theHero->vy -= HERO_ACCELERATION;
		else if (theHero->vy < 0)theHero->vy += HERO_ACCELERATION;
		//x�����ٶ�
		if (keyLeftDown && !keyRightDown && theHero->vx > -1 * v_max)
			theHero->vx -= HERO_ACCELERATION;
		else if (!keyLeftDown && keyRightDown && theHero->vx < v_max)
			theHero->vx += HERO_ACCELERATION;
		else if (theHero->vx > 0)theHero->vx -= HERO_ACCELERATION;
		else if (theHero->vx < 0)theHero->vx += HERO_ACCELERATION;

		theHero->x += (int)(theHero->vx);
		theHero->y += (int)(theHero->vy);
		
		//�ж��Ƿ񳬽�(����ֵ����Ȼ������Ч��)
		if (currentStage->stageID == STAGE_1) {
			if (theHero->x<0) 
			{ theHero->x=4; theHero->vx=-0.7*theHero->vx; }
		}
		else if (theHero->x < -400) 
			{ theHero->x=-400; theHero->vx=-0.7*theHero->vx; }
		if (currentStage->stageID == STAGE_1){
			if (theHero->x>WINDOW_WIDTH-HERO_SIZE_X-15) 
			{ theHero->x=WINDOW_WIDTH-HERO_SIZE_X-19; theHero->vx=-0.7*theHero->vx; }
		}
		else if (theHero->x>WINDOW_WIDTH+400-HERO_SIZE_X-15) 
			{ theHero->x=WINDOW_WIDTH+400-HERO_SIZE_X-19; theHero->vx=-0.7*theHero->vx; }
		if (theHero->y<14+HERO_SIZE_Y) 
			{ theHero->y=15+HERO_SIZE_Y; theHero->vy=-0.7*theHero->vy; }
		if (theHero->y>WINDOW_HEIGHT-HERO_SIZE_Y-31) 
			{ theHero->y=WINDOW_HEIGHT-HERO_SIZE_Y-35; theHero->vy=-0.7*theHero->vy; }

		//�������ĵ�λ��
		int centerX = theHero->x + HERO_SIZE_X / 2;
		int centerY = theHero->y + HERO_SIZE_Y / 2;
		
		//���ǳ���
		double dirX = mouseX - centerX;
		double dirY = mouseY - centerY;
		if (currentStage->stageID != STAGE_1) {
			dirX += map_move_x;
		}
		theHero->frame = GetHeroFrame(dirX, dirY);		
		
		//boss��������ײ
		if ((pow((centerX- Boss->x - BOSS_SIZE/2.0), 2)+pow((centerY - Boss->y - BOSS_SIZE/2.0), 2))<pow(HERO_SIZE_X/2.0+BOSS_SIZE/2.0, 2) && Boss->skill == BOSS_SKILL1
			||  (pow((centerX- Boss->x - BOSS2_SIZE*0.6/2.0), 2)+pow((centerY - Boss->y - BOSS2_SIZE*0.6/2.0), 2))<pow(HERO_SIZE_X/2.0+BOSS2_SIZE*0.6/2.0, 2) && Boss->skill == BOSS_SKILL2)
		{
			//��ײ��⣬ǰ�ľ�Ϊ��������һ�����Ϊ����
			if (theHero->x <= Boss->x -HERO_SIZE_X + 5) 
			{
				theHero->x += theHero->x - Boss->x + HERO_SIZE_X-5;
				theHero->vx = -theHero->vx *0.7;
			}
			else if (theHero->x >= Boss->x+BOSS_SIZE -5) 
			{
				theHero->x += theHero->x - Boss->x - BOSS_SIZE+5;
				theHero->vx = -theHero->vx *0.7;
			}
			else if (theHero->y <= Boss->y -HERO_SIZE_Y+ 5) 
			{
				theHero->y += theHero->y - Boss->y + HERO_SIZE_Y-5;
				theHero->vy = -theHero->vy *0.7;
			}
			else if (theHero->y >= Boss->y+BOSS_SIZE -5) 
			{
				theHero->y += theHero->y - Boss->y - BOSS_SIZE+5;
				theHero->vy = -theHero->vy *0.7;
			}
			else 
			{
				theHero->x = hero_pre.x; 
				theHero->y = hero_pre.y; 
				theHero->vy = -theHero->vy *0.7;
				theHero->vx = -theHero->vx *0.7;
			}
		}
		for (int i=0; i<Boss_Bonus.size(); i++)
			{
				if ((pow((Boss_Bonus[i]->x + BOSS_SIZE/2 - centerX), 2)+pow((Boss_Bonus[i]->y + BOSS_SIZE/2- centerY), 2)) <= pow(BOSS_SIZE/2+HERO_SIZE_X/2 - 5, 2))
				{
					//��ײ��⣬ǰ�ľ�Ϊ��������һ�����Ϊ����
					if (theHero->x <= Boss_Bonus[i]->x -HERO_SIZE_X + 5) 
					{
						theHero->x += theHero->x - Boss_Bonus[i]->x + HERO_SIZE_X-5;
						theHero->vx = -theHero->vx *0.7;
					}
					else if (theHero->x >= Boss_Bonus[i]->x+BOSS_SIZE -5) 
					{
						theHero->x += theHero->x - Boss_Bonus[i]->x - BOSS_SIZE+5;
						theHero->vx = -theHero->vx *0.7;
					}
					else if (theHero->y <= Boss_Bonus[i]->y -HERO_SIZE_Y+ 5) 
					{
						theHero->y += theHero->y - Boss_Bonus[i]->y + HERO_SIZE_Y-5;
						theHero->vy = -theHero->vy *0.7;
					}
					else if (theHero->y >= Boss_Bonus[i]->y+BOSS_SIZE -5) 
					{
						theHero->y += theHero->y - Boss_Bonus[i]->y - BOSS_SIZE+5;
						theHero->vy = -theHero->vy *0.7;
					}
					else 
					{
						theHero->x = hero_pre.x; 
						theHero->y = hero_pre.y; 
						theHero->vy = -theHero->vy *0.7;
						theHero->vx = -theHero->vx *0.7;
					}
				}
			}

		//С����������ײ
		for (int j=0; j<Enemy.size(); j++)
			{
				Enemy_Condition* enemy = Enemy[j];
				if (theHero->skill == HERO_SKILL_ATTACK  &&  Hero_Skill_Using
					&&  (pow((centerX- enemy->x - ENEMY_SIZE/2), 2)+pow((centerY - enemy->y - ENEMY_SIZE/2), 2)) <= pow(ENEMY_SIZE/2.0+HERO_ATTACK_WITDH/2.0, 2))
				{
					enemy->health = 0;
				}
				if ((pow((centerX- enemy->x - ENEMY_SIZE/2), 2)+pow((centerY - enemy->y - ENEMY_SIZE/2), 2)) <= pow(ENEMY_SIZE/2.0+HERO_SIZE_X/2.0, 2))
				{
					//��ײ��⣬ǰ�ľ�Ϊ��������һ�����Ϊ����
					if (theHero->x <= enemy->x -HERO_SIZE_X +5) 
					{
						theHero->x += theHero->x - enemy->x + HERO_SIZE_X-5;
						theHero->vx = -theHero->vx *0.7;
					}
					else if (theHero->x >= enemy->x+BOSS_SIZE -5) 
					{
						theHero->x += theHero->x - enemy->x - BOSS_SIZE +5;
						theHero->vx = -theHero->vx *0.7;
					}
					else if (theHero->y <= enemy->y -HERO_SIZE_Y + 5) 
					{
						theHero->y += theHero->y - enemy->y + HERO_SIZE_Y-5;
						theHero->vy = -theHero->vy *0.7;
					}
					else if (theHero->y >= enemy->y+BOSS_SIZE -5) 
					{
						theHero->y = hero_pre.y; 
						theHero->vy = -theHero->vy *0.7;
					}
					else 
					{
						theHero->x = hero_pre.x; 
						theHero->y = hero_pre.y; 
						theHero->vy = -theHero->vy *0.7;
						theHero->vx = -theHero->vx *0.7;
					}

					break;
				}
			}

		//ʹ�ü���
		if (Hero_Skill_Using) 
			{
				if (theHero->skill == HERO_SKILL_ATTACK)
				{
					if (!Hero_Skill_Attack && (pow((centerX- Boss->x -BOSS_SIZE/2.0), 2)+pow((centerY- Boss->y -BOSS_SIZE/2.0), 2))<pow(HERO_ATTACK_WITDH/2.0+BOSS_SIZE/2.0, 2))
					{
						Boss->health--;
						Hero_Skill_Attack = true;
					}
				}
			}
		
		//������ײ
		for(int i=0;i<MapTrap.size();i++)
		{
			Trap* trap = MapTrap[i];
			if (theHero->skill == HERO_SKILL_ATTACK && Hero_Skill_Using && trap->trapID == TRAP_2
				&& (pow((centerX- trap->x -TRAP_WIDTH/2.0), 2)+pow((centerY- trap->y -TRAP_WIDTH/2.0), 2))<pow(HERO_ATTACK_HEIGHT/2.0+TRAP_WIDTH/2.0, 2))
			{
				trap->visible == false;
				trap_exist[ TRAP_2 - 101 ] = false;
				int k = rand()%2;
				Enemy_Condition* enemy = NULL;
					if (k == 0) enemy=CreateEnemy(bmp_Enemy1, trap->x+TRAP_WIDTH/2.0, trap->y+TRAP_WIDTH/2.0, theHero->x + HERO_SIZE_X - trap->x - ENEMY_SIZE/2.0, 
						theHero->y + HERO_SIZE_Y - trap->y - ENEMY_SIZE/2.0, ENEMY_SKILL1, hWnd, ENEMY_ID1);
					else enemy=CreateEnemy(bmp_Enemy2, trap->x+TRAP_WIDTH/2.0, trap->y+TRAP_WIDTH/2.0, theHero->x + HERO_SIZE_X - trap->x - ENEMY_SIZE/2.0, 
						theHero->y + HERO_SIZE_Y - trap->y - ENEMY_SIZE/2.0, ENEMY_SKILL2, hWnd, ENEMY_ID1);
				//ש����ײ
				for(int k=0;k<Brick.size();k++)
				{
					Trick* brick = Brick[k];
					if (!brick->visible) continue;
					if (pow(enemy->x + BOSS_SIZE/2 - enemy->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
						<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +5,2) ) 
					{
						if (enemy->ID == ENEMY_ID1) num_enemy--;
						Enemy_Condition* enemy2 = enemy;
						enemy = NULL;
						delete(enemy2);
						break;
					}
				}
				if (enemy != NULL) Enemy.push_back(enemy);
				MapTrap.erase(MapTrap.begin()+i);
				continue;
			}
			if (!trap->visible) continue;
			if ((pow((centerX- trap->x -TRAP_WIDTH/2.0), 2)+pow((centerY- trap->y -TRAP_WIDTH/2.0), 2))<pow(HERO_SIZE_X/2.0+TRAP_WIDTH/2.0, 2))
			{
				if (trap->trapID == TRAP_1 && !trap->inn) 
				{
					if (!theHero->protect) 
					{
						theHero->health -- ;	
						Protect_Hero(hWnd);
					}
					trap->inn = true;
				}
				else if (trap->trapID == TRAP_2) KillTimer(hWnd, HERO_BULLET_TIMER);
				else if (trap->trapID == TRAP_3) {
					theHero->vx = theHero->vx / abs(theHero->vx) * 2;
					theHero->vy = theHero->vy / abs(theHero->vy) * 2;
				}
			}
			else if (trap->trapID == TRAP_1 && trap->inn) trap->inn = false;
		}

		//ש����ײ
		for(int i=0;i<Brick.size();i++)
			{
				Trick* brick = Brick[i];
				if (!brick->visible) continue;
				if (pow(centerX - brick->x - BRICK_SIZE/2, 2)+pow(centerY - brick->y - BRICK_SIZE/2, 2) <= pow(HERO_SIZE_X/2 + BRICK_SIZE/2 - 5,2) ) 
				{
					if (brick->brickID ==BRICK_KIND3  &&  theHero->protect == false) 
					{
						theHero->health --;
						Protect_Hero(hWnd);
					}
					//��ײ��⣬ǰ�ľ�Ϊ��������һ�����Ϊ����
					if (theHero->x <= brick->x -HERO_SIZE_X +5) 
					{
						theHero->x += theHero->x - brick->x + HERO_SIZE_X-5;
						theHero->vx = -theHero->vx *0.7;
					}
					else if (theHero->x >= brick->x+BRICK_SIZE -5) 
					{
						theHero->x += theHero->x - brick->x - BRICK_SIZE +5;
						theHero->vx = -theHero->vx *0.7;
					}
					else if (theHero->y <= brick->y -HERO_SIZE_Y + 5) 
					{
						theHero->y += theHero->y - brick->y + HERO_SIZE_Y-5;
						theHero->vy = -theHero->vy *0.7;
					}
					else if (theHero->y >= brick->y+BRICK_SIZE -5) 
					{
						theHero->y = hero_pre.y; 
						theHero->vy = -theHero->vy *0.7;
					}
					else 
					{
						theHero->x = hero_pre.x; 
						theHero->y = hero_pre.y; 
						theHero->vy = -theHero->vy *0.7;
						theHero->vx = -theHero->vx *0.7;
					}
				}
		}
		
		int tmp = map_move_x_plus;
		map_move_x_plus += theHero->x - hero_pre.x; 
		if (abs(map_move_x_plus) <= 400) map_move_x = map_move_x_plus;
		else if (map_move_x_plus < -400) map_move_x = -400;
		else if (map_move_x_plus > 400) map_move_x = 400;

		//�жϹؿ��Ƿ�ʧ��
		if (theHero->health <= 0)     
		{ 
			//�˴��Ӳ��䶯��
			InvalidateRect(hWnd, NULL, FALSE);
			currentStage->timerOn = false;	 
			preStage = *currentStage;
			InitStage(hWnd, STAGE_FAILED);
		}									
				
		InvalidateRect(hWnd, NULL, FALSE);
	}
		
}

//�������˺��޵�
void Protect_Hero(HWND hWnd)
{
	theHero->protect = true;
	KillTimer(hWnd, TIMER_HERO_UP);
	if (theHero->skill == HERO_SKILL_STRONG  && Hero_Skill_Ready)
	{
		SetTimer(hWnd, TIMER_PROTECT, TIMER_PROTECT_ELAPSE_SKILL1, NULL);
		Hero_Skill_Ready = false;
		SetTimer(hWnd, TIMER_HERO_SKILL_CD_ID, TIMER_HERO_SKILL1_CD, NULL);
	}
	else if (theHero->skill == HERO_SKILL_LIGHTMOVE  && Hero_Skill_Ready && Hero_Skill_Using)
	{
		SetTimer(hWnd, TIMER_PROTECT, TIMER_PROTECT_ELAPSE_SKILL4, NULL);
		Hero_Skill_Ready = false;
		SetTimer(hWnd, TIMER_HERO_SKILL_CD_ID, TIMER_HERO_SKILL4_CD, NULL);
	}
	else SetTimer(hWnd, TIMER_PROTECT, TIMER_PROTECT_ELAPSE, NULL);
	InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
}

// �������ǵĵ�ǰ֡��,Ϊ��ȷ�����õ�����һ֡ͼ��
int GetHeroFrame(double dirX, double dirY) 
{
	double dirLen = sqrt(dirX * dirX + dirY * dirY);
	if (dirLen == 0)return 0;
	double cos = -dirY / dirLen;
	double arc = acos(cos);
	if (dirX < 0)arc = 2 * PI - arc;

	int frame = (int)((arc + PI / HERO_FRAME_NUMBER) / (2 * PI / HERO_FRAME_NUMBER));
	if (frame == HERO_FRAME_NUMBER)frame = 0;
	return frame;
}

//boss״̬����
void UpdateBoss(HWND hWnd)
{
	if (Boss != NULL && currentStage->timerOn == true)
	{
	if (Boss->skill == BOSS_SKILL1)
	{
		Boss_Condition boss_pre = *Boss;
		//׷��
		////�������ĵ�λ��
		int centerX = theHero->x + HERO_SIZE_X / 2;
		int centerY = theHero->y + HERO_SIZE_Y / 2;
		//׷��
		if ((pow((centerX- Boss->x -BOSS_SIZE/2.0), 2)+pow((centerY- Boss->y -BOSS_SIZE/2.0), 2)) >= pow(HERO_SIZE_X/2.0+BOSS_SIZE/2.0+5, 2))
		{
			//����boss�ƶ�����
			Boss->direction_x = abs(Boss->x - theHero->x);
			Boss->direction_y = abs(Boss->y - theHero->y);
			if (theHero->x - Boss->x > 8) Boss->x += (int)(Boss->v * Boss->direction_x / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
			else if (theHero->x - Boss->x < -8)Boss->x -= (int)(Boss->v * Boss->direction_x / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
			if (theHero->y - Boss->y > 8) Boss->y += (int)(Boss->v * Boss->direction_y / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
			else if (theHero->y - Boss->y < -8)Boss->y -= (int)(Boss->v * Boss->direction_y / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
		}
		else
		{
			Boss->x = boss_pre.x;
			Boss->y = boss_pre.y;		
		}
		//ש����ײ
		for(int i=0;i<Brick.size();i++)
		{
			Trick* brick = Brick[i];
			if (!brick->visible) continue;
			if (pow(Boss->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(Boss->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
				<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 - 2,2) ) 
			{				
				if (pow(Boss->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(Boss->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
					<= pow(BOSS_SIZE/2 + BRICK_SIZE/2-14,2) ) 
				{
					Boss->x = 650;
					Boss->y = 200;
					continue;	
				}
				srand(time(NULL));
				do
				{
					int seed=pow(-1,rand()%10);
					Boss->x = boss_pre.x + seed*3;
					seed=pow(-1,rand()%10);
					Boss->y = boss_pre.y + seed*4;	
				}while (pow(Boss->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(Boss->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
				<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +1,2));
			}
		}

		//boss�̲�С��
		for (int j=0; j<Enemy.size();)
			{
				Enemy_Condition* enemy = Enemy[j];
				if ((pow((enemy->x + ENEMY_SIZE/2- Boss->x - BOSS_SIZE/2), 2)+pow((enemy->y + ENEMY_SIZE/2 - Boss->y - BOSS_SIZE/2), 2)) <= pow(BOSS_SIZE/2+ENEMY_SIZE/2 - 20, 2))
				{
					Boss->health += enemy->health; 
					if (enemy->ID == ENEMY_ID1)
						num_enemy--;
					Enemy.erase(Enemy.begin()+j);
					continue;
				} 
				j++;
			}

		if (currentStage->stageID == STAGE_1) {
			if (Boss->x < 0 || Boss->x > WINDOW_WIDTH - BOSS_SIZE) Boss->x = 650;
			if (Boss->y < 50 || Boss->y > WINDOW_HEIGHT - BOSS_SIZE) Boss->y = 200;
		}
		else {
			if (Boss->x < -400+10 || Boss->x > WINDOW_WIDTH + 400 - BOSS_SIZE) Boss->x = 650;
			if (Boss->y < 50 || Boss->y > WINDOW_HEIGHT - BOSS_SIZE) Boss->y = 200;
		}

		

		//����,�˴����ж���,ע�⣬����protectbossʱ���Ѫ   
		if (Boss->health == BOSS_HEALTH1) 
		{
			Protect_Boss(hWnd);
			handy_protect_boss = true;
			SetTimer(hWnd, TIMER_BOSS1, TIMER_BOSS1_ELAPSE2, NULL);
			Boss->health--;
		}
		else if (Boss->health == BOSS_HEALTH2) 
		{
			Protect_Boss(hWnd);
			handy_protect_boss = true;
			SetTimer(hWnd, TIMER_BOSS1, TIMER_BOSS1_ELAPSE3, NULL);
			Boss->health--;
		}
		if (num_enemy == 0 && !handy_protect_boss) Boss->protect = false;		//�������
		if (num_enemy > 0) Boss->protect = true;

		//�жϹؿ��Ƿ�ɹ�
		if (Boss->health <= 0)     
		{ 
			//�˴���Ӷ���
			InvalidateRect(hWnd, NULL, FALSE);
			currentStage->timerOn = false;	 
			preStage = *currentStage;
			InitStage(hWnd, STAGE_SUCCESS);
		}		
	}
	else if (Boss->skill == BOSS_SKILL2)
	{
		Boss_Condition boss_pre = *Boss;
		//׷��
		////�������ĵ�λ��
		int centerX = theHero->x + HERO_SIZE_X / 2;
		int centerY = theHero->y + HERO_SIZE_Y / 2;
		//׷��
		if ((pow((centerX- Boss->x -BOSS2_SIZE*0.6/2.0), 2)+pow((centerY- Boss->y -BOSS2_SIZE*0.6/2.0), 2)) >= pow(HERO_SIZE_X/2.0+BOSS2_SIZE*0.6/2.0+5, 2))
		{
			//����boss�ƶ�����
			Boss->direction_x = abs(Boss->x - theHero->x);
			Boss->direction_y = abs(Boss->y - theHero->y);
			if (theHero->x - Boss->x > 8) Boss->x += (int)(Boss->v * Boss->direction_x / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
			else if (theHero->x - Boss->x < -8)Boss->x -= (int)(Boss->v * Boss->direction_x / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
			if (theHero->y - Boss->y > 8) Boss->y += (int)(Boss->v * Boss->direction_y / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
			else if (theHero->y - Boss->y < -8)Boss->y -= (int)(Boss->v * Boss->direction_y / sqrt(pow(Boss->direction_x/1.0, 2) + pow(Boss->direction_y/1.0, 2)));
		}
		else
		{
			Boss->x = boss_pre.x;
			Boss->y = boss_pre.y;		
		}
		//ש����ײ
		for(int i=0;i<Brick.size();i++)
		{
			Trick* brick = Brick[i];
			if (!brick->visible) continue;
			if (pow(Boss->x + BOSS2_SIZE*0.6/2 - brick->x - BRICK_SIZE/2, 2)+pow(Boss->y + BOSS2_SIZE*0.6/2- brick->y - BRICK_SIZE/2, 2)
				<= pow(BOSS2_SIZE*0.6/2 + BRICK_SIZE/2,2) ) 
			{
				if (pow(Boss->x + BOSS2_SIZE*0.6/2 - brick->x - BRICK_SIZE/2, 2)+pow(Boss->y + BOSS2_SIZE*0.6/2- brick->y - BRICK_SIZE/2, 2)
					<= pow(BOSS2_SIZE*0.6/2 + BRICK_SIZE/2-6,2) ) 
				{
					Boss->x = Boss_Bonus[0]->x + BOSS_SIZE/2 - BOSS2_SIZE*0.6/2;
					Boss->y = Boss_Bonus[0]->y;
					continue;	
				}
				srand(time(NULL));
				do
				{
					int seed=pow(-1,rand()%10);
					Boss->x = boss_pre.x + seed*6;
					seed=pow(-1,rand()%10);
					Boss->y = boss_pre.y + seed*6;	
				}while (pow(Boss->x + BOSS2_SIZE*0.6/2 - brick->x - BRICK_SIZE/2, 2)+pow(Boss->y + BOSS2_SIZE*0.6/2- brick->y - BRICK_SIZE/2, 2)
				<= pow(BOSS2_SIZE*0.6/2 + BRICK_SIZE/2 +2,2));
			}
		}

		//boss�̲�С��
		for (int j=0; j<Enemy.size();)
			{
				Enemy_Condition* enemy = Enemy[j];
				if ((pow((enemy->x + ENEMY_SIZE/2- Boss->x - BOSS2_SIZE*0.6/2), 2)+pow((enemy->y + ENEMY_SIZE/2 - Boss->y - BOSS2_SIZE*0.6/2), 2)) <= pow(BOSS2_SIZE*0.6/2+ENEMY_SIZE/2 - 20, 2))
				{
					Boss->health += enemy->health; 
					if (enemy->ID == ENEMY_ID1)
						num_enemy--;
					Enemy.erase(Enemy.begin()+j);
					continue;
				} 
				j++;
			}

		if (currentStage->stageID == STAGE_1) {
			if (Boss->x < 0 || Boss->x > WINDOW_WIDTH - BOSS2_SIZE*0.6) Boss->x = 400;
			if (Boss->y < 50 || Boss->y > WINDOW_HEIGHT - BOSS2_SIZE*0.6) Boss->y = 300;
		}
		else {
			if (Boss->x < -400+10 || Boss->x > WINDOW_WIDTH + 400 - BOSS2_SIZE*0.6) Boss->x = 400;
			if (Boss->y < 50 || Boss->y > WINDOW_HEIGHT - BOSS2_SIZE*0.6) Boss->y = 300;
		}

		if (num_enemy == 0 && !handy_protect_boss) Boss->protect = false;		//�������
		if (num_enemy > 0) Boss->protect = true;

		if (Boss->health <= 30 && num_bonus>4) {
			Boss_Bonus.pop_back();
			num_bonus--;
			handy_protect_boss = true;
			Protect_Boss(hWnd);
		}
		if (Boss->health <= 10 && num_bonus>3) {
			Boss_Bonus.pop_back();
			num_bonus--;
			handy_protect_boss = true;
			Protect_Boss(hWnd);
		}

		//�жϹؿ��Ƿ�ɹ�
		if (Boss->health <= 0)     
		{ 
			//�˴���Ӷ���
			InvalidateRect(hWnd, NULL, FALSE);
			currentStage->timerOn = false;	 
			preStage = *currentStage;
			InitStage(hWnd, STAGE_SUCCESS);
		}		
	}
		InvalidateRect(hWnd, NULL, FALSE);
	}
}

//boss�޵�
void Protect_Boss(HWND hWnd)
{
	Boss->protect = true;
	if (currentStage->stageID == STAGE_1) SetTimer(hWnd, TIMER_BOSS_PROTECT, TIMER_BOSS_PROTECT_DESTROY_ELAPSE, NULL);
	else SetTimer(hWnd, TIMER_BOSS_PROTECT, TIMER_BOSS2_PROTECT_DESTROY_ELAPSE, NULL);
	InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
}
//boss�޵���ʱʧЧ
void Protect_Boss_Destroy(HWND hWnd)
{
	Boss->protect = false;
	SetTimer(hWnd, TIMER_BOSS_PROTECT, TIMER_BOSS_PROTECT_ELAPSE, NULL);
	InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
}

//С����boss2��β��״̬����
void UpdateEnemy(HWND hWnd)
{
	if (currentStage->timerOn == true)//  &&  Enemy.size() != 0
	{
		////�������ĵ�λ��
		int centerX = theHero->x + HERO_SIZE_X / 2;
		int centerY = theHero->y + HERO_SIZE_Y / 2;
		
		for (int i=0; i<Enemy.size();)
		{			
			Enemy_Condition* enemy = Enemy[i];
			Enemy_Condition enemy_pre = *enemy;
			if (enemy->health <= 0) 
			{
				InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
				if (enemy->ID == ENEMY_ID1) num_enemy--;
				Enemy.erase(Enemy.begin() + i);
				continue;
			}
			bool collision = false;
			bool aimed = false;  //�ж��Ƿ�׷��
			if (enemy->skill == ENEMY_SKILL2 || enemy->health>2) aimed = true;

			if (aimed)
			{//׷��
				if ((pow((centerX- enemy->x -BOSS_SIZE/2.0), 2)+pow((centerY- enemy->y -BOSS_SIZE/2.0), 2)) >= pow(HERO_SIZE_X/2.0+BOSS_SIZE/2.0+5, 2))
				{
					//����enemy�ƶ�����
					enemy->direction_x = abs(enemy->x - theHero->x);
					enemy->direction_y = abs(enemy->y - theHero->y);
					if (theHero->x - enemy->x > 8) enemy->x += (int)(enemy->v * enemy->direction_x / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
					else if (theHero->x - enemy->x < -8)enemy->x -= (int)(enemy->v * enemy->direction_x / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
					if (theHero->y - enemy->y > 8) enemy->y += (int)(enemy->v * enemy->direction_y / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
					else if (theHero->y - enemy->y < -8)enemy->y -= (int)(enemy->v * enemy->direction_y / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
				}
				else
				{
					enemy->x = enemy_pre.x;
					enemy->y = enemy_pre.y;
				}
			}
			else 
			{//����boss
				if ((pow((centerX- enemy->x -BOSS_SIZE/2.0), 2)+pow((centerY- enemy->y -BOSS_SIZE/2.0), 2)) >= pow(HERO_SIZE_X/2.0+BOSS_SIZE/2.0+20, 2))
				{
					//����enemy�ƶ�����
					enemy->direction_x = abs(enemy->x - Boss->x);
					enemy->direction_y = abs(enemy->y - Boss->y);
					if (Boss->x - enemy->x > 8) enemy->x += (int)(enemy->v * enemy->direction_x / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
					else if (Boss->x - enemy->x < -8)enemy->x -= (int)(enemy->v * enemy->direction_x / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
					if (Boss->y - enemy->y > 8) enemy->y += (int)(enemy->v * enemy->direction_y / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
					else if (Boss->y - enemy->y < -8)enemy->y -= (int)(enemy->v * enemy->direction_y / sqrt(pow(enemy->direction_x/1.0, 2) + pow(enemy->direction_y/1.0, 2)));
				}
				else
				{
					enemy->x = enemy_pre.x;
					enemy->y = enemy_pre.y;
				}
			}
			//ש����ײ
			for(int J=0;J<Brick.size();J++)
			{
				Trick* brick = Brick[J];
				if (!brick->visible) continue;
				if (pow(enemy->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
					<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 - 2,2) ) 
				{
					srand(time(NULL));
					do{
						int seed=pow(-1,rand()%10);
						enemy->x = enemy_pre.x + seed*3;
						seed=pow(-1,rand()%10);
						enemy->y = enemy_pre.y +seed*3;	
					}while (pow(enemy->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
						<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 - 2,2));
				}
			}
			//С�������ں�
			int j=0;
			Enemy_Condition* enemy2;
			for ( j=0; j<i; j++)
			{
				if (j==i) continue;
				enemy2 = Enemy[j];
				if ((pow((enemy2->x- enemy->x), 2)+pow((enemy2->y - enemy->y), 2)) <= pow(BOSS_SIZE/2, 2))
				{
					enemy->health += enemy2->health;
					collision = true;
					break;
				}
			}
			if (collision) {
				InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
				if (enemy2->ID == ENEMY_ID1) num_enemy--;
				Enemy.erase(Enemy.begin()+j);
				continue;
			}
	/*
			if ((pow((enemy->x + ENEMY_SIZE/2- Boss->x - BOSS_SIZE/2), 2)+pow((enemy->y + ENEMY_SIZE/2 - Boss->y - BOSS_SIZE/2), 2)) <= pow(BOSS_SIZE/2+ENEMY_SIZE/2+10, 2))
			{
				enemy->x = enemy_pre.x;
				enemy->y = enemy_pre.y;
			}
	*/
			if (currentStage->stageID == STAGE_1) {
				if (enemy->x < 10 || enemy->x > WINDOW_WIDTH - ENEMY_SIZE - 20)
				{
					enemy->x = enemy_pre.x;
				}			
				if (enemy->y < ENEMY_SIZE || enemy->y > WINDOW_HEIGHT - ENEMY_SIZE -40)
				{
					enemy->y = enemy_pre.y;
				}
			}
			else {
				if (enemy->x < -400+10 || enemy->x > WINDOW_WIDTH +400 - ENEMY_SIZE - 20)
				{
					enemy->x = enemy_pre.x;
				}			
				if (enemy->y < ENEMY_SIZE || enemy->y > WINDOW_HEIGHT - ENEMY_SIZE -40)
				{
					enemy->y = enemy_pre.y;
				}
			}

			i++;
		}

		//boss2β��״̬����
		for (int i=0; i<Boss_Bonus.size(); i++)
		{
			Boss_Bonus[i]->v = Boss->v;
			if (i == 0)
			{
				if ((pow((Boss_Bonus[i]->x + BOSS_SIZE/2 - Boss->x - BOSS2_SIZE*0.6/2), 2)+pow((Boss_Bonus[i]->y + BOSS_SIZE/2- Boss->y - BOSS2_SIZE*0.6/2), 2)) >= pow(BOSS_SIZE/2+BOSS2_SIZE*0.6/2, 2))
				{
					Boss_Bonus[i]->direction_x = abs(Boss_Bonus[i]->x - Boss->x);
					Boss_Bonus[i]->direction_y = abs(Boss_Bonus[i]->y - Boss->y);
					if (Boss->x - Boss_Bonus[i]->x > 8) Boss_Bonus[i]->x += (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_x / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
					else if (Boss->x - Boss_Bonus[i]->x < -8)Boss_Bonus[i]->x -= (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_x / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
					if (Boss->y - Boss_Bonus[i]->y > 8) Boss_Bonus[i]->y += (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_y / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
					else if (Boss->y - Boss_Bonus[i]->y < -8) Boss_Bonus[i]->y -= (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_y / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
				}
			}
			else
			{
				if ((pow((Boss_Bonus[i]->x- Boss_Bonus[i-1]->x), 2)+pow((Boss_Bonus[i]->y- Boss_Bonus[i-1]->y), 2)) >= pow(BOSS_SIZE, 2))
				{
					Boss_Bonus[i]->direction_x = abs(Boss_Bonus[i]->x - Boss_Bonus[i-1]->x);
					Boss_Bonus[i]->direction_y = abs(Boss_Bonus[i]->y - Boss_Bonus[i-1]->y);
					if (Boss_Bonus[i-1]->x - Boss_Bonus[i]->x > 8) Boss_Bonus[i]->x += (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_x / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
					else if (Boss_Bonus[i-1]->x - Boss_Bonus[i]->x < -8)Boss_Bonus[i]->x -= (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_x / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
					if (Boss_Bonus[i-1]->y - Boss_Bonus[i]->y > 8) Boss_Bonus[i]->y += (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_y / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
					else if (Boss_Bonus[i-1]->y - Boss_Bonus[i]->y < -8) Boss_Bonus[i]->y -= (int)(Boss_Bonus[i]->v * Boss_Bonus[i]->direction_y / sqrt(pow(Boss_Bonus[i]->direction_x/1.0, 2) + pow(Boss_Bonus[i]->direction_y/1.0, 2)));
				}
			}
			for (int j=0; j<Enemy.size();)
			{
				Enemy_Condition* enemy = Enemy[j];
				if ((pow((enemy->x + ENEMY_SIZE/2- Boss_Bonus[i]->x - BOSS_SIZE/2), 2)+pow((enemy->y + ENEMY_SIZE/2 - Boss_Bonus[i]->y - BOSS_SIZE/2), 2)) <= pow(BOSS_SIZE/2+ENEMY_SIZE/2 - 20, 2))
				{
					Boss->health += enemy->health; 
					if (enemy->ID == ENEMY_ID1)
						num_enemy--;
					Enemy.erase(Enemy.begin()+j);
					continue;
				} 
				j++;
			}
		}

		InvalidateRect(hWnd, NULL, FALSE);
	}
}


//BOSS_AI����
void Send_Bullet(int kind, HWND hWnd)
{
	switch (kind)
	{
		case BOSS_AIMED:
			{
				for (int i=1;i<=4;i++)
				{
					int seed=rand()%20;
					int dx=theHero->x + HERO_SIZE_X / 2- Boss->x -BOSS_SIZE/2.0;
					int	dy=theHero->y + HERO_SIZE_Y / 2- Boss->y -BOSS_SIZE/2.0;
					Bullet_Normal* boss_bullet = nullptr;					
					if (seed%11 != 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx + (int)(pow(-1,rand()%10))*rand()%40, dy + (int)(pow(-1,rand()%10))*rand()%40, BOSS_BULLET_ID);
					else boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx + (int)(pow(-1,rand()%10))*rand()%40, dy + (int)(pow(-1,rand()%10))*rand()%40, BOSS_BULLET_ID);
					boss_bullet->v += rand()%4;
					Bullet_normal.push_back(boss_bullet);     //������ӵ�
				}

				if (Enemy.size() > 0)
				{
					for (int i=0; i<Enemy.size(); i++)
					{			
						Enemy_Condition* enemy = Enemy[i];
						if (enemy->skill == ENEMY_SKILL2)
						{
							for (int j=1;j<=2;j++)
							{
								int seed=rand()%20;	
								int dx=theHero->x + HERO_SIZE_X / 2- enemy->x -BOSS_SIZE/2.0;
								int	dy=theHero->y + HERO_SIZE_Y / 2- enemy->y -BOSS_SIZE/2.0;
								Bullet_Normal* enemy_bullet = nullptr;					
								if (seed%11 != 0) enemy_bullet = CreateEnemyBullet(enemy, bmp_Boss_Bullet1, dx + (int)(pow(-1,rand()%10))*rand()%40, dy + (int)(pow(-1,rand()%10))*rand()%40, BOSS_BULLET_ID);
								else enemy_bullet = CreateEnemyBullet(enemy, bmp_Boss_Bullet2, dx + (int)(pow(-1,rand()%10))*rand()%40, dy + (int)(pow(-1,rand()%10))*rand()%40, BOSS_BULLET_ID);
								enemy_bullet->v += rand()%3;
								Bullet_normal.push_back(enemy_bullet);     //������ӵ�
							}
						}
					}
				}

				break;
			}
		case BOSS_CALLING:
			{
				if (sum_bullet_session%3 == 0) return;
				int seed = rand()%20;
				if (seed % 11==0) 
				{
					if (Enemy.size()-num_enemy >= 4) return;
					int x,y;
					if (currentStage->stageID == STAGE_1) { 
						do {
							 x = (rand()%(WINDOW_WIDTH-ENEMY_SIZE-30))+5;
							 y = (rand()%(WINDOW_HEIGHT-ENEMY_SIZE-100))+60;
						} while ((pow((Boss->x- x), 2)+pow((Boss->y - y), 2)) <= pow(BOSS_SIZE+100, 2)  ||  (pow((theHero->x- x), 2)+pow((theHero->y - y), 2)) <= pow(BOSS_SIZE+100, 2));
					}
					else { 
						do {
							x = (rand()%(WINDOW_WIDTH +400 -ENEMY_SIZE-30))+15 -400;
							y = (rand()%(WINDOW_HEIGHT-ENEMY_SIZE-100))+60;
						} while ((pow((Boss->x- x), 2)+pow((Boss->y - y), 2)) <= pow(BOSS_SIZE+100, 2)  ||  (pow((theHero->x- x), 2)+pow((theHero->y - y), 2)) <= pow(BOSS_SIZE+100, 2));
					}
					Enemy_Condition* enemy=CreateEnemy(bmp_Enemy2, x, y, theHero->x + HERO_SIZE_X - x - ENEMY_SIZE/2.0, 
						theHero->y + HERO_SIZE_Y - y - ENEMY_SIZE/2.0, ENEMY_SKILL2, hWnd, ENEMY_ID2);
					//ש����ײ
					for(int i=0;i<Brick.size();i++)
					{
						Trick* brick = Brick[i];
						if (!brick->visible) continue;
						if (pow(enemy->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
							<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +10,2) ) 
						{
							if (enemy->ID == ENEMY_ID1) num_enemy--;
							Enemy_Condition* enemy2 = enemy;
							enemy = NULL;
							delete(enemy2);
							break;
						}
					}
					if (enemy != NULL) Enemy.push_back(enemy);
						else Boss->health += 2;
				}
				else 
				{
					if (Enemy.size()-num_enemy >= 3) return;
					int x,y;
					if (currentStage->stageID == STAGE_1) { 
						do {
							 x = (rand()%(WINDOW_WIDTH-ENEMY_SIZE-30))+5;
							 y = (rand()%(WINDOW_HEIGHT-ENEMY_SIZE-100))+60;
						} while ((pow((Boss->x- x), 2)+pow((Boss->y - y), 2)) <= pow(BOSS_SIZE+100, 2)  ||  (pow((theHero->x- x), 2)+pow((theHero->y - y), 2)) <= pow(BOSS_SIZE+100, 2));
					}
					else { 
						do {
							x = (rand()%(WINDOW_WIDTH +400 -ENEMY_SIZE-30))+15 -400;
							y = (rand()%(WINDOW_HEIGHT-ENEMY_SIZE-100))+60;
						} while ((pow((Boss->x- x), 2)+pow((Boss->y - y), 2)) <= pow(BOSS_SIZE+100, 2)  ||  (pow((theHero->x- x), 2)+pow((theHero->y - y), 2)) <= pow(BOSS_SIZE+100, 2));
					}
					Enemy_Condition* enemy=CreateEnemy(bmp_Enemy1, x, y, theHero->x + HERO_SIZE_X - x - ENEMY_SIZE/2.0, 
						theHero->y + HERO_SIZE_Y - y - ENEMY_SIZE/2.0, ENEMY_SKILL1, hWnd, ENEMY_ID2);
					//ש����ײ
					for(int i=0;i<Brick.size();i++)
					{
						Trick* brick = Brick[i];
						if (!brick->visible) continue;
						if (pow(enemy->x + BOSS_SIZE/2 - enemy->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
							<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +10,2) ) 
						{
							if (enemy->ID == ENEMY_ID1) num_enemy--;
							Enemy_Condition* enemy2 = enemy;
							enemy = NULL;
							delete(enemy2);
							break;
						}
					}
					if (enemy != NULL) Enemy.push_back(enemy);
						else Boss->health += 2;
				}

				break;
			}
		case BOSS_LINE:
			{
				int dx, dy, seed;
				Bullet_Normal* boss_bullet = nullptr;
				dx = 50;dy = 0;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 50;dy = 50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 0;dy = 50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 0;dy = -50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = -50;dy = -50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = -50;dy = 0;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = -50;dy = 50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 50;dy = -50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	

				break;
			}
		case BOSS_LIGHTMOVE:
			{
				if (sum_bullet_session % 3 == 0) return;
				int seed=rand()%10;
				Boss_Condition boss_pre = *Boss;
				int dx=int(pow(-1,seed))*rand()%200;
				seed=rand()%10;
				int	dy=int(pow(-1,seed))*rand()%150;
				if (theHero->x - Boss->x > 0) Boss->x = (rand() % (theHero->x - Boss->x)) + Boss->x + dx;
				else if (theHero->x - Boss->x < 0) Boss->x = Boss->x - (rand() % (Boss->x - theHero->x) )+ dx;
				if (theHero->y - Boss->y > 0) Boss->y = (rand() % (theHero->y - Boss->y)) + Boss->y +dy;
				else if (theHero->y - Boss->y < 0) Boss->y = Boss->y - (rand() % (Boss->y - theHero->y) )+ dy;
				
				////�������ĵ�λ��
				int centerX = theHero->x + HERO_SIZE_X / 2;
				int centerY = theHero->y + HERO_SIZE_Y / 2;
				if ((pow((centerX- Boss->x -BOSS_SIZE/2.0), 2)+pow((centerY- Boss->y -BOSS_SIZE/2.0), 2)) <= pow(HERO_SIZE_X/2.0+BOSS_SIZE/2.0+5, 2)
					||  Boss->x <= 10  &&  Boss->x >= -10+WINDOW_WIDTH-BOSS_SIZE  ||  Boss->y <= 60  &&  Boss->y >= -10+WINDOW_HEIGHT-BOSS_SIZE)
				{
					Boss->x = boss_pre.x;
					Boss->y = boss_pre.y;
					return;
				}
				for(int i=0;i<Brick.size();i++)
				{
					Trick* brick = Brick[i];
					if (!brick->visible) continue;
					if (pow(Boss->x + BOSS_SIZE/2 - brick->x - BRICK_SIZE/2, 2)+pow(Boss->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
						<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +30,2) ) 
					{
						Boss->x = boss_pre.x;
						Boss->y = boss_pre.y;
						return;
					}
				}

				break;
			}
		case BOSS_RANDOM1:
			{
				int srand(time(NULL));
				for (int i=1;i<=10;i++)
				{
					int seed=rand()%10;
					int dx=int(pow(-1,seed))*rand()%250;
					seed=rand()%10;
					int	dy=int(pow(-1,seed))*rand()%150;
					Bullet_Normal* boss_bullet = nullptr;
					if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, -dx, dy, BOSS_BULLET_ID);
					else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, -dx, dy, BOSS_BULLET_ID);
					boss_bullet->v += rand()%3;
					Bullet_normal.push_back(boss_bullet);     //������ӵ�
				}

				if (Enemy.size() > 0)
				{
					for (int i=0; i<Enemy.size(); i++)
					{			
						Enemy_Condition* enemy = Enemy[i];
						if (enemy->skill == ENEMY_SKILL2)
						{
							for (int j=1;j<=10;j++)
							{
								int seed=rand()%20;	
								int dx=int(pow(-1,seed))*rand()%250;
								seed=rand()%20;	
								int	dy=int(pow(-1,seed))*rand()%150;
								Bullet_Normal* enemy_bullet = nullptr;					
								if (seed%11 != 0) enemy_bullet = CreateEnemyBullet(enemy, bmp_Boss_Bullet1, dx, dy, BOSS_BULLET_ID);
								else enemy_bullet = CreateEnemyBullet(enemy, bmp_Boss_Bullet2, dx, dy, BOSS_BULLET_ID);
								enemy_bullet->v += rand()%3;
								Bullet_normal.push_back(enemy_bullet);     //������ӵ�
							}
						}
					}
				}

				break;
			}
		case BOSS_LINE2:      
			{
				int dx, dy, seed;
				Bullet_Normal* boss_bullet = nullptr;
				dx = 50;dy = 0;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 50;dy = 50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 0;dy = 50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 0;dy = -50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = -50;dy = -50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = -50;dy = 0;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = -50;dy = 50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	
				dx = 50;dy = -50;
				seed=rand()%10;
				if (seed%7 == 0) boss_bullet = CreateBossBullet(bmp_Boss_Bullet2, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);						
				else boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss->x, Boss->y, dx, dy, BOSS_BULLET_ID);
				Bullet_normal.push_back(boss_bullet);     //������ӵ�	

				break;
			}
		case BOSS_AIMBULLET:
			{
				for (int i=0; i<Boss_Bonus.size(); i++)
				{
					Bullet_Normal* boss_bullet = nullptr;										    
					boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss_Bonus[i]->x, Boss_Bonus[i]->y, Boss_Bonus[i]->direction_y, -Boss_Bonus[i]->direction_x, BOSS_BULLET_ID);
					Bullet_normal.push_back(boss_bullet);
					boss_bullet = CreateBossBullet(bmp_Boss_Bullet1, Boss_Bonus[i]->x, Boss_Bonus[i]->y, -Boss_Bonus[i]->direction_y, Boss_Bonus[i]->direction_x, BOSS_BULLET_ID);
					Bullet_normal.push_back(boss_bullet);
				}
				break;
			}
		case BOSS_RUSH:
			{
				Boss->v = BOSS2_MAXV;
				break;
			}
		case BOSS_MOVE:
			{				
				if (Boss->health <=10) Boss->health++;
				Boss->health ++;
				break;
			}
		case BOSS_LINERUSH:
			{
				int dx=theHero->x + HERO_SIZE_X / 2- Boss->x -BOSS2_SIZE*0.6/2.0;
				int	dy=theHero->y + HERO_SIZE_Y / 2- Boss->y -BOSS2_SIZE*0.6/2.0;
				Bullet_Normal* boss_bullet = CreateBossBullet(bmp_Boss_Bullet_Rush, Boss->x, Boss->y, dx, dy, BOSS_BULLET_RUSH_ID);					
				Bullet_normal.push_back(boss_bullet);     //������ӵ�
				
				break;
			}

		default : break;
		}

}

//�ӵ���ײ���
void Bullet_Collision(HWND hWnd)
{
	if (theHero != NULL && Boss != NULL && currentStage->timerOn ==true)
	{
		//���������ӵ�״̬
		int i,j;
		for(i=0;i<Bullet_normal.size();i++)
		{
			Bullet_Normal* bullet = Bullet_normal[i];	
			//�����ӵ�λ��					
			bullet->x += (int)(bullet->v * bullet->direction_x / (sqrt(pow(bullet->direction_x, 2) + pow(bullet->direction_y, 2))+0.01));
			bullet->y += (int)(bullet->v * bullet->direction_y / (sqrt(pow(bullet->direction_x, 2) + pow(bullet->direction_y, 2))+0.01));
		}

		for(i=0;i<Bullet_normal.size();)	
		{
			Bullet_Normal* bullet = Bullet_normal[i];
			if (!bullet->visible) {
				i++;
				continue;
			}

			//�ж��ӵ���ǽ�ڵ���ײ
			if (currentStage->stageID == STAGE_1 && bullet->ID == BOSS_BULLET_RUSH_ID && ( bullet->x <= 0 || bullet->x >= WINDOW_WIDTH-BOSS_BULLET_RUSH_SIZE || bullet->y >= WINDOW_HEIGHT-BOSS_BULLET_RUSH_SIZE || bullet->y <= 40)
				|| currentStage->stageID != STAGE_1  &&  bullet->ID == BOSS_BULLET_RUSH_ID && ( bullet->x <= -400 || bullet->x >= WINDOW_WIDTH+400-BOSS_BULLET_RUSH_SIZE || bullet->y >= WINDOW_HEIGHT-BOSS_BULLET_RUSH_SIZE || bullet->y <= 40))
			{
				Bullet_normal.erase(Bullet_normal.begin()+i);
				continue;
			}
			else{
			if (currentStage->stageID == STAGE_1 && (bullet->x <= 0 || bullet->x >= WINDOW_WIDTH-HERO_BULLET_WIDTH*2)  
				|| currentStage->stageID != STAGE_1  &&  (bullet->x <= -400 || bullet->x >= WINDOW_WIDTH+400-HERO_BULLET_WIDTH*2))
			{
				if (bullet->ID == HERO_BULLET_ID)
				{
					bullet->collision++;
					bullet->direction_x = -bullet->direction_x;
				
					if (bullet->collision >=BULLET_COLLISION_SKILL && theHero->skill == HERO_SKILL_BULLET || bullet->collision >=BULLET_COLLISION && theHero->skill != HERO_SKILL_BULLET
							|| bullet->ID != HERO_BULLET_ID ) 
						Bullet_normal.erase(Bullet_normal.begin()+i);
					else i++;
				}
				else if (bullet->ID == BOSS_BULLET_ID)
				{
					Bullet_normal.erase(Bullet_normal.begin()+i);
				}
				continue;
			}
			if (currentStage->stageID == STAGE_1 && (bullet->y >= WINDOW_HEIGHT-HERO_BULLET_HEIGHT || bullet->y <= 40)
				|| currentStage->stageID != STAGE_1  &&  (bullet->y >= WINDOW_HEIGHT-HERO_BULLET_HEIGHT || bullet->y <= 40))
			{
				if (bullet->ID == HERO_BULLET_ID)
				{
					bullet->collision ++;
					bullet->direction_y = -bullet->direction_y;
				
					if (bullet->collision >=BULLET_COLLISION_SKILL && theHero->skill == HERO_SKILL_BULLET || bullet->collision >=BULLET_COLLISION && theHero->skill != HERO_SKILL_BULLET
							|| bullet->ID != HERO_BULLET_ID ) 
						Bullet_normal.erase(Bullet_normal.begin()+i);
					else i++;
				}
				else if (bullet->ID == BOSS_BULLET_ID)
				{
					Bullet_normal.erase(Bullet_normal.begin()+i);
				}
				continue;
			}
			}
			

			//�ж��ӵ��������
			bool collision = false;
			for(j=0;j<i;)
			{				
				if (bullet->ID != HERO_BULLET_ID || bullet->visible != true) break;
				Bullet_Normal* bullet2 = Bullet_normal[j];					
				if (bullet2->ID == HERO_BULLET_ID || bullet2->visible != true) 
				{
					j++;
					continue;					
				}				
				else if (bullet2->ID == BOSS_BULLET_RUSH_ID)
				{
					if (pow(bullet->x - bullet2->x + HERO_BULLET_HEIGHT/2.0 - BOSS_BULLET_RUSH_SIZE/2.0, 2) 
					+ pow(bullet->y - bullet2->y + HERO_BULLET_HEIGHT/2.0 - BOSS_BULLET_RUSH_SIZE/2.0, 2) 
					<= pow(HERO_BULLET_WIDTH/2.0 + BOSS_BULLET_RUSH_SIZE/2.0, 2))  collision = true;
					j++;
					continue;
				}
				else if ( pow(bullet->x - bullet2->x + HERO_BULLET_HEIGHT/2.0 - BOSS_BULLET_SIZE/2.0, 2) 
					+ pow(bullet->y - bullet2->y + HERO_BULLET_HEIGHT/2.0 - BOSS_BULLET_SIZE/2.0, 2) 
					<= pow(HERO_BULLET_WIDTH/2.0 + BOSS_BULLET_SIZE/2.0, 2))
				{					
					if (bullet2->img != bmp_Boss_Bullet2) 
						bullet2->visible = false;
					else if (theHero->skill == HERO_SKILL_BULLET && Hero_Skill_Ready)
					{
						bullet2->visible = false;
						SetTimer(hWnd, TIMER_HERO_SKILL_CD_ID, TIMER_HERO_SKILL3_CD, NULL);
						Hero_Skill_Ready = false;
					}
					j++;
					collision = true;
					continue;
				}
				j++;
			}
			if (collision)
			{
				bullet->visible = false;
				i++;
				continue;
			}

			//���ʹ�ü���
			if (Hero_Skill_Using) 
			{
				if (theHero->skill == HERO_SKILL_ATTACK)
				{
					if (bullet->ID ==BOSS_BULLET_ID  &&  pow(bullet->x - theHero->x + BOSS_BULLET_SIZE/2.0 - HERO_SIZE_X/2.0, 2) + pow(bullet->y - theHero->y + 
					BOSS_BULLET_SIZE/2.0 - HERO_SIZE_Y/2.0, 2) <= pow(BOSS_BULLET_SIZE/2.0 + HERO_ATTACK_WITDH/2.0, 2))
					{
						Bullet_normal.erase(Bullet_normal.begin()+i);	
						continue;
					}
				}
			}

			//�ж������ӵ���boss��С�������ײ
			if (bullet->ID ==HERO_BULLET_ID)
			{
				if (Boss->skill == BOSS_SKILL1  &&  pow(bullet->x - Boss->x + HERO_BULLET_HEIGHT/2.0 - BOSS_SIZE/2.0, 2) + pow(bullet->y - Boss->y + 
				HERO_BULLET_HEIGHT/2.0 - BOSS_SIZE/2.0, 2) <= pow(HERO_BULLET_WIDTH/2.0 + BOSS_SIZE/2.0, 2)
				 ||  Boss->skill == BOSS_SKILL2  &&  pow(bullet->x - Boss->x + HERO_BULLET_HEIGHT/2.0 - BOSS2_SIZE*0.6/2.0, 2) + pow(bullet->y - Boss->y + 
				HERO_BULLET_HEIGHT/2.0 - BOSS2_SIZE*0.6/2.0, 2) <= pow(HERO_BULLET_WIDTH/2.0 + BOSS2_SIZE*0.6/2.0, 2))
				{
					Bullet_normal.erase(Bullet_normal.begin()+i);				
					if (Boss->protect == false) Boss->health --;
					continue;
				}
			}
			if (bullet->ID ==HERO_BULLET_ID) for (int i=0; i<Boss_Bonus.size(); i++)
			{
				if ((pow((-Boss_Bonus[i]->x - BOSS_SIZE/2 + bullet->x + HERO_BULLET_HEIGHT/2), 2)+pow((-Boss_Bonus[i]->y - BOSS_SIZE/2 + bullet->y + HERO_BULLET_HEIGHT/2), 2)) <= pow(BOSS_SIZE/2+HERO_BULLET_WIDTH/2, 2))
				{
					if (Boss->protect == false) Boss->health --;
					bullet->visible = false;
					break;
				}
			}
			if (!bullet->visible) {
				i++;
				continue;
			}
			if (bullet->ID ==HERO_BULLET_ID) for (int j=0; j<Enemy.size(); j++)
			{	
				Enemy_Condition* enemy = Enemy[j];
				if (pow(bullet->x - enemy->x + HERO_BULLET_HEIGHT/2.0 - BOSS_SIZE/2.0, 2) + pow(bullet->y - enemy->y + 
					HERO_BULLET_HEIGHT/2.0 - BOSS_SIZE/2.0, 2) <= pow(HERO_BULLET_WIDTH/2.0 + BOSS_SIZE/2.0, 2))
				{
					bullet->visible = false;			
					if (enemy->protect == false)
					{
						if (theHero->skill == HERO_SKILL_BULLET) enemy->health -=2;
						else enemy->health--;
					}
					break;
				}
			}
			if (!bullet->visible) {
				i++;
				continue;
			}
			//�ж�boss�ӵ������Ǽ����ײ
			if (bullet->ID ==BOSS_BULLET_ID  &&  pow(bullet->x - theHero->x + BOSS_BULLET_SIZE/2.0 - HERO_SIZE_X/2.0, 2) + pow(bullet->y - theHero->y + 
				BOSS_BULLET_SIZE/2.0 - HERO_SIZE_Y/2.0, 2) <= pow(BOSS_BULLET_SIZE/2.0 + HERO_SIZE_X/2.0, 2))
			{
				Bullet_normal.erase(Bullet_normal.begin()+i);				
				if (theHero->protect == false) 
				{
					theHero->health --;
					Protect_Hero(hWnd);
				}
				continue;
			}
			else if (bullet->ID ==BOSS_BULLET_RUSH_ID  &&  pow(bullet->x - theHero->x + BOSS_BULLET_RUSH_SIZE/2.0 - HERO_SIZE_X/2.0, 2) + pow(bullet->y - theHero->y + 
				BOSS_BULLET_RUSH_SIZE/2.0 - HERO_SIZE_Y/2.0, 2) <= pow(BOSS_BULLET_RUSH_SIZE/2.0 + HERO_SIZE_X/2.0, 2))
			{
				if (theHero->protect == false) 
				{
					theHero->health --;
					Protect_Hero(hWnd);
				}
				i++;
				continue;
			}
			if (!bullet->visible) {
				i++;
				continue;
			}

			//�ж��ӵ�������Ĺ�ϵ
			//�����������;����������ƻ�
			for(int j=0;j<MapTrap.size();)
			{
				Trap* trap = MapTrap[j];
				if ((pow((bullet->x + HERO_BULLET_HEIGHT/2.0 - trap->x -TRAP_WIDTH/2.0), 2)+pow((bullet->y + HERO_BULLET_HEIGHT/2.0 - trap->y -TRAP_WIDTH/2.0), 2))
					<pow(HERO_BULLET_WIDTH/2.0+TRAP_WIDTH/2.0, 2))
				{
					if (trap->trapID == TRAP_3 && !bullet->inn) 
					{
						if (bullet->ID == HERO_BULLET_ID  && theHero->skill != HERO_SKILL_BULLET) bullet->v/=3;
						else bullet->v*=2;
						bullet->inn = true;
					}
					else if (trap->trapID == TRAP_2  &&  bullet->ID == HERO_BULLET_ID  ) 
					{
						bullet->visible = false;
						if (theHero->skill == HERO_SKILL_BULLET) trap->health -=3;
						else trap->health--;
						if (trap->health <= 0) 
						{
							trap_exist[ TRAP_2 - 101 ] = false;
							trap->visible = false;
							int k = rand()%2;
							Enemy_Condition* enemy = NULL;
							if (k == 0) enemy=CreateEnemy(bmp_Enemy1, trap->x+TRAP_WIDTH/2.0, trap->y+TRAP_WIDTH/2.0, theHero->x + HERO_SIZE_X - trap->x - ENEMY_SIZE/2.0, 
								theHero->y + HERO_SIZE_Y - trap->y - ENEMY_SIZE/2.0, ENEMY_SKILL1, hWnd, ENEMY_ID1);
							else enemy=CreateEnemy(bmp_Enemy2, trap->x+TRAP_WIDTH/2.0, trap->y+TRAP_WIDTH/2.0, theHero->x + HERO_SIZE_X - trap->x - ENEMY_SIZE/2.0, 
								theHero->y + HERO_SIZE_Y - trap->y - ENEMY_SIZE/2.0, ENEMY_SKILL2, hWnd, ENEMY_ID1);
							MapTrap.erase(MapTrap.begin()+j);
							//ש����ײ
							for(int k=0;k<Brick.size();k++)
							{
								Trick* brick = Brick[k];
								if (!brick->visible) continue;
								if (pow(enemy->x + BOSS_SIZE/2 - enemy->x - BRICK_SIZE/2, 2)+pow(enemy->y + BOSS_SIZE/2- brick->y - BRICK_SIZE/2, 2)
									<= pow(BOSS_SIZE/2 + BRICK_SIZE/2 +5,2) ) 
								{
									if (enemy->ID == ENEMY_ID1) num_enemy--;
									Enemy_Condition* enemy2 = enemy;
									enemy = NULL;
									delete(enemy2);
									break;
								}
							}
							if (enemy != NULL) Enemy.push_back(enemy);
							else Boss->health++;
						}
						break;
					}
				}				
				else if (trap->trapID == TRAP_3 && bullet->inn) 
				{
					if (bullet->ID == HERO_BULLET_ID  &&  theHero->skill != HERO_SKILL_BULLET) bullet->v*=3;
					else bullet->v/=2;
					bullet->inn = false;
				}
				j++;
			}
			if ( !bullet->visible )
			{
				Bullet_normal.erase(Bullet_normal.begin()+i);
				continue;
			}

			//ש����ײ
			for(int j=0;j<Brick.size();)
			{
				Trick* brick = Brick[j];
				if (!brick->visible) continue;
				if (pow(HERO_BULLET_WIDTH/2 + bullet->x - brick->x - BRICK_SIZE/2, 2)+pow(HERO_BULLET_WIDTH/2 + bullet->y - brick->y - BRICK_SIZE/2, 2) 
					<= pow(HERO_BULLET_WIDTH/2 + BRICK_SIZE/2, 2) && bullet->ID!=BOSS_BULLET_RUSH_ID  || pow(BOSS_BULLET_RUSH_SIZE/2 + bullet->x - brick->x - BRICK_SIZE/2, 2)
					+pow(BOSS_BULLET_RUSH_SIZE/2 + bullet->y - brick->y - BRICK_SIZE/2, 2) <= pow(BOSS_BULLET_RUSH_SIZE/2 + BRICK_SIZE/2, 2) && bullet->ID==BOSS_BULLET_RUSH_ID
					&&  brick->brickID != BRICK_KIND1) 
				{
					bullet->collision++;
					if (bullet->collision >=BULLET_COLLISION_SKILL && theHero->skill == HERO_SKILL_BULLET || bullet->collision >=BULLET_COLLISION && theHero->skill != HERO_SKILL_BULLET
					|| bullet->ID != HERO_BULLET_ID && bullet->ID != BOSS_BULLET_RUSH_ID) 
						bullet->visible = false;
					if (bullet->x <= brick->x - HERO_BULLET_WIDTH +5 || bullet->x >= brick->x + BRICK_SIZE -5) bullet->direction_x = -bullet->direction_x;
					if (bullet->y <= brick->y - HERO_BULLET_WIDTH +5 || bullet->y >= brick->y + BRICK_SIZE -5) bullet->direction_y = -bullet->direction_y;
					if (brick->brickID == BRICK_KIND2)
					{
						brick->health--;
						if (brick->health <= 0 || bullet->ID == BOSS_BULLET_RUSH_ID)
						{
							Brick.erase(Brick.begin()+j);
							break;
						}
					}
					break;
				}
				j++;
			}
			i++;
		}
		//˳���������˲��ɼ���������ײ�����ӵ� �� ���壨�⣡����˳���㣡̫���裡�ѣ�QAQ  ��=4Сʱ�޹���
		for(i=0;i<Bullet_normal.size();i++)
		{
			Bullet_Normal* bullet = Bullet_normal[i];	
			if (!bullet->visible) Bullet_normal.erase(Bullet_normal.begin()+i);

		}

		InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ

	}
}

#pragma endregion

#pragma region ��ͼ����Դ���ء�����
//��ʼ��ͼ����
BOOL Game_Load( HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//����ͼ����Դ
	bmp_Background_Start = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(STARTBACKGROUND));
	bmp_Background_Stage1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUND_STAGE1));
	bmp_Background_Stage2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUND_STAGE2));
	bmp_backgroundofstage1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUNDOFSTAGE1));
	bmp_backgroundofstage2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUNDOFSTAGE2));
	bmp_Background_Pause = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUND_FAILED));
	bmp_Help_Background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUND_HELP));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_START));
	//bmp_Title = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(START_TITLE));
	bmp_Hero = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(HERO));
	bmp_HeroHealth = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(HERO_HEALTH));
	bmp_HelpButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(START_HELP));
	bmp_Pause = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(PAUSE));
	bmp_Choice_Background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUND_CHOICE));
	bmp_Chose1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(CHOSESTAGE1));
	bmp_Chose2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(CHOSESTAGE2));
	bmp_ExitButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_EXITGAME));	
	bmp_BulletHero = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(HERO_BULLET));	
	bmp_Trap[0] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(TRAP1));
	bmp_Trap[1] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(TRAP2));
	bmp_Trap[2] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(TRAP3));
	bmp_Boss1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BOSS1));
	bmp_Boss2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BOSS2));
	bmp_Boss2_Plus = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BOSS2_PLUS));
	bmp_Boss_Protect = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BOSS_PROTECT));
	bmp_Hero_Protect = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(HERO_PROTECT));
	bmp_Boss_Bullet1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BOSS_BULLET1));
	bmp_Boss_Bullet2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BOSS_BULLET2));   //�����ƻ�,���ӵ�
	bmp_Boss_Bullet_Rush = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BOSS_RUSH_BULLET));   //�����ƻ�,���ӵ�
	bmp_Skill_Bonus_Ready = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(SKILL_BONUS_READY));   
	for (int i=0;i<=6;i++) bmp_Hero_Attack_Skill[i] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(HERO_ATTACK_SKILL1 + i));
	for (int i=0;i<=7;i++) bmp_Crash[i] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(CRASH_1 + i));
	for (int i=1;i<=4;i++) bmp_Brick[i] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(TRICK_KIND_1 + i - 1));
	bmp_StrongButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_STRONG));   
	bmp_AttackButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_ATTACK));
	bmp_BulletButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_BULLET));
	bmp_MoveButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_MOVE));
	bmp_Enemy1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(ENEMY_1));
	bmp_Enemy2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(ENEMY_2));
	bmp_Background_Failed = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BACKGROUND_FAILED));
	bmp_ContinueButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_CONTINUEGAME));
	bmp_TitleButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_TITLE));
	bmp_RetryButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_RETRYGAME));
	bmp_ChoiceButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(BUTTON_CHOICE));

	ShowCursor(true);	//��ʱ����������꣬��ʱ�򡭡��ٺٺ�

	//��Ӱ�ť
	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 650, 400);
	buttons.push_back(startButton);     //��ʼ��Ϸ
	/*
		Button* titleButton = CreateButton(BUTTON_TITLEGAME, bmp_Title, BUTTON_TITLEGAME_WIDTH, BUTTON_TITLEGAME_HEIGHT, 130, 70);
		buttons.push_back(titleButton);     //��Ϸ����     
	*/
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_HelpButton, BUTTON_HELP_WIDTH, BUTTON_HELP_HEIGHT, 650, 400+BUTTON_STARTGAME_HEIGHT+30);
	buttons.push_back(helpButton);     //��Ϸ����
	Button* pauseButton = CreateButton(BUTTON_PAUSE, bmp_Pause, BUTTON_PAUSE_WIDTH, BUTTON_PAUSE_HEIGHT, 670, 10);
	buttons.push_back(pauseButton);     //��Ϸ��ͣ
	Button* choseButton1 = CreateButton(BUTTON_CHOICESTAGE1, bmp_Chose1, BUTTON_CHOICESTAGE1_WIDTH, BUTTON_CHOICESTAGE1_HEIGHT, 300, 100);
	buttons.push_back(choseButton1);     //ѡ��ؿ�1
	Button* choseButton2 = CreateButton(BUTTON_CHOICESTAGE2, bmp_Chose2, BUTTON_CHOICESTAGE1_WIDTH, BUTTON_CHOICESTAGE1_HEIGHT, 300, 100+BUTTON_CHOICESTAGE1_HEIGHT+50);
	buttons.push_back(choseButton2);     //ѡ��ؿ�2
	Button* exitButton = CreateButton(BUTTON_EXIT, bmp_ExitButton, BUTTON_EXIT_WIDTH, BUTTON_EXIT_HEIGHT, 650, 400+BUTTON_STARTGAME_HEIGHT+30+BUTTON_HELP_HEIGHT+30);
	buttons.push_back(exitButton);     //��Ϸ�˳�
	Button* SkillButton = CreateButton(HERO_SKILL_STRONG, bmp_StrongButton, BUTTON_CHOICESTAGE1_WIDTH, BUTTON_CHOICESTAGE1_HEIGHT, 100, 100);
	buttons.push_back(SkillButton);     //ѡ���ܣ������ӻ�
	SkillButton = CreateButton(HERO_SKILL_ATTACK, bmp_AttackButton, BUTTON_CHOICESTAGE1_WIDTH, BUTTON_CHOICESTAGE1_HEIGHT, 100, 100+BUTTON_CHOICESTAGE1_HEIGHT+50);
	buttons.push_back(SkillButton);     //ѡ���ܣ������
	SkillButton = CreateButton(HERO_SKILL_BULLET, bmp_BulletButton, BUTTON_CHOICESTAGE1_WIDTH, BUTTON_CHOICESTAGE1_HEIGHT, 100, 150+2*BUTTON_CHOICESTAGE1_HEIGHT+50);
	buttons.push_back(SkillButton);     //ѡ���ܣ��ӵ���ʦ
	SkillButton = CreateButton(HERO_SKILL_LIGHTMOVE, bmp_MoveButton, BUTTON_CHOICESTAGE1_WIDTH, BUTTON_CHOICESTAGE1_HEIGHT, 100, 200+3*BUTTON_CHOICESTAGE1_HEIGHT+50);
	buttons.push_back(SkillButton);     //ѡ���ܣ�����ԾǨ
	Button* choiceButton = CreateButton(BUTTON_BACKTOCHOICE, bmp_ChoiceButton, BUTTON_BACKTOCHOICE_WIDTH, BUTTON_BACKTOCHOICE_HEIGHT, 300, 100);
	buttons.push_back(choiceButton);     //����ѡ�ؽ���
	Button* titleButton = CreateButton(BUTTON_BACKTOTITLE, bmp_TitleButton, BUTTON_BACKTOTITLE_WIDTH, BUTTON_BACKTOTITLE_HEIGHT, 670, 10);
	buttons.push_back(titleButton);     //�����������
	Button* continueButton = CreateButton(BUTTON_CONTINUE, bmp_ContinueButton, BUTTON_CONTINUE_WIDTH, BUTTON_CONTINUE_HEIGHT, 300, 200+BUTTON_RETRY_HEIGHT+BUTTON_BACKTOCHOICE_HEIGHT);
	buttons.push_back(continueButton);     //������Ϸ
	Button* retryButton = CreateButton(BUTTON_RETRY, bmp_RetryButton, BUTTON_RETRY_WIDTH, BUTTON_RETRY_HEIGHT, 300, 100+BUTTON_BACKTOCHOICE_HEIGHT+50);
	buttons.push_back(retryButton);     //�ؿ�����

	//��ʼ����ʼ����������ˢ����ʾ�е��ã���ɾ��
	//InitStage(hWnd, STAGE_STARTMENU);

	//��ʼ������ʱ��
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);

	return TRUE;
}

//ͼ����ƺ���
void Game_Paint(HWND hWnd)
{
	if (First_) return;
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);
	
	HPEN hPen = NULL;

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//��ʼ������
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// ���Ʊ���������
	SelectObject(hdc_loadBmp, currentStage->background);
	if (currentStage->stageID != STAGE_2) BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	else {
		BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 400 - map_move_x/6, 100, SRCCOPY);
	}
	// ����������������ݵ�����
	if (currentStage->stageID == STAGE_STARTMENU) 
	{

	}
	else if (currentStage->stageID == STAGE_CHOICE)
	{
		TextOut(hdc_memBuffer, 110, 50, TEXT("ѡ����"), lstrlen(TEXT("ѡ����")));
		TextOut(hdc_memBuffer, 310, 50, TEXT("ѡ��ؿ�,������κ����"), lstrlen(TEXT("ѡ��ؿ�,������κ����")));
	}
	else if (currentStage->stageID == STAGE_FAILED) 
	{
		TextOut(hdc_memBuffer, 310, 50, TEXT("�ؿ�ʧ��"), lstrlen(TEXT("�ؿ�ʧ��")));
	}
	else if (currentStage->stageID == STAGE_SUCCESS) 
	{
		TextOut(hdc_memBuffer, 310, 50, TEXT("�ؿ����"), lstrlen(TEXT("�ؿ����")));
	}
	else if (currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_2) 
	{
		if (theHero == NULL || Boss == NULL) return;
		// �������ǵ�����
		if (theHero->health > 0)
		{
			SelectObject(hdc_loadBmp, theHero->img);
			if (currentStage->stageID == STAGE_1) TransparentBlt
			(
				hdc_memBuffer, theHero->x, theHero->y,
				HERO_SIZE_X, HERO_SIZE_Y,
				hdc_loadBmp, 0, HERO_SIZE_Y * theHero->frame, HERO_SIZE_X, HERO_SIZE_Y,
				RGB(255, 255, 255)
			);
			else TransparentBlt
			(
				hdc_memBuffer, theHero->x - map_move_x, theHero->y,
				HERO_SIZE_X, HERO_SIZE_Y,
				hdc_loadBmp, 0, HERO_SIZE_Y * theHero->frame, HERO_SIZE_X, HERO_SIZE_Y,
				RGB(255, 255, 255)
			);
		}
		else
		{
			for (int j=0;j<=21;j++)
			{
				int k=0;
				while (k<=20){
				SelectObject(hdc_loadBmp, bmp_Crash[j%8]);
				if (currentStage->stageID == STAGE_1) TransparentBlt
				(
					hdc_memBuffer, theHero->x + HERO_SIZE_X/2 - CRASH_SIZE/2, theHero->y + HERO_SIZE_Y/2 - CRASH_SIZE/2,
					CRASH_SIZE, CRASH_SIZE,
					hdc_loadBmp, 0, 0, CRASH_SIZE, CRASH_SIZE,
					RGB(0, 0, 0)
				);
				else TransparentBlt
				(
					hdc_memBuffer, theHero->x + HERO_SIZE_X/2 - CRASH_SIZE/2 - map_move_x, theHero->y + HERO_SIZE_Y/2 - CRASH_SIZE/2,
					CRASH_SIZE, CRASH_SIZE,
					hdc_loadBmp, 0, 0, CRASH_SIZE, CRASH_SIZE,
					RGB(0, 0, 0)
				);
				k++;
				}
			}
		}

		//������ˣ����Ʒ�����
		if (theHero->protect) 
		{
			SelectObject(hdc_loadBmp, bmp_Hero_Protect);
			if (currentStage->stageID == STAGE_1) TransparentBlt
			(
				hdc_memBuffer, theHero->x + HERO_SIZE_X/2 - HERO_PROTECT_SIZE/2, theHero->y + HERO_SIZE_Y/2 - HERO_PROTECT_SIZE/2,
				HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
				hdc_loadBmp, 0, 0, HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
				RGB(0, 0, 0)
			);
			else TransparentBlt
			(
				hdc_memBuffer, theHero->x - map_move_x + HERO_SIZE_X/2 - HERO_PROTECT_SIZE/2, theHero->y + HERO_SIZE_Y/2 - HERO_PROTECT_SIZE/2,
				HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
				hdc_loadBmp, 0, 0, HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
				RGB(0, 0, 0)
			);
		}
		//���ʹ�ü���
		if (Hero_Skill_Using) 
		{
			if (theHero->skill == HERO_SKILL_ATTACK)
			{			
				SelectObject(hdc_loadBmp, bmp_Hero_Attack_Skill[Hero_Skill_Using % 7]);
				if (currentStage->stageID == STAGE_1) TransparentBlt
				(
					hdc_memBuffer, theHero->x + HERO_SIZE_X/2 - HERO_ATTACK_WITDH/2, theHero->y + HERO_SIZE_Y/2 - HERO_ATTACK_HEIGHT/2,
					HERO_ATTACK_WITDH, HERO_ATTACK_HEIGHT,
					hdc_loadBmp, 0, 0, HERO_ATTACK_HEIGHT, HERO_ATTACK_HEIGHT,
					RGB(255, 255, 255)
				);		
				else TransparentBlt
				(
					hdc_memBuffer, theHero->x - map_move_x + HERO_SIZE_X/2 - HERO_ATTACK_WITDH/2, theHero->y + HERO_SIZE_Y/2 - HERO_ATTACK_HEIGHT/2,
					HERO_ATTACK_WITDH, HERO_ATTACK_HEIGHT,
					hdc_loadBmp, 0, 0, HERO_ATTACK_HEIGHT, HERO_ATTACK_HEIGHT,
					RGB(255, 255, 255)
				);		
			}
		}
		
		//��������״̬������
		int i=0;
		SelectObject(hdc_loadBmp, bmp_HeroHealth);
		for ( i=1;i<=theHero->health;i++)
			TransparentBlt
			(
				hdc_memBuffer, HERO_HEALTH_X*i-30, 10,
				HERO_HEALTH_X, HERO_HEALTH_Y,
				hdc_loadBmp, 0, 0, HERO_HEALTH_X, HERO_HEALTH_Y,
				RGB(255, 255, 255)
			);
		if (Hero_Skill_Ready)
		{
			SelectObject(hdc_loadBmp, bmp_Skill_Bonus_Ready);
			TransparentBlt
			(
				hdc_memBuffer, HERO_HEALTH_X*(8)-30, 10,
				HERO_HEALTH_X, HERO_HEALTH_Y,
				hdc_loadBmp, 0, 0, HERO_HEALTH_X, HERO_HEALTH_Y,
				RGB(255, 255, 255)
			);
		}

		//�����ӵ�������
		for(int i=0;i<Bullet_normal.size();i++)
			{
				Bullet_Normal* bullet = Bullet_normal[i];
				if (bullet->visible == true){
					SelectObject(hdc_loadBmp, bullet->img);
					if (bullet->ID != BOSS_BULLET_RUSH_ID)
					{
						if (currentStage->stageID == STAGE_1) TransparentBlt(
							hdc_memBuffer, bullet->x, bullet->y,
							HERO_BULLET_WIDTH, HERO_BULLET_HEIGHT,
							hdc_loadBmp, 0, 0, HERO_BULLET_WIDTH, HERO_BULLET_HEIGHT,
							RGB(0, 0, 0)
						);
						else TransparentBlt(
							hdc_memBuffer, bullet->x - map_move_x, bullet->y,
							HERO_BULLET_WIDTH, HERO_BULLET_HEIGHT,
							hdc_loadBmp, 0, 0, HERO_BULLET_WIDTH, HERO_BULLET_HEIGHT,
							RGB(0, 0, 0)
						);
					}
					else
					{
						if (currentStage->stageID == STAGE_1) TransparentBlt(
							hdc_memBuffer, bullet->x, bullet->y,
							BOSS_BULLET_RUSH_SIZE, BOSS_BULLET_RUSH_SIZE,
							hdc_loadBmp, 0, 0, BOSS_BULLET_RUSH_SIZE, BOSS_BULLET_RUSH_SIZE,
							RGB(0, 0, 0)
						);
						else TransparentBlt(
							hdc_memBuffer, bullet->x - map_move_x, bullet->y,
							BOSS_BULLET_RUSH_SIZE, BOSS_BULLET_RUSH_SIZE,
							hdc_loadBmp, 0, 0, BOSS_BULLET_RUSH_SIZE, BOSS_BULLET_RUSH_SIZE,
							RGB(0, 0, 0)
						);
					}
				}
			}
		
		//�������嵽����
		for(int i=0;i<MapTrap.size();i++)
			{
				Trap* trap = MapTrap[i];
				if (!trap->visible) continue;
				SelectObject(hdc_loadBmp, trap->img);
				if (currentStage->stageID == STAGE_1) TransparentBlt(
					hdc_memBuffer, trap->x, trap->y,
					TRAP_WIDTH, TRAP_WIDTH,
					hdc_loadBmp, 0, 0, TRAP_WIDTH, TRAP_WIDTH,
					RGB(255, 255, 255)
				);
				else TransparentBlt(
					hdc_memBuffer, trap->x - map_move_x, trap->y,
					TRAP_WIDTH, TRAP_WIDTH,
					hdc_loadBmp, 0, 0, TRAP_WIDTH, TRAP_WIDTH,
					RGB(255, 255, 255)
				);
			}

		//����ש�鵽����
		for(int i=0;i<Brick.size();i++)
			{
				Trick* brick = Brick[i];
				if (!brick->visible) continue;
				SelectObject(hdc_loadBmp, brick->img);
				if (currentStage->stageID == STAGE_1) TransparentBlt(
					hdc_memBuffer, brick->x, brick->y,
					BRICK_SIZE, BRICK_SIZE,
					hdc_loadBmp, 0, 0, BRICK_SIZE, BRICK_SIZE,
					RGB(255, 255, 255)
				);
				else TransparentBlt(
					hdc_memBuffer, brick->x - map_move_x, brick->y,
					BRICK_SIZE, BRICK_SIZE,
					hdc_loadBmp, 0, 0, BRICK_SIZE, BRICK_SIZE,
					RGB(255, 255, 255)
				);
			}

		//����boss������
		if (Boss->health >0)
		{
			if (Boss->skill == BOSS_SKILL1)
			{
				wchar_t open_order[300];  
				SetBkMode(hdc_memBuffer, 0);
				swprintf_s(open_order, L"health:%d", Boss->health);	
				TextOut(hdc_memBuffer, Boss->x - 5, Boss->y - 20, open_order, lstrlen(open_order));
				SelectObject(hdc_loadBmp, Boss->img);
				if (currentStage->stageID == STAGE_1) TransparentBlt(
					hdc_memBuffer, Boss->x, Boss->y,
					BOSS_SIZE, BOSS_SIZE,
					hdc_loadBmp, 0, 0, BOSS_SIZE, BOSS_SIZE,
					RGB(255, 255, 255)
				);
				else TransparentBlt(
					hdc_memBuffer, Boss->x - map_move_x, Boss->y,
					BOSS_SIZE, BOSS_SIZE,
					hdc_loadBmp, 0, 0, BOSS_SIZE, BOSS_SIZE,
					RGB(255, 255, 255)
				);
			}
			else if (Boss->skill == BOSS_SKILL2)
			{
				wchar_t open_order[300];  
				SetBkMode(hdc_memBuffer, 0);
				swprintf_s(open_order, L"health:%d", Boss->health);	
				TextOut(hdc_memBuffer, Boss->x - map_move_x - 5, Boss->y - 20, open_order, lstrlen(open_order));
				SelectObject(hdc_loadBmp, Boss->img);
				if (currentStage->stageID == STAGE_1) TransparentBlt(
					hdc_memBuffer, Boss->x, Boss->y,
					BOSS2_SIZE*3/5, BOSS2_SIZE*3/5,
					hdc_loadBmp, 0, 0, BOSS2_SIZE, BOSS2_SIZE,
					RGB(0, 0, 0)
				);
				else TransparentBlt(
					hdc_memBuffer, Boss->x - map_move_x, Boss->y,
					BOSS2_SIZE*3/5, BOSS2_SIZE*3/5,
					hdc_loadBmp, 0, 0, BOSS2_SIZE, BOSS2_SIZE,
					RGB(0, 0, 0)
				); 
				for (int i=0; i<Boss_Bonus.size(); i++)			
				{
					Boss_Condition* boss = Boss_Bonus[i];
					SelectObject(hdc_loadBmp, bmp_Boss2_Plus);
					if (currentStage->stageID == STAGE_1) TransparentBlt(
						hdc_memBuffer, boss->x, boss->y,
						BOSS_SIZE, BOSS_SIZE,
						hdc_loadBmp, 0, 0, BOSS_SIZE, BOSS_SIZE,
						RGB(0, 0, 0)
					);
					else TransparentBlt(
						hdc_memBuffer, boss->x - map_move_x, boss->y,
						BOSS_SIZE, BOSS_SIZE,
						hdc_loadBmp, 0, 0, BOSS_SIZE, BOSS_SIZE,
						RGB(0, 0, 0)
					);
				}
			}
		}
		else
		{
			for (int j=0;j<=21;j++)
			{
				int k=0;
				while (k<=20){
				SelectObject(hdc_loadBmp, bmp_Crash[j%8]);
				if (currentStage->stageID == STAGE_1) TransparentBlt
				(
					hdc_memBuffer, Boss->x + ENEMY_SIZE/2 - CRASH_SIZE/2, Boss->y + ENEMY_SIZE/2 - CRASH_SIZE/2,
					CRASH_SIZE, CRASH_SIZE,
					hdc_loadBmp, 0, 0, CRASH_SIZE, CRASH_SIZE,
					RGB(0, 0, 0)
				);
				else TransparentBlt
				(
					hdc_memBuffer, Boss->x - map_move_x + ENEMY_SIZE/2 - CRASH_SIZE/2, Boss->y + ENEMY_SIZE/2 - CRASH_SIZE/2,
					CRASH_SIZE, CRASH_SIZE,
					hdc_loadBmp, 0, 0, CRASH_SIZE, CRASH_SIZE,
					RGB(0, 0, 0)
				);
				k++;
				}
			}
		}

		//����boss������
		if (Boss->protect) 
		{
			if (Boss->skill == BOSS_SKILL1)
			{
				SelectObject(hdc_loadBmp, bmp_Hero_Protect);
				if (currentStage->stageID == STAGE_1) TransparentBlt
				(
					hdc_memBuffer, Boss->x + BOSS_SIZE - HERO_PROTECT_SIZE - 3, Boss->y + BOSS_SIZE - HERO_PROTECT_SIZE - 3,
					HERO_PROTECT_SIZE+10, HERO_PROTECT_SIZE+10,
					hdc_loadBmp, 0, 0, HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
					RGB(0, 0, 0)
				);
				else TransparentBlt
				(
					hdc_memBuffer, Boss->x - map_move_x + BOSS_SIZE - HERO_PROTECT_SIZE - 3, Boss->y + BOSS_SIZE - HERO_PROTECT_SIZE - 3,
					HERO_PROTECT_SIZE+10, HERO_PROTECT_SIZE+10,
					hdc_loadBmp, 0, 0, HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
					RGB(0, 0, 0)
				);
			}
			else if (Boss->skill == BOSS_SKILL2)
			{
				SelectObject(hdc_loadBmp, bmp_Boss_Protect);
				if (currentStage->stageID == STAGE_1) TransparentBlt
				(
					hdc_memBuffer, Boss->x + BOSS2_SIZE*3/5/2 - BOSS2_PROTECT_SIZE*3/5/2, Boss->y + BOSS2_SIZE*3/5/2 - BOSS2_PROTECT_SIZE*3/5/2,
					BOSS2_PROTECT_SIZE*3/5,BOSS2_PROTECT_SIZE*3/5,
					hdc_loadBmp, 0, 0, BOSS2_PROTECT_SIZE, BOSS2_PROTECT_SIZE,
					RGB(0, 0, 0)
				);
				else TransparentBlt
				(
					hdc_memBuffer, Boss->x - map_move_x + BOSS2_SIZE*3/5/2 - BOSS2_PROTECT_SIZE*3/5/2, Boss->y + BOSS2_SIZE*3/5/2 - BOSS2_PROTECT_SIZE*3/5/2,
					BOSS2_PROTECT_SIZE*3/5,BOSS2_PROTECT_SIZE*3/5,
					hdc_loadBmp, 0, 0, BOSS2_PROTECT_SIZE, BOSS2_PROTECT_SIZE,
					RGB(0, 0, 0)
				);
				for (int i=0; i<Boss_Bonus.size(); i++)			
				{
					Boss_Condition* boss = Boss_Bonus[i];
					SelectObject(hdc_loadBmp, bmp_Hero_Protect);
					if (currentStage->stageID == STAGE_1) TransparentBlt(
						hdc_memBuffer, boss->x + BOSS_SIZE - HERO_PROTECT_SIZE - 3, boss->y + BOSS_SIZE - HERO_PROTECT_SIZE - 3,
						HERO_PROTECT_SIZE+10, HERO_PROTECT_SIZE+10,
						hdc_loadBmp, 0, 0, HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
						RGB(0, 0, 0)
					);
					else TransparentBlt(
						hdc_memBuffer, boss->x - map_move_x + BOSS_SIZE - HERO_PROTECT_SIZE - 3, boss->y + BOSS_SIZE - HERO_PROTECT_SIZE - 3,
						HERO_PROTECT_SIZE+10, HERO_PROTECT_SIZE+10,
						hdc_loadBmp, 0, 0, HERO_PROTECT_SIZE, HERO_PROTECT_SIZE,
						RGB(0, 0, 0)
					);
				}
			}
		}

		//����С��
		for (int i=0; i<Enemy.size(); i++)
		{			
			Enemy_Condition* enemy = Enemy[i];
			if (enemy->health >0)
			{
				SelectObject(hdc_loadBmp, enemy->img);
				if (currentStage->stageID == STAGE_1) TransparentBlt
				(
					hdc_memBuffer, enemy->x, enemy->y,
					ENEMY_SIZE, ENEMY_SIZE,
					hdc_loadBmp, 0, 0, ENEMY_SIZE, ENEMY_SIZE,
					RGB(255, 255, 255)
				);
				else TransparentBlt
				(
					hdc_memBuffer, enemy->x - map_move_x, enemy->y,
					ENEMY_SIZE, ENEMY_SIZE,
					hdc_loadBmp, 0, 0, ENEMY_SIZE, ENEMY_SIZE,
					RGB(255, 255, 255)
				);
			}
			else 
			{
				for (int j=0;j<=21;j++)
				{
					int k=0;
					while (k<=20){
					SelectObject(hdc_loadBmp, bmp_Crash[j%8]);
					if (currentStage->stageID == STAGE_1) TransparentBlt
					(
						hdc_memBuffer, enemy->x + ENEMY_SIZE/2 - CRASH_SIZE/2, enemy->y + ENEMY_SIZE/2 - CRASH_SIZE/2,
						CRASH_SIZE, CRASH_SIZE,
						hdc_loadBmp, 0, 0, CRASH_SIZE, CRASH_SIZE,
						RGB(0, 0, 0)
					);
					else TransparentBlt
					(
						hdc_memBuffer, enemy->x - map_move_x + ENEMY_SIZE/2 - CRASH_SIZE/2, enemy->y + ENEMY_SIZE/2 - CRASH_SIZE/2,
						CRASH_SIZE, CRASH_SIZE,
						hdc_loadBmp, 0, 0, CRASH_SIZE, CRASH_SIZE,
						RGB(0, 0, 0)
					);
					k++;
					}
				}
			}
		}

	}

	// ���ư�ť������
	for(int i=0;i<buttons.size();i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (skill_bonus==button->buttonID){
				SelectObject(hdc_loadBmp, button->img);
				TransparentBlt(
					hdc_memBuffer, button->x, button->y,
					button->width, button->height,
					hdc_loadBmp, 0, 0, button->width, button->height,
					RGB(255, 255, 255));
			}
			else if (button->buttonID >= HERO_SKILL_ATTACK && button->buttonID <= HERO_SKILL_LIGHTMOVE)
			{
				SelectObject(hdc_loadBmp, button->img);
				TransparentBlt(
					hdc_memBuffer, button->x, button->y,
					button->width, button->height,
					hdc_loadBmp, 0, 0, button->width, button->height,
					RGB(195, 195, 195));
			}
			else if (button->buttonID == BUTTON_CHOICESTAGE1 && stagechoose != STAGE_1 || button->buttonID == BUTTON_CHOICESTAGE2 && stagechoose != STAGE_2)
			{
				SelectObject(hdc_loadBmp, button->img);
				TransparentBlt(
					hdc_memBuffer, button->x, button->y,
					button->width, button->height,
					hdc_loadBmp, 0, 0, button->width, button->height,
					RGB(195, 195, 195));
			}
			else if (button->buttonID == BUTTON_CHOICESTAGE1 && stagechoose == STAGE_1)
			{
				SelectObject(hdc_loadBmp, button->img);
				TransparentBlt(
					hdc_memBuffer, button->x, button->y,
					button->width, button->height,
					hdc_loadBmp, 0, 0, button->width, button->height,
					RGB(255, 255, 255));
				SelectObject(hdc_loadBmp, bmp_backgroundofstage1);
				TransparentBlt(
					hdc_memBuffer, 175, 340,
					BUTTON_BACKGROUNDOFSTAGE1_WIDTH, BUTTON_BACKGROUNDOFSTAGE1_HEIGHT,
					hdc_loadBmp, 0, 0, BUTTON_BACKGROUNDOFSTAGE1_WIDTH, BUTTON_BACKGROUNDOFSTAGE1_HEIGHT,
					RGB(255, 255, 255));
			}
			else if (button->buttonID == BUTTON_CHOICESTAGE2 && stagechoose == STAGE_2)
			{
				SelectObject(hdc_loadBmp, button->img);
				TransparentBlt(
					hdc_memBuffer, button->x, button->y,
					button->width, button->height,
					hdc_loadBmp, 0, 0, button->width, button->height,
					RGB(255, 255, 255));
				SelectObject(hdc_loadBmp, bmp_backgroundofstage2);
				TransparentBlt(
					hdc_memBuffer, 175, 340,
					BUTTON_BACKGROUNDOFSTAGE1_WIDTH, BUTTON_BACKGROUNDOFSTAGE1_HEIGHT,
					hdc_loadBmp, 0, 0, BUTTON_BACKGROUNDOFSTAGE1_WIDTH, BUTTON_BACKGROUNDOFSTAGE1_HEIGHT,
					RGB(255, 255, 255));
			}
			else{
				SelectObject(hdc_loadBmp, button->img);
				TransparentBlt(
					hdc_memBuffer, button->x, button->y,
					button->width, button->height,
					hdc_loadBmp, 0, 0, button->width, button->height,
					RGB(195, 195, 195)
					);				
			}
		}
	}
	
	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ棨�ǳ���Ҫ��
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);
	DeleteObject(hPen);

	// ��������
	EndPaint(hWnd, &ps);
}

//��ͣ���������Դ����
void pause_clear(HWND hWnd)
{
	KillTimer(hWnd, HERO_BULLET_TIMER);
	KillTimer(hWnd, TIMER_TRAP);
	KillTimer(hWnd, TIMER_BOSS1);
	KillTimer(hWnd, TIMER_BOSS_PROTECT);
	KillTimer(hWnd, TIMER_PROTECT);
	KillTimer(hWnd, TIMER_BOSS1_BULLET);
	KillTimer(hWnd, TIMER_BOSS_PROTECT_DESTROY_ELAPSE);
	KillTimer(hWnd, TIMER_HERO_SKILL_CD_ID);
	KillTimer(hWnd, TIMER_HERO_SKILL_LAST_ID);
	KillTimer(hWnd, TIMER_ENEMY_BULLET);

	num_enemy = 0;
	Hero_Skill_Ready = false;
	Hero_Skill_Attack = false;
	Bullet_normal.clear();
	MapTrap.clear();
	Enemy.clear();
	Brick.clear();
	Boss_Bonus.clear();
	handy_protect_boss = false;
	map_move_x = 0;
	map_move_x_plus = 0;
	num_bonus = 0;
	stagechoose = 0;
	for (int i=0;i<=2;i++) trap_exist[i] = false;
	if (theHero != NULL) 
	{
		delete(theHero);
		theHero = new Hero();
	}
	theHero = NULL;
	if (Boss != NULL) 
	{
		delete(Boss);
		Boss = new Boss_Condition();
	}
	Boss = NULL;
	//InvalidateRect(hWnd, NULL, FALSE);//ˢ����ʾ
}

#pragma endregion

