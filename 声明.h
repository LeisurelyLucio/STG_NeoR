#pragma region ͷ�ļ�����

// Windows ͷ�ļ�: 
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <time.h>
//#include <dsound.h>
//#include <mmreg.h>

//#include <afxwin.h>
//#include <afxext.h>
//#include <vfw.h>
//#pragma comment(lib,"vfw32.lib")

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string.h>

// ��Դͷ�ļ�
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")


//���ó�����Ҫ������ͷ�ļ�
#include <vector>
#include <math.h>


#pragma endregion

#pragma region �궨��

//�������
#define WINDOW_WIDTH	800							//���ڿ�ȶ���ĺ�
#define WINDOW_HEIGHT	600							//���ڸ߶ȶ���ĺ�
#define WINDOW_TITLE	L"�� NeoR Automata ��"	//���ڱ��ⶨ��ĺ�
#define WINDOW_TITLEBARHEIGHT	32		//�������߶�

//�ؿ�ѡ��
#define STAGE_STARTMENU			0		//��ʼ�����ID
#define STAGE_1					1		//��һ����Ϸ������ID
#define STAGE_2					2		//�ڶ�����Ϸ������ID
#define STAGE_HELP				3		//���������ID
#define STAGE_CHOICE			4		//ѡ�ؽ����ID
#define STAGE_PAUSE				5		//��ͣ�����ID
#define STAGE_FAILED			6		//ʧ�ܽ����ID
#define STAGE_SUCCESS			7		//�ɹ������ID

//�������
#define HERO_SIZE_X				25		//���ǵĿ��
#define HERO_SIZE_Y				25		//���ǵĸ߶�
#define HERO_FRAME_NUMBER		12		//���ǵĶ���֡����
#define HERO_HEALTH_X			50		//��������ֵͼ����
#define HERO_HEALTH_Y			39		//��������ֵͼ��߶�
#define HERO_ACCELERATION		0.3		//���Ǽ��ٶ�
#define HERO_MAXSPEED			6.0		//��������ٶ�
#define HERO_LOW_MAXSPEED		3.5		//��������ٶ�
#define HERO_SKILL_ATTACK		1		//���Ǽ��ܣ�����ս���Ҽ���ս:�����ӵ������ӷ�������ɱС��;���ܰ�ťID
#define	HERO_ATTACK_WITDH		150		//���Ǽ��ܣ���սͼ���С
#define	HERO_ATTACK_HEIGHT		150		//���Ǽ��ܣ���սͼ���С
#define HERO_SKILL_BULLET		2		//���Ǽ��ܣ��ӵ���ʦ���ӵ���ǽ����һ��,���٣��ɵ��������ӵ���������٣���ɱС����������������ӵ�;���ܰ�ťID
#define HERO_SKILL_STRONG		3		//���Ǽ��ܣ��������ӣ�������������������ʱ������;���ܰ�ťID
#define HERO_SKILL_LIGHTMOVE	4		//���Ǽ��ܣ�����ԾǨ���ƶ����������λ�ò�������ʱ����;���ܰ�ťID
#define HERO_BULLET_ID			100		//�����ӵ�ID
#define HERO_BULLET_WIDTH		16		//�����ӵ����
#define HERO_BULLET_HEIGHT		16		//�����ӵ��߶�
#define BULLET_V				7		//�����ӵ��ٶ�
#define BULLET_V_SKILL			6		//���Ǽ����ӵ����ٶ�
#define BULLET_COLLISION_SKILL	3		//���Ǽ����ӵ�����ײ����
#define BULLET_COLLISION		2		//������ͨ�ӵ�����ײ����
#define HERO_PROTECT_SIZE		50		//���Ƿ�����/boss1�����ֳߴ�
#define CRASH_SIZE				64		//��ըͼ��ߴ�

