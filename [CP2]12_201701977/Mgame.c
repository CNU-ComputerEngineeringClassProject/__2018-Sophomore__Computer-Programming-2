#include <stdio.h>
#include <string.h>
#include <stdlib.h> //Rand 함수를 위한 해더파일
#include <windows.h> //화면 Clear를 위한 해더파일
#include <time.h> //Srand를 사용하기 위한 해더파일
#include <conio.h> //getch를 사용하기위한 해더파일

// **************************** 컬러 사용하기 Define 값 **************************** //

#define colorHandle GetStdHandle(STD_OUTPUT_HANDLE) //콘솔창의 핸들정보 받기
#define BLACK SetConsoleTextAttribute(colorHandle, 0x0000); //검정색
#define GRAY SetConsoleTextAttribute(colorHandle, 0x0007); //밝은 회색
#define RED SetConsoleTextAttribute(colorHandle, 0x000c); //빨간색
#define BLUE SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008); //파란색
#define WHITE SetConsoleTextAttribute(colorHandle, 0x000f); //하얀색
#define YEL SetConsoleTextAttribute(colorHandle, 0x000e); //노란색
#define GREEN SetConsoleTextAttribute(colorHandle, 0x0002) ; //녹색
#define VIO SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008 |0x000c); //보라색

// **************************** 커서 숨기기 매크로 **************************** //

enum { HIDDEN, SHOW };  //열거형 enum 선언

// **************************** 미로함수 방향키 아스키코드값 **************************** //

#define LEFT 75 //좌측 방향키
#define RIGHT 77 //우측 방향키
#define UP 72 //위쪽방향키
#define DOWN 80 //아래쪽 방향키
#define Enter 13 //엔터값
#define ESC 27 //esc값

// **************************** System 함수 **************************** //
void gotoxy(int, int); //x축,y축 이동시켜주는 함수
void delay(clock_t wait); //딜레이 함수 시간 몇초를 대기하기 위한 함수
void color(unsigned short color); // 랜덤 컬러를 주기 위한 함수
void viewCursor(char show); //커서를 숨기거나 보여준다.

// **************************** 미로탈출게임 함수 **************************** //
void miro();    //미로게임 메인 함수
int miroGame(); //게임 동작 ,화면 출력을 구현하는 함수

int main() {

	miro(); //미로게임 메인 함수 호출
	return 0;

}

void miro()
{
	int n; 
	n = miroGame(); //miroGame()하고 반환된 값을 n에 저장한다. 
}

void gotoxy(int x, int y) //x축,y축 이동시켜주는 함수
{
	COORD pos = { x,y }; //COORD는 x값과 y값을 갖는 구조체로 <window.h>에 포함되어있다. 구조체 변수를 생성.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //SetConsoleCursorPosition 함수는 매개변수로 받은 콘솔 스크린 버퍼와 특정 커서 좌표를 가지고 해당 콘솔 스크린 버퍼의 커서 좌표를 새 좌표로 바꿔주는 역할

}

void color(unsigned short color) //무작위 컬러 만들기위한 함수
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 스크린 핸들가져오기
	SetConsoleTextAttribute(hCon, color); //콘솔창의 출력 색상을 color로 사용할수 있게 한다.
}

void viewCursor(char show) //커서 숨기기 / 보이기
{
	HANDLE hConsole;//콘솔 핸들
	CONSOLE_CURSOR_INFO ConsoleCursor;//콘솔커서 정보 구조체

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//핸들을 구하고

	ConsoleCursor.bVisible = show; //커서표시 show 
	ConsoleCursor.dwSize = 1; //커서 사이즈를 1로 한다.

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);//설정
}

void delay(clock_t wait) //시간을 지연시키는 함수
{
	//wait ms 만큼 대기 1000 = 1 초
	clock_t goal;//	clock_t 변수 goal
	goal = wait + clock(); //대기시간 + 현재시간
	while (goal > clock()); //goal이 현재시간보다 클때 동안 계속 반복
}

