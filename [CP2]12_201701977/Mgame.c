#include <stdio.h>
#include <string.h>
#include <stdlib.h> //Rand �Լ��� ���� �ش�����
#include <windows.h> //ȭ�� Clear�� ���� �ش�����
#include <time.h> //Srand�� ����ϱ� ���� �ش�����
#include <conio.h> //getch�� ����ϱ����� �ش�����

// **************************** �÷� ����ϱ� Define �� **************************** //

#define colorHandle GetStdHandle(STD_OUTPUT_HANDLE) //�ܼ�â�� �ڵ����� �ޱ�
#define BLACK SetConsoleTextAttribute(colorHandle, 0x0000); //������
#define GRAY SetConsoleTextAttribute(colorHandle, 0x0007); //���� ȸ��
#define RED SetConsoleTextAttribute(colorHandle, 0x000c); //������
#define BLUE SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008); //�Ķ���
#define WHITE SetConsoleTextAttribute(colorHandle, 0x000f); //�Ͼ��
#define YEL SetConsoleTextAttribute(colorHandle, 0x000e); //�����
#define GREEN SetConsoleTextAttribute(colorHandle, 0x0002) ; //���
#define VIO SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008 |0x000c); //�����

// **************************** Ŀ�� ����� ��ũ�� **************************** //

enum { HIDDEN, SHOW };  //������ enum ����

// **************************** �̷��Լ� ����Ű �ƽ�Ű�ڵ尪 **************************** //

#define LEFT 75 //���� ����Ű
#define RIGHT 77 //���� ����Ű
#define UP 72 //���ʹ���Ű
#define DOWN 80 //�Ʒ��� ����Ű
#define Enter 13 //���Ͱ�
#define ESC 27 //esc��

// **************************** System �Լ� **************************** //
void gotoxy(int, int); //x��,y�� �̵������ִ� �Լ�
void delay(clock_t wait); //������ �Լ� �ð� ���ʸ� ����ϱ� ���� �Լ�
void color(unsigned short color); // ���� �÷��� �ֱ� ���� �Լ�
void viewCursor(char show); //Ŀ���� ����ų� �����ش�.

// **************************** �̷�Ż����� �Լ� **************************** //
void miro();    //�̷ΰ��� ���� �Լ�
int miroGame(); //���� ���� ,ȭ�� ����� �����ϴ� �Լ�

int main() {

	miro(); //�̷ΰ��� ���� �Լ� ȣ��
	return 0;

}

void miro()
{
	int n; 
	n = miroGame(); //miroGame()�ϰ� ��ȯ�� ���� n�� �����Ѵ�. 
}

void gotoxy(int x, int y) //x��,y�� �̵������ִ� �Լ�
{
	COORD pos = { x,y }; //COORD�� x���� y���� ���� ����ü�� <window.h>�� ���ԵǾ��ִ�. ����ü ������ ����.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //SetConsoleCursorPosition �Լ��� �Ű������� ���� �ܼ� ��ũ�� ���ۿ� Ư�� Ŀ�� ��ǥ�� ������ �ش� �ܼ� ��ũ�� ������ Ŀ�� ��ǥ�� �� ��ǥ�� �ٲ��ִ� ����

}

void color(unsigned short color) //������ �÷� ��������� �Լ�
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� ��ũ�� �ڵ鰡������
	SetConsoleTextAttribute(hCon, color); //�ܼ�â�� ��� ������ color�� ����Ҽ� �ְ� �Ѵ�.
}

void viewCursor(char show) //Ŀ�� ����� / ���̱�
{
	HANDLE hConsole;//�ܼ� �ڵ�
	CONSOLE_CURSOR_INFO ConsoleCursor;//�ܼ�Ŀ�� ���� ����ü

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//�ڵ��� ���ϰ�

	ConsoleCursor.bVisible = show; //Ŀ��ǥ�� show 
	ConsoleCursor.dwSize = 1; //Ŀ�� ����� 1�� �Ѵ�.

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);//����
}

void delay(clock_t wait) //�ð��� ������Ű�� �Լ�
{
	//wait ms ��ŭ ��� 1000 = 1 ��
	clock_t goal;//	clock_t ���� goal
	goal = wait + clock(); //���ð� + ����ð�
	while (goal > clock()); //goal�� ����ð����� Ŭ�� ���� ��� �ݺ�
}

