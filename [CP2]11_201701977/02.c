#include <stdio.h>

struct cracker{ //cracker���� ����ü ����
	int price; //������ ������ ���
	int calories; //������ ������ ���
};

int main(void){
	struct cracker basasak; //cracker ����ü ���� ����
	printf("�ٻ���� ���ݰ� ������ �Է��ϼ��� : ");
	scanf("%d %d",&basasak.price, &basasak.calories); //���ݰ� ������ �Է� �ް� ���� price����� calories����� �����Ѵ�.
	printf("�ٻ���� ���� : %d��\n", basasak.price); //price����� ���� ����Ѵ�. (���� ���)
	printf("�ٻ���� ���� : %dkcal\n",basasak.calories); //calories����� ���� ����Ѵ�. (���� ���)

	return 0;
}