int miroGame() {
	struct MIRO //MIRO구조체
	{
		int x, y; //x,y값 좌표
		int PlayN; //게임상태(?)
};
	struct MIRO Me, Mon[20], Pre[10]; //MIRO구조체의 Me, 크기가 20인 Mon, 크기가 10인 Pre 배열 변수를 선언한다.
	static int Stage = 1, PreNum; //Stage를 표시해줄 변수와 하트의 개수PreNum
	static int i, j, k = 0,T=0, b, c[20][2] = { 0 }, d[30] = { 0 }; //반복문을 위한 변수,무작위 값을 저장하기위한 변수,배열
	static int Screen[18][28] = { 0 }; //게임화면의 전체크기
	int randNum[2] = { 0 };//랜덤값을 넣기위한 크기가 2인 배열
	char ch;//키보드 입력 아스키코드값을 받기 위한 변수
	int Life = 3, LifeN, GameOver = 0;//목숨은 3개로 주어진다. //목숨의 개수, 게임종료 변수

	srand(time(NULL)); //seed

	system("mode con lines=20 cols=58"); // 창 크기 line = y축, cols = x축, lins은 -1 크기 출력 //콘솔창의 크기조절
	system("cls"); //콘솔창 전체 내용지우기
	viewCursor(HIDDEN);//커서를 숨긴다.
	system("cls"); //콘솔창 전체 내용지우기

	while (1) {
		randNum[0] = 0; //randNum 0번째 배열을 0으로 초기화한다.
		randNum[1] = 0; //randNum 1번째 배열을 0으로 초기화한다.

		gotoxy(22, 9); //커서의 위치를 (22,9)로 이동시킨다.
		printf("S t a g e %d", Stage); //게임 스테이지가 몇인지 알려준다.
		Sleep(3000);//3초를 지연시킨다.
		system("cls");//콘솔창 전체 내용지우기

		b = rand() % 14 + 2; //b에 2~15의 값을 무작위로 넣는다.

		for (i = 0; i < Stage *2; i++) { //i는 0부터 스테이지에 2를 곱한수 전까지 반복한다.
			c[i][0] = rand() % 14 + 2; //열이 0인 행이 i인 c배열에 2~15사이의 값을 랜덤으로 받는다.
			c[i][1] = rand() % 22 + 3; //열이 1인 행이 i인 c배열에 3~24사이의 값을 랜덤으로 받는다.
		 }
		for (i = 0; i < 35; i++) { //i는 0부터 35전까지 반복한다.
			d[i] = rand() % 26 + 1; //i번째 d배열에 1~26값을 랜덤으로 넣는다.
		}

		Me.x = 7; //Me의 x좌표를 7로 넣는다.
		Me.y = 1; //Me의 y좌표를 1로 넣는다.
		Me.PlayN = 1; //Me의 PlayN의 개수를 1로 초기화한다. 

		for (i = 0; i < Stage * 2; i++) { //i는 0부터 스테이지에 2를 곱한수 전까지 반복한다.
			Mon[i].x = c[i][0]; //i번째 Mon의 x좌표에 열이 0인 행이 i인 c배열값을 넣는다.
			Mon[i].y = c[i][1]; //i번째 Mon의 y좌표에 열이 1인 행이 i인 c배열값을 넣는다.
			Mon[i].PlayN = 10; //i번째 Mon의PlayN을 10으로 저장한다.
		}

		for (i = 0; i < Stage ; i++) { //i는 0부터 스테이지수 전까지 반복한다.
			Pre[i].x = c[i][0]; //i번째 Pre의 x좌표에 열이 0인 행이 i인 c배열값을 넣는다.
			Pre[i].y = c[i][1] + 1; //i번째 Pre의 y좌표에 열이 1인 행이 i인 c배열값+1을 넣는다.
			Pre[i].PlayN = 7; //i번째 Pre의PlayN을 7으로 저장한다.
		}

		for (i = 0; i < 18; i++) { //초기화시킨다.
			for (j = 0; j < 28; j++)
			{
				Screen[i][j] = 0;
			}
		}

		k = 0; // k에 0을 저장한다.
		for (i = 0; i < 18; i++) //벽생성
		{
			for (j = 0; j < 28; j++)
			{
				if (i == 0 || i == 17) //행이 0이나 17인 곳에 벽생성
					Screen[i][j] = 9;
				else if (j == 0 || j == 27) //열이 0이나 27인 곳에 벽생성
					Screen[i][j] = 9;
			}
		}
		for (i = 1; i < 18; i++) { //랜덤 벽생성
			for (j = 0; j < 28; j++) {
				if (d[k] == j) { //k번째d배열의 값이 j라면
					Screen[i][j] = 9; //행이i 열이j인 곳에 벽생성
					k++;//k하나 증가
				}
			}
		}

		Screen[b][26] = 0;//출구앞은 벽생성을 하지 않도록 한다.
		Screen[b][27] = 0;//출구 
		Screen[7][1] = 1; //초기화
		Screen[6][1] = 0;//Me가 있을곳 바로 위쪽은 벽생성을 하지 않도록 한다.

		for (i = 0; i< Stage * 2; i++) {//i는 0부터 스테이지에 2를 곱한수 전까지 반복한다.
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//Screen[Mon[i].x][Mon[i].y]에 Mon[0].PlayN값을 넣는다.
		}
		for (i = 0; i < Stage; i++) {//i는 0부터 스테이지에 2를 곱한수 전까지 반복한다.
			Screen[Pre[i].x][Pre[i].y] = Pre[0].PlayN; //Screen[Pre[i].x][Pre[i].y]에 Pre[0].PlayN값을 넣는다.
		}

		while (1) { //무한루프
			PreNum = 0; //하트개수를 0으로 한다.
			for (i = 0; i < Stage * 2; i++) {//i는 0부터 스테이지에 2를 곱한수 전까지 반복한다.
				randNum[0] = rand() % 15; //randNum[0]에 0~14중 하나의 값을 무작위로 넣는다.
				if (randNum[0] == 0) { //randNum[0]가 0이라면
					randNum[1] = rand() % 4;//randNum[1]에 0~3중 하나의 값을 무작위로 넣는다.
					switch (randNum[1]) {//randNum[1]의 값이
					case 0 ://0이라면
						if (Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN) {
							//화면에서 장애물의 왼쪽으로 갔을때 벽이 아니고, 다른 장애물이 없고, 하트가 아닌경우
							Screen[Mon[i].x][Mon[i].y] = 0; //현재 장애물의 위치에서 장애물을 없앤다.
							Mon[i].y -= 1; //장애물의 y값을 하나 줄인다.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) //만약 장애물이 움직일때 Me를 만나면
								Me.PlayN = 99; //Me.PlayN을 99로 한다.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; //화면에 Mon의(x,y)에 Mon을 보인다.
						break; //왼쪽
					case 1 ://1이라면
						if (Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN) {
							//화면에서 장애물의 오른쪽으로 갔을때 벽이 아니고, 다른 장애물이 없고, 하트가 아닌경우
							Screen[Mon[i].x][Mon[i].y] = 0;//현재 장애물의 위치에서 장애물을 없앤다.
							Mon[i].y += 1;//장애물의 y값을 하나 늘린다.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//만약 장애물이 움직일때 Me를 만나면
								Me.PlayN = 99;//Me.PlayN을 99로 한다.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//화면에 Mon의(x,y)에 Mon을 보인다.
						break; //오른쪽
					case 2://2라면
						if (Screen[Mon[i].x-1][Mon[i].y ] != 9 && Screen[Mon[i].x-1][Mon[i].y ] != Mon[i].PlayN && Screen[Mon[i].x-1][Mon[i].y ] != Pre[0].PlayN) {
							//화면에서 장애물의 위쪽으로 갔을때 벽이 아니고, 다른 장애물이 없고, 하트가 아닌경우
							Screen[Mon[i].x][Mon[i].y] = 0;//현재 장애물의 위치에서 장애물을 없앤다.
							Mon[i].x -= 1;//장애물의 x값을 하나 줄인다.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//만약 장애물이 움직일때 Me를 만나면
								Me.PlayN = 99;//Me.PlayN을 99로 한다.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//화면에 Mon의(x,y)에 Mon을 보인다.
						break; //위쪽
					case 3://3이라면
						if (Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN) {
							//화면에서 장애물의 아래쪽으로 갔을때 벽이 아니고, 다른 장애물이 없고, 하트가 아닌경우
							Screen[Mon[i].x][Mon[i].y] = 0;//현재 장애물의 위치에서 장애물을 없앤다.
							Mon[i].x += 1;//장애물의 x값을 하나 늘린다.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//만약 장애물이 움직일때 Me를 만나면
								Me.PlayN = 99;//Me.PlayN을 99로 한다.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//화면에 Mon의(x,y)에 Mon을 보인다.
						break; //아래쪽
					}
				}
			}

			for (i = 0; i < 18; i++) { //최종 출력
				gotoxy(1, i + 1); //x는 1, y는 i+1로 커서를 이동한다.
			for (j = 0; j < 28; j++) {
				if (Screen[i][j] == 0) { //Screen 행이 i이고 열이 j일때 값이 0이라면
					BLACK; //검정색
					printf("★"); //별을 출력한다.
				}//움직일수있는 공간
				else if (Screen[i][j] == Me.PlayN) { //Screen 행이 i이고 열이 j일때 값이 Me.PlayN값이라면
					RED; //빨강색
					printf("☆"); //빈별을 출력한다.
				}//사용자(Me)
				else if (Screen[i][j] == 9) { //Screen 행이 i이고 열이 j일때 값이 9라면
					WHITE; //흰색
					printf("■"); //네모를 출력한다.
				}//벽
				else if (Screen[i][j] == Mon[0].PlayN) { //Screen 행이 i이고 열이 j일때 값이 Mon[0]의 PlayN값이라면
					VIO;//보라색
					printf("◆");//다이아몬드를 출력한다.
				}//장애물
				else if (Screen[i][j] == Pre[0].PlayN) { //Screen 행이 i이고 열이 j일때 값이 Pre[0].PlayN값이라면 
					YEL;//노랑색
					printf("♡");//하트를 출력한다.
				}//선물?? Me가 먹어야하는 것
			}
			printf("\n");
		}

		if (kbhit()) {//kbhit() 키 입력여부.. 입력이 있으면 1, 없으면 0
			ch = getch(); //입력된 key의 아스키코드값 반환 후 ch에 저장
			switch (ch) { //ch의 값이
			case 75 : //75일 경우 왼쪽
				  if(Screen[Me.x][Me.y - 1] != 9 ) //화면에서 Me의 왼쪽(y값-1)이 벽이 아니라면 
			   { Screen[Me.x][Me.y] = 0;//화면에서 원래 있던곳은 0으로 Me를 없애고
					Me.y -= 1;//Me의 y값을 -1하여 왼쪽으로 한칸 이동한뒤
					if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99; //만약 Me의(x,y)자리가 장애물자리라면 Me.PlayN을 99로 저장한다.
			   }
				  Screen[Me.x][Me.y] = Me.PlayN; //화면에 Me의(x,y)에 Me를 보인다.

				break;//왼쪽
			case 77://77일 경우 오른쪽 
			 if(Screen[Me.x][Me.y + 1] != 9 ) //화면에서 Me의 오른쪽(y값+1)이 벽이 아니라면 
			   {Screen[Me.x][Me.y] = 0;//화면에서 원래 있던곳은 0으로 Me를 없애고
				   Me.y += 1;//Me의 y값을 +1하여 오른쪽으로 한칸 이동한뒤
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99;//만약 Me의(x,y)자리가 장애물자리라면 Me.PlayN을 99로 저장한다.
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;//화면에 Me의(x,y)에 Me를 보인다.
				break; //오른쪽
			case 72://72일 경우 위쪽
				 if(Screen[Me.x - 1][Me.y] != 9 )//화면에서 Me의 위쪽(x값-1)이 벽이 아니라면 
			   {
				   Screen[Me.x][Me.y] = 0;//화면에서 원래 있던곳은 0으로 Me를 없애고
				   Me.x -= 1;//Me의 x값을 -1하여 위쪽으로 한칸 이동한뒤
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99;//만약 Me의(x,y)자리가 장애물자리라면 Me.PlayN을 99로 저장한다.
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;//화면에 Me의(x,y)에 Me를 보인다.
				break; //위쪽
			case 80 ://80일경우 아래쪽
			 if(Screen[Me.x + 1][Me.y] != 9 )//화면에서 Me의 아래쪽(x값+1)이 벽이 아니라면 
			   {
				   Screen[Me.x][Me.y] = 0;//화면에서 원래 있던곳은 0으로 Me를 없애고
				   Me.x += 1;//Me의 x값을 +1하여 아래쪽으로 한칸 이동한뒤
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99;//만약 Me의(x,y)자리가 장애물자리라면 Me.PlayN을 99로 저장한다.
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;//화면에 Me의(x,y)에 Me를 보인다.
				break;//아래쪽
			case ESC: break; //esc가 눌리면 종료
			}
		}

		if (ch == ESC) break; //esc가 눌리면 종료

		LifeN = Life; //LifeN에 Life값을 저장한다.
		if (Me.PlayN == 99) {//Me의 PlayN이 99이면 //장애물을 만났다는 의미
			Life -= 1; //생명을 하나 줄인다.
			break; //게임 다시 하기
		}
		for (i = 0; i < 18; i++) {
			for (j = 0; j < 28; j++) {
				if (Screen[i][j] == Pre[0].PlayN) { //Screen i행 j열의 값이 Pre[0].PlayN과 같다면
					PreNum++; //PreNum값을 하나 증가시킨다.
				}
			}
		}

		if (PreNum == 0) { //하트가 없고
			if (Me.y == 27) break; //Me의 y자리가 27(출구)라면 break한다. //이번 스테이지 끝
		}
	} 
	if(ch==ESC) break;//esc가 눌리면 종료

	if(Life!=0 && Stage !=11){ //만약 Life가 0이아니고, Stage가 11이 아니라면(다음스테이지 이동)
		if(LifeN == Life){//만약 LifeN이 Lif와 값이 같다면
		Stage += 1; //스테이지 값을 하나 늘린다.
		system("cls");//콘솔창 전체 내용지우기
		gotoxy(16,9);//커서를 (16,9)로 이동시킨다.
		printf("S t a g e  C l e a r !!"); //스테이지를 틀리어 했다는 메세지 출력
		Sleep(3000);//3초를 지연시킨다.
		system("cls");//콘솔창 전체 내용지우기
		}else{//(죽었다면)
			gotoxy(19,10);//커서를 (19,10)로 이동시킨다.
			printf("G a m e o v e r ! !"); //게임이끝났다는 메세지 출력
			Sleep(3000);//3초를 지연시킨다.
			system("cls");//콘솔창 전체 내용지우기
			gotoxy(26,9);//커서를 (26,9)로 이동시킨다.
			WHITE;//흰색
			printf(" = %d",Life);//생명 개수를 알려준다.
			Sleep(3000);//3초를 지연시킨다.
			system("cls");//콘솔창 전체 내용지우기
			GRAY;//회색
		}
	}
	if(Life ==0){//생명이 없다면(게임이 완전히 끝)
	gotoxy(19,10);//커서를 (19,10)로 이동시킨다.
			printf("G a m e o v e r ! !");//게임이끝났다는 메세지 출력
			Sleep(3000);//3초를 지연시킨다.
			system("cls");//콘솔창 전체 내용지우기
			break;
	}
	else if(Stage ==11){//만약 스테이지가 11이라면(모든 스테이지 게임 클리어)
		system("cls");//콘솔창 전체 내용지우기
		WHITE;//흰색
		gotoxy(14,9);//커서를 (14,9)로 이동시킨다.
		printf(" C o n g r a t u l a t i o n ");//축하한다는 메세지 출력
		Sleep(3000);//3초를 지연시킨다.
			system("cls");//콘솔창 전체 내용지우기
			gotoxy(19,9);//커서를 (19,9)로 이동시킨다.
			printf("T h e E n d ! !");//게임이 끝이라는 메세지 출력
			Sleep(4000);//4초를 지연시킨다.
			GRAY;//회색
			break;
	}
	}
	return 0;
	}