int miroGame() {
	struct MIRO //MIRO����ü
	{
		int x, y; //x,y�� ��ǥ
		int PlayN; //���ӻ���(?)
};
	struct MIRO Me, Mon[20], Pre[10]; //MIRO����ü�� Me, ũ�Ⱑ 20�� Mon, ũ�Ⱑ 10�� Pre �迭 ������ �����Ѵ�.
	static int Stage = 1, PreNum; //Stage�� ǥ������ ������ ��Ʈ�� ����PreNum
	static int i, j, k = 0,T=0, b, c[20][2] = { 0 }, d[30] = { 0 }; //�ݺ����� ���� ����,������ ���� �����ϱ����� ����,�迭
	static int Screen[18][28] = { 0 }; //����ȭ���� ��üũ��
	int randNum[2] = { 0 };//�������� �ֱ����� ũ�Ⱑ 2�� �迭
	char ch;//Ű���� �Է� �ƽ�Ű�ڵ尪�� �ޱ� ���� ����
	int Life = 3, LifeN, GameOver = 0;//����� 3���� �־�����. //����� ����, �������� ����

	srand(time(NULL)); //seed

	system("mode con lines=20 cols=58"); // â ũ�� line = y��, cols = x��, lins�� -1 ũ�� ��� //�ܼ�â�� ũ������
	system("cls"); //�ܼ�â ��ü ���������
	viewCursor(HIDDEN);//Ŀ���� �����.
	system("cls"); //�ܼ�â ��ü ���������

	while (1) {
		randNum[0] = 0; //randNum 0��° �迭�� 0���� �ʱ�ȭ�Ѵ�.
		randNum[1] = 0; //randNum 1��° �迭�� 0���� �ʱ�ȭ�Ѵ�.

		gotoxy(22, 9); //Ŀ���� ��ġ�� (22,9)�� �̵���Ų��.
		printf("S t a g e %d", Stage); //���� ���������� ������ �˷��ش�.
		Sleep(3000);//3�ʸ� ������Ų��.
		system("cls");//�ܼ�â ��ü ���������

		b = rand() % 14 + 2; //b�� 2~15�� ���� �������� �ִ´�.

		for (i = 0; i < Stage *2; i++) { //i�� 0���� ���������� 2�� ���Ѽ� ������ �ݺ��Ѵ�.
			c[i][0] = rand() % 14 + 2; //���� 0�� ���� i�� c�迭�� 2~15������ ���� �������� �޴´�.
			c[i][1] = rand() % 22 + 3; //���� 1�� ���� i�� c�迭�� 3~24������ ���� �������� �޴´�.
		 }
		for (i = 0; i < 35; i++) { //i�� 0���� 35������ �ݺ��Ѵ�.
			d[i] = rand() % 26 + 1; //i��° d�迭�� 1~26���� �������� �ִ´�.
		}

		Me.x = 7; //Me�� x��ǥ�� 7�� �ִ´�.
		Me.y = 1; //Me�� y��ǥ�� 1�� �ִ´�.
		Me.PlayN = 1; //Me�� PlayN�� ������ 1�� �ʱ�ȭ�Ѵ�. 

		for (i = 0; i < Stage * 2; i++) { //i�� 0���� ���������� 2�� ���Ѽ� ������ �ݺ��Ѵ�.
			Mon[i].x = c[i][0]; //i��° Mon�� x��ǥ�� ���� 0�� ���� i�� c�迭���� �ִ´�.
			Mon[i].y = c[i][1]; //i��° Mon�� y��ǥ�� ���� 1�� ���� i�� c�迭���� �ִ´�.
			Mon[i].PlayN = 10; //i��° Mon��PlayN�� 10���� �����Ѵ�.
		}

		for (i = 0; i < Stage ; i++) { //i�� 0���� ���������� ������ �ݺ��Ѵ�.
			Pre[i].x = c[i][0]; //i��° Pre�� x��ǥ�� ���� 0�� ���� i�� c�迭���� �ִ´�.
			Pre[i].y = c[i][1] + 1; //i��° Pre�� y��ǥ�� ���� 1�� ���� i�� c�迭��+1�� �ִ´�.
			Pre[i].PlayN = 7; //i��° Pre��PlayN�� 7���� �����Ѵ�.
		}

		for (i = 0; i < 18; i++) { //�ʱ�ȭ��Ų��.
			for (j = 0; j < 28; j++)
			{
				Screen[i][j] = 0;
			}
		}

		k = 0; // k�� 0�� �����Ѵ�.
		for (i = 0; i < 18; i++) //������
		{
			for (j = 0; j < 28; j++)
			{
				if (i == 0 || i == 17) //���� 0�̳� 17�� ���� ������
					Screen[i][j] = 9;
				else if (j == 0 || j == 27) //���� 0�̳� 27�� ���� ������
					Screen[i][j] = 9;
			}
		}
		for (i = 1; i < 18; i++) { //���� ������
			for (j = 0; j < 28; j++) {
				if (d[k] == j) { //k��°d�迭�� ���� j���
					Screen[i][j] = 9; //����i ����j�� ���� ������
					k++;//k�ϳ� ����
				}
			}
		}

		Screen[b][26] = 0;//�ⱸ���� �������� ���� �ʵ��� �Ѵ�.
		Screen[b][27] = 0;//�ⱸ 
		Screen[7][1] = 1; //�ʱ�ȭ
		Screen[6][1] = 0;//Me�� ������ �ٷ� ������ �������� ���� �ʵ��� �Ѵ�.

		for (i = 0; i< Stage * 2; i++) {//i�� 0���� ���������� 2�� ���Ѽ� ������ �ݺ��Ѵ�.
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//Screen[Mon[i].x][Mon[i].y]�� Mon[0].PlayN���� �ִ´�.
		}
		for (i = 0; i < Stage; i++) {//i�� 0���� ���������� 2�� ���Ѽ� ������ �ݺ��Ѵ�.
			Screen[Pre[i].x][Pre[i].y] = Pre[0].PlayN; //Screen[Pre[i].x][Pre[i].y]�� Pre[0].PlayN���� �ִ´�.
		}

		while (1) { //���ѷ���
			PreNum = 0; //��Ʈ������ 0���� �Ѵ�.
			for (i = 0; i < Stage * 2; i++) {//i�� 0���� ���������� 2�� ���Ѽ� ������ �ݺ��Ѵ�.
				randNum[0] = rand() % 15; //randNum[0]�� 0~14�� �ϳ��� ���� �������� �ִ´�.
				if (randNum[0] == 0) { //randNum[0]�� 0�̶��
					randNum[1] = rand() % 4;//randNum[1]�� 0~3�� �ϳ��� ���� �������� �ִ´�.
					switch (randNum[1]) {//randNum[1]�� ����
					case 0 ://0�̶��
						if (Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN) {
							//ȭ�鿡�� ��ֹ��� �������� ������ ���� �ƴϰ�, �ٸ� ��ֹ��� ����, ��Ʈ�� �ƴѰ��
							Screen[Mon[i].x][Mon[i].y] = 0; //���� ��ֹ��� ��ġ���� ��ֹ��� ���ش�.
							Mon[i].y -= 1; //��ֹ��� y���� �ϳ� ���δ�.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) //���� ��ֹ��� �����϶� Me�� ������
								Me.PlayN = 99; //Me.PlayN�� 99�� �Ѵ�.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; //ȭ�鿡 Mon��(x,y)�� Mon�� ���δ�.
						break; //����
					case 1 ://1�̶��
						if (Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN) {
							//ȭ�鿡�� ��ֹ��� ���������� ������ ���� �ƴϰ�, �ٸ� ��ֹ��� ����, ��Ʈ�� �ƴѰ��
							Screen[Mon[i].x][Mon[i].y] = 0;//���� ��ֹ��� ��ġ���� ��ֹ��� ���ش�.
							Mon[i].y += 1;//��ֹ��� y���� �ϳ� �ø���.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//���� ��ֹ��� �����϶� Me�� ������
								Me.PlayN = 99;//Me.PlayN�� 99�� �Ѵ�.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//ȭ�鿡 Mon��(x,y)�� Mon�� ���δ�.
						break; //������
					case 2://2���
						if (Screen[Mon[i].x-1][Mon[i].y ] != 9 && Screen[Mon[i].x-1][Mon[i].y ] != Mon[i].PlayN && Screen[Mon[i].x-1][Mon[i].y ] != Pre[0].PlayN) {
							//ȭ�鿡�� ��ֹ��� �������� ������ ���� �ƴϰ�, �ٸ� ��ֹ��� ����, ��Ʈ�� �ƴѰ��
							Screen[Mon[i].x][Mon[i].y] = 0;//���� ��ֹ��� ��ġ���� ��ֹ��� ���ش�.
							Mon[i].x -= 1;//��ֹ��� x���� �ϳ� ���δ�.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//���� ��ֹ��� �����϶� Me�� ������
								Me.PlayN = 99;//Me.PlayN�� 99�� �Ѵ�.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//ȭ�鿡 Mon��(x,y)�� Mon�� ���δ�.
						break; //����
					case 3://3�̶��
						if (Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN) {
							//ȭ�鿡�� ��ֹ��� �Ʒ������� ������ ���� �ƴϰ�, �ٸ� ��ֹ��� ����, ��Ʈ�� �ƴѰ��
							Screen[Mon[i].x][Mon[i].y] = 0;//���� ��ֹ��� ��ġ���� ��ֹ��� ���ش�.
							Mon[i].x += 1;//��ֹ��� x���� �ϳ� �ø���.
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//���� ��ֹ��� �����϶� Me�� ������
								Me.PlayN = 99;//Me.PlayN�� 99�� �Ѵ�.
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;//ȭ�鿡 Mon��(x,y)�� Mon�� ���δ�.
						break; //�Ʒ���
					}
				}
			}

			for (i = 0; i < 18; i++) { //���� ���
				gotoxy(1, i + 1); //x�� 1, y�� i+1�� Ŀ���� �̵��Ѵ�.
			for (j = 0; j < 28; j++) {
				if (Screen[i][j] == 0) { //Screen ���� i�̰� ���� j�϶� ���� 0�̶��
					BLACK; //������
					printf("��"); //���� ����Ѵ�.
				}//�����ϼ��ִ� ����
				else if (Screen[i][j] == Me.PlayN) { //Screen ���� i�̰� ���� j�϶� ���� Me.PlayN���̶��
					RED; //������
					printf("��"); //���� ����Ѵ�.
				}//�����(Me)
				else if (Screen[i][j] == 9) { //Screen ���� i�̰� ���� j�϶� ���� 9���
					WHITE; //���
					printf("��"); //�׸� ����Ѵ�.
				}//��
				else if (Screen[i][j] == Mon[0].PlayN) { //Screen ���� i�̰� ���� j�϶� ���� Mon[0]�� PlayN���̶��
					VIO;//�����
					printf("��");//���̾Ƹ�带 ����Ѵ�.
				}//��ֹ�
				else if (Screen[i][j] == Pre[0].PlayN) { //Screen ���� i�̰� ���� j�϶� ���� Pre[0].PlayN���̶�� 
					YEL;//�����
					printf("��");//��Ʈ�� ����Ѵ�.
				}//����?? Me�� �Ծ���ϴ� ��
			}
			printf("\n");
		}

		if (kbhit()) {//kbhit() Ű �Է¿���.. �Է��� ������ 1, ������ 0
			ch = getch(); //�Էµ� key�� �ƽ�Ű�ڵ尪 ��ȯ �� ch�� ����
			switch (ch) { //ch�� ����
			case 75 : //75�� ��� ����
				  if(Screen[Me.x][Me.y - 1] != 9 ) //ȭ�鿡�� Me�� ����(y��-1)�� ���� �ƴ϶�� 
			   { Screen[Me.x][Me.y] = 0;//ȭ�鿡�� ���� �ִ����� 0���� Me�� ���ְ�
					Me.y -= 1;//Me�� y���� -1�Ͽ� �������� ��ĭ �̵��ѵ�
					if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99; //���� Me��(x,y)�ڸ��� ��ֹ��ڸ���� Me.PlayN�� 99�� �����Ѵ�.
			   }
				  Screen[Me.x][Me.y] = Me.PlayN; //ȭ�鿡 Me��(x,y)�� Me�� ���δ�.

				break;//����
			case 77://77�� ��� ������ 
			 if(Screen[Me.x][Me.y + 1] != 9 ) //ȭ�鿡�� Me�� ������(y��+1)�� ���� �ƴ϶�� 
			   {Screen[Me.x][Me.y] = 0;//ȭ�鿡�� ���� �ִ����� 0���� Me�� ���ְ�
				   Me.y += 1;//Me�� y���� +1�Ͽ� ���������� ��ĭ �̵��ѵ�
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99;//���� Me��(x,y)�ڸ��� ��ֹ��ڸ���� Me.PlayN�� 99�� �����Ѵ�.
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;//ȭ�鿡 Me��(x,y)�� Me�� ���δ�.
				break; //������
			case 72://72�� ��� ����
				 if(Screen[Me.x - 1][Me.y] != 9 )//ȭ�鿡�� Me�� ����(x��-1)�� ���� �ƴ϶�� 
			   {
				   Screen[Me.x][Me.y] = 0;//ȭ�鿡�� ���� �ִ����� 0���� Me�� ���ְ�
				   Me.x -= 1;//Me�� x���� -1�Ͽ� �������� ��ĭ �̵��ѵ�
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99;//���� Me��(x,y)�ڸ��� ��ֹ��ڸ���� Me.PlayN�� 99�� �����Ѵ�.
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;//ȭ�鿡 Me��(x,y)�� Me�� ���δ�.
				break; //����
			case 80 ://80�ϰ�� �Ʒ���
			 if(Screen[Me.x + 1][Me.y] != 9 )//ȭ�鿡�� Me�� �Ʒ���(x��+1)�� ���� �ƴ϶�� 
			   {
				   Screen[Me.x][Me.y] = 0;//ȭ�鿡�� ���� �ִ����� 0���� Me�� ���ְ�
				   Me.x += 1;//Me�� x���� +1�Ͽ� �Ʒ������� ��ĭ �̵��ѵ�
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN=99;//���� Me��(x,y)�ڸ��� ��ֹ��ڸ���� Me.PlayN�� 99�� �����Ѵ�.
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;//ȭ�鿡 Me��(x,y)�� Me�� ���δ�.
				break;//�Ʒ���
			case ESC: break; //esc�� ������ ����
			}
		}

		if (ch == ESC) break; //esc�� ������ ����

		LifeN = Life; //LifeN�� Life���� �����Ѵ�.
		if (Me.PlayN == 99) {//Me�� PlayN�� 99�̸� //��ֹ��� �����ٴ� �ǹ�
			Life -= 1; //������ �ϳ� ���δ�.
			break; //���� �ٽ� �ϱ�
		}
		for (i = 0; i < 18; i++) {
			for (j = 0; j < 28; j++) {
				if (Screen[i][j] == Pre[0].PlayN) { //Screen i�� j���� ���� Pre[0].PlayN�� ���ٸ�
					PreNum++; //PreNum���� �ϳ� ������Ų��.
				}
			}
		}

		if (PreNum == 0) { //��Ʈ�� ����
			if (Me.y == 27) break; //Me�� y�ڸ��� 27(�ⱸ)��� break�Ѵ�. //�̹� �������� ��
		}
	} 
	if(ch==ESC) break;//esc�� ������ ����

	if(Life!=0 && Stage !=11){ //���� Life�� 0�̾ƴϰ�, Stage�� 11�� �ƴ϶��(������������ �̵�)
		if(LifeN == Life){//���� LifeN�� Lif�� ���� ���ٸ�
		Stage += 1; //�������� ���� �ϳ� �ø���.
		system("cls");//�ܼ�â ��ü ���������
		gotoxy(16,9);//Ŀ���� (16,9)�� �̵���Ų��.
		printf("S t a g e  C l e a r !!"); //���������� Ʋ���� �ߴٴ� �޼��� ���
		Sleep(3000);//3�ʸ� ������Ų��.
		system("cls");//�ܼ�â ��ü ���������
		}else{//(�׾��ٸ�)
			gotoxy(19,10);//Ŀ���� (19,10)�� �̵���Ų��.
			printf("G a m e o v e r ! !"); //�����̳����ٴ� �޼��� ���
			Sleep(3000);//3�ʸ� ������Ų��.
			system("cls");//�ܼ�â ��ü ���������
			gotoxy(26,9);//Ŀ���� (26,9)�� �̵���Ų��.
			WHITE;//���
			printf(" = %d",Life);//���� ������ �˷��ش�.
			Sleep(3000);//3�ʸ� ������Ų��.
			system("cls");//�ܼ�â ��ü ���������
			GRAY;//ȸ��
		}
	}
	if(Life ==0){//������ ���ٸ�(������ ������ ��)
	gotoxy(19,10);//Ŀ���� (19,10)�� �̵���Ų��.
			printf("G a m e o v e r ! !");//�����̳����ٴ� �޼��� ���
			Sleep(3000);//3�ʸ� ������Ų��.
			system("cls");//�ܼ�â ��ü ���������
			break;
	}
	else if(Stage ==11){//���� ���������� 11�̶��(��� �������� ���� Ŭ����)
		system("cls");//�ܼ�â ��ü ���������
		WHITE;//���
		gotoxy(14,9);//Ŀ���� (14,9)�� �̵���Ų��.
		printf(" C o n g r a t u l a t i o n ");//�����Ѵٴ� �޼��� ���
		Sleep(3000);//3�ʸ� ������Ų��.
			system("cls");//�ܼ�â ��ü ���������
			gotoxy(19,9);//Ŀ���� (19,9)�� �̵���Ų��.
			printf("T h e E n d ! !");//������ ���̶�� �޼��� ���
			Sleep(4000);//4�ʸ� ������Ų��.
			GRAY;//ȸ��
			break;
	}
	}
	return 0;
	}