//��ť���
////��ʼ����
#define BUTTON_STARTGAME			1001	//��ʼ��Ϸ��ťID
#define BUTTON_STARTGAME_WIDTH		95		//��ʼ��Ϸ��ť���
#define BUTTON_STARTGAME_HEIGHT		24		//��ʼ��Ϸ��ť�߶�
#define BUTTON_TITLEGAME			1002	//��Ϸ���ⰴťID
#define BUTTON_TITLEGAME_WIDTH		513		//��Ϸ���ⰴť���
#define BUTTON_TITLEGAME_HEIGHT		180		//��Ϸ���ⰴť�߶�
#define BUTTON_HELP					1003	//��Ϸ������ťID
#define BUTTON_HELP_WIDTH			76		//��Ϸ������ť���
#define BUTTON_HELP_HEIGHT			24		//��Ϸ������ť�߶�
#define BUTTON_EXIT					1004	//��Ϸ������ťID
#define BUTTON_EXIT_WIDTH			63		//��Ϸ�˳���ť���
#define BUTTON_EXIT_HEIGHT			23		//��Ϸ�˳���ť�߶�
////��һ�ء��ڶ���
#define BUTTON_PAUSE				2001	//��Ϸ��ͣ��ťID
#define BUTTON_PAUSE_WIDTH			109		//��Ϸ��ͣ��ť���
#define BUTTON_PAUSE_HEIGHT			29		//��Ϸ��ͣ��ť�߶�
#define TRAP_WIDTH					75		//������
#define TRAP_1						101		//��������1����������
#define TRAP_2						102		//��������2���ӵ����ţ����ƺ����С����ʹboss���»ص��ܱ���״̬
#define TRAP_3						103		//��������3���ж�����
#define BOSS_SIZE					45		//BOSS1ͼ��ߴ�;С��ͼ��ߴ�
#define BOSS2_PROTECT_SIZE			128		//BOSS2�����ֳߴ�
#define BOSS2_SIZE					100		//BOSS2�ߴ�
#define BOSS_SKILL1					1		//boss����������˲�ƣ����Ե�Ļ���ٻ�С��������
#define BOSS_LIGHTMOVE				0		//boss���ܣ�˲��
#define BOSS_AIMED					1		//boss���ܣ�׷�ٵ�Ļ
#define BOSS_LINE2					2		//boss���ܣ����Ե�Ļ����
#define BOSS_LINE					3		//boss���ܣ����Ե�Ļ
#define BOSS_RANDOM1				4		//boss���ܣ������Ļ
#define BOSS_CALLING				5		//boss���ܣ��ٻ�С��
#define BOSS_SKILL2					2		//boss����������˲�ƣ�׷�ٵ�Ļ���ٻ�С���������ƶ�
#define BOSS_MOVE					6		//boss���ܣ��ݵ�
#define BOSS_AIMBULLET				7		//boss���ܣ������ӵ�
#define BOSS_LINERUSH				8		//boss���ܣ�������		
#define BOSS_RUSH					9		//boss���ܣ�����
#define BOSS_BULLET_ID				101		//boss�ӵ���С������1��2�ӵ�ID
#define	BOSS_AIMED_BULLET_ID		103		//boss2׷���ӵ�ID
#define BOSS_BULLET_SIZE			16		//boss�ӵ��ߴ�
#define BOSS_BULLET_V				3		//boss�ӵ��ƶ��ٶ�
#define BOSS_HEALTH					40		//boss����ֵ
#define BOSS2_HEALTH				50		//boss2����ֵ
#define BOSS_V						1.6		//boss1�ƶ��ٶ�
#define BOSS2_V						2.5		//boss2�ƶ��ٶ�
#define BOSS2_MAXV					7.0		//boss2�ƶ��ٶ�
#define BOSS_HEALTH1				31		//boss�ٽ�����ֵ1
#define BOSS_HEALTH2				15		//boss�ٽ�����ֵ2
#define BOSS_BULLET_RUSH_ID			102		//boss������ID
#define BOSS_BULLET_RUSH_SIZE		50		//boss�������ߴ�
#define BOSS_BULLET_RUSH_V			5		//boss�������ƶ��ٶ�
#define ENEMY_V						2		//С���ƶ��ٶ�
#define ENEMY_V2					3		//С���ƶ��ٶ�
#define ENEMY_SKILL1				11		//С������1�������������Ե�Ļ����·��
#define ENEMY_SKILL2				12		//С������2����������boss��Ļ��
#define ENEMY_SIZE					45		//С��ͼ��ߴ�
#define ENEMY_BULLET_V				3		//С���ӵ��ƶ��ٶ�
#define ENEMY_HEALTH				4		//С������ֵ
#define ENEMY_ID1					100		//С����Ȼ����
#define ENEMY_ID2					101		//С����ѭ�ٻ�����
#define BRICK_KIND1					1001	//ש������1����ͨש��
#define BRICK_KIND2					1002	//ש������2�����ƻ�ש��
#define BRICK_KIND3					1003	//ש������3������ש��
#define BRICK_KIND4					1004	//ש������4���ָ�ש��
#define BRICK_SIZE					50	    //ש��ߴ�
////ѡ�ؽ���
#define BUTTON_CHOICESTAGE1			4001	//ѡ���һ�ذ�ťID
#define BUTTON_CHOICESTAGE1_WIDTH	100		//ѡ���һ�ذ�ť���
#define BUTTON_CHOICESTAGE1_HEIGHT	16		//ѡ���һ�ذ�ť�߶�
#define BUTTON_CHOICESTAGE2			4002	//ѡ��ڶ��ذ�ťID
#define BUTTON_BACKGROUNDOFSTAGE1_WIDTH	450		//ѡ���һ�ر������°�ť���
#define BUTTON_BACKGROUNDOFSTAGE1_HEIGHT	200	//ѡ���һ�ر������°�ť�߶�
////��ͣ������ʧ�ܽ���
#define BUTTON_RETRY				3001	//���԰�ťID
#define BUTTON_RETRY_WIDTH			109		//���԰�ť���
#define BUTTON_RETRY_HEIGHT			29		//���԰�ť�߶�
#define BUTTON_CONTINUE				3002	//������ťID
#define BUTTON_CONTINUE_WIDTH		109		//������ť���
#define BUTTON_CONTINUE_HEIGHT		29		//������ť�߶�
#define BUTTON_BACKTOTITLE			3003	//���ر���ҳ��ťID
#define BUTTON_BACKTOTITLE_WIDTH	109		//���ر���ҳ��ť���
#define BUTTON_BACKTOTITLE_HEIGHT	29		//���ر���ҳ��ť�߶�
#define BUTTON_BACKTOCHOICE			3004	//����ѡ��ҳ��ťID
#define BUTTON_BACKTOCHOICE_WIDTH	109		//����ѡ��ҳ��ť���
#define BUTTON_BACKTOCHOICE_HEIGHT	29		//����ѡ��ҳ��ť�߶�

//��ʱ��
#define TIMER_GAMETIMER				1		//��Ϸ��Ĭ�ϼ�ʱ��ID
#define TIMER_GAMETIMER_ELAPSE		10		//Ĭ�ϼ�ʱ��ˢ�¼���ĺ�����
#define HERO_BULLET_TIMER			2		//�����ӵ������ʱ��ID
#define HERO_BULLET_TIMER_ELAPSE	200		//�����ӵ������ʱ��ˢ�¼��������
#define HERO_BULLET_SKILL_TIMER_ELAPSE	180		//�����ӵ������ʱ��ˢ�¼�������������ڼ��ܣ�
#define TIMER_TRAP					3		//��ͼ�����ʱ��ID
#define TIMER_TRAP_ELAPSE			2000	//��ͼ�����ʱ��ˢ�¼��������
#define TIMER_HERO_SKILL_LAST_ID	9		//�����������ܽ�ս����ʱ���ʱ��ID
#define TIMER_HERO_SKILL_LAST		50		//�����������ܽ�ս����ˢ�¼��
#define TIMER_HERO_SKILL_CD_ID		8		//��������������ȴ��ʱ��ID
#define TIMER_HERO_SKILL2_CD		6000	//�����������ܽ���ս��ȴ
#define TIMER_HERO_SKILL3_CD		1000	//���Ǳ��������ӵ���ʦ��ȴ
#define TIMER_HERO_SKILL1_CD		4000	//���Ǳ�����������������ȴ
#define TIMER_HERO_SKILL4_CD		2500	//����������������ԾǨ��ȴ
#define TIMER_BOSS1					4		//bossAIר�ü�ʱ��ID
#define TIMER_BOSS1_ELAPSE1			4700	//boss1�ֶ�ˢ�»��ƣ���������
#define TIMER_BOSS1_ELAPSE2			3200	//boss1�ֶ�ˢ�»��ƣ���������
#define TIMER_BOSS1_ELAPSE3			1500	//boss1�ֶ�ˢ�»��ƣ���������
/*#define TIMER_BOSS2_ELAPSE			2300	//boss2ˢ��  */
#define TIMER_BOSS1_BULLET			5		//boss�ӵ������ʱ��ID
#define TIMER_BOSS1_BULLET_SENDNUM	7		//boss��Ļ�ѵ�����
#define TIMER_BOSS1_BULLET_ELAPSE1	650		//boss�ӵ�������ʱ��1
#define TIMER_BOSS1_BULLET_ELAPSE2	450		//boss�ӵ�������ʱ��2
#define TIMER_BOSS1_BULLET_ELAPSE3	200		//boss�ӵ�������ʱ��3
#define TIMER_BOSS2_BULLET_ELAPSE	300		//boss2�ӵ�������ʱ��
#define TIMER_BOSS_PROTECT			6		//boss�����ּ�ʱ��ID
#define TIMER_BOSS_PROTECT_ELAPSE	500		//boss�����ֻ����ָ�����ʱ
#define TIMER_BOSS_PROTECT_DESTROY_ELAPSE	1500	//boss���������鵹��ʱ
#define TIMER_BOSS2_PROTECT_DESTROY_ELAPSE  2500		//boss2���������鵹��ʱ
#define TIMER_PROTECT				7		//�������˺��޵м�ʱ��ID
#define TIMER_PROTECT_ELAPSE		2000	//�������˺��޵м�ʱ��ˢ��ʱ��
#define TIMER_PROTECT_ELAPSE_SKILL1		3000	//�������˺��޵м�ʱ��ˢ��ʱ�䣨���ܣ������ӻ���
#define TIMER_PROTECT_ELAPSE_SKILL4		500	//����ԾǨ���޵м�ʱ��ˢ��ʱ�䣨���ܣ�����ԾǨ��
#define TIMER_ENEMY_BULLET			11		//С���ӵ������ʱ��ID
#define TIMER_ENEMY_BULLET_ELAPSE	1000		//С���ӵ�������ʱ��
#define TIMER_HERO_UP			12		//Ӣ�������ظ���ʱ��ID
#define TIMER_HERO_UP_ELAPSE	4000		//Ӣ�������ظ����ʱ��
#define TIMER_HERO_UPJUDGE			13		//Ӣ�������ظ��жϼ�ʱ��ID
#define TIMER_HERO_UPJUDGE_ELAPSE	3000		//Ӣ�������ظ���������ʱ��

#pragma endregion

#pragma region �ṹ������


struct Stage	// �����ṹ��
{
	int stageID;		//�������
	HBITMAP background;			//����ͼƬ
	int timeCountDown;	//��Ϸʱ�䵹��ʱ
	bool timerOn;		//��ʱ���Ƿ����У���Ϸ�Ƿ���ͣ��
};

struct Button	// ��ť�ṹ��
{
	int buttonID;	//��ť���
	bool visible;	//��ť�Ƿ�ɼ�
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	int width;		//���
	int height;		//�߶�
};

struct Trap		//����ṹ��
{
	int trapID;
	HBITMAP img;
	bool visible;
	int health;
	bool inn;	//�Ƿ��������ڲ�
	int x;
	int y;
};

struct Trick		//ש��ṹ��
{
	int brickID;
	HBITMAP img;
	bool visible;
	int health;
	int x;
	int y;
};
struct Hero		// ���ǽṹ��
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	int health;		//����ֵ
	int skill;      //����ѡ��
	bool protect;	//���˺��޵�ʱ��
};

struct Bullet_Normal		// �ӵ��ṹ��
{
	HBITMAP img;	//ͼƬ������Ϊ�ж��ӵ��Ƿ���Ե���������
	bool visible;	//�Ƿ���Ҫ����
	int ID;			//������
	int x;			//����x
	int y;			//����y
	double v;				//���ٶ�
	int direction_x;		//�ٶȷ���x
	int direction_y;		//�ٶȷ���y
	bool inn;		//�Ƿ���������
	int collision;		//�Ƿ�������ײ
};

struct Boss_Condition		// Boss�ṹ��
{
	HBITMAP img;	//ͼƬ
	bool protect;	//�Ƿ��ڱ���״̬
	int x;			//����x
	int y;			//����y
	double v;				//���ٶ�
	int direction_x;		//�ٶȷ���x
	int direction_y;		//�ٶȷ���y
	int skill;				//boss����
	int health;			//boss����ֵ
};

struct Enemy_Condition		// С���ṹ��
{
	HBITMAP img;	//ͼƬ
	bool protect;	//�Ƿ��ڱ���״̬
	int x;			//����x
	int y;			//����y
	double v;				//���ٶ�
	int direction_x;		//�ٶȷ���x
	int direction_y;		//�ٶȷ���y
	int skill;				//С������
	int health;			//С������ֵ
	int ID;			//С����γ��֣���Ȼor�ٻ�
};



#pragma endregion

#pragma region ����ע�ắ������
	
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

#pragma endregion

#pragma region �¼�����������
// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);
// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
// AI��Ļ���亯��
void Send_Bullet(int kind, HWND hWnd);
// ����Ҽ������¼�������
void RButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ����Ҽ��ɿ��¼�������
void RButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion

#pragma region ״̬����������
// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);
// ������Ǻ���
Hero* CreateHero(HBITMAP img, int x, int y, int health, int skill);
// �������ֱ���ӵ���������
Bullet_Normal* CreateHeroBullet(HBITMAP img, int ID);
// ��ʼ����������
void InitStage(HWND hWnd, int stageID);
// ˢ������״̬����
void UpdateHero(HWND hWnd);
// �������ǵĵ�ǰ֡��
int GetHeroFrame(double dirX, double dirY);
// ��ͼ���庯��
Trap* CreateTrap(HBITMAP img, int x, int y, int trap_id);
// ���Ƿ�����
void Protect_Hero(HWND hWnd);
// boss�ж�ָ��
void UpdateBoss(HWND hWnd);
//boss�޵�
void Protect_Boss(HWND hWnd);
//boss�޵���ʱʧЧ
void Protect_Boss_Destroy(HWND hWnd);
// ���boss�ӵ�
Bullet_Normal* CreateBossBullet(HBITMAP img, int x, int y, int directx, int directy, int ID);
//�ӵ���ײ���
void Bullet_Collision(HWND hWnd);
//���С������
Enemy_Condition* CreateEnemy(HBITMAP img, int x, int y, int direct_x, int direct_y, int skill, HWND hWnd, int ID);
//С��״̬����
void UpdateEnemy(HWND hWnd);
//���С���ӵ�����
Bullet_Normal* CreateEnemyBullet(Enemy_Condition* enemy, HBITMAP img, int directx, int directy, int ID);

#pragma endregion

#pragma region ��ͼ����Դ���ء��ͷź�������
//��Դ�������ʼ��
BOOL Game_Load ( HWND hWnd, WPARAM wParam, LPARAM lParam);
//ͼ�λ���
void Game_Paint(HWND hWnd);
//��ͣ���������Դ����
void pause_clear(HWND hWnd);   

#pragma endregion