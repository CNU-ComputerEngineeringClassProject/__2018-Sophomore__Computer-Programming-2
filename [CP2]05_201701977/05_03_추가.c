#include <stdio.h>
/*�Է��� 50�̻��ϰ�� long long���� ������
�ᱹ long long���� �� ����ũ�⸦ ������̴�.
�׷��� ������ ��µǰ� �ȴ�.

�����̶� ū ���� ����ϱ� ���ؼ��� unsigned long long���� ����Ѵ�.
unsigned long long���� ����ũ�⸦ ����� ������
long long�����ٴ� �� ū ���� ����Ҽ��ִ�.

�̴� �Ǻ���ġ ������ ���� ������ ����ϱ⶧���� �����ϴ�.*/

long long fib(int num); //40 �̻��ϰ�� int���� �� �ִ� ����ũ�⸦ �Ѱܹ�����. �׷��Ƿ� long long���� ����Ͽ� ũ�⸦ �ø���.

int main(void) {
	int n = 1;
	 int i;



printf("������ �ƴ� ���� �Է��ϼ��� : ");
		scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		printf("%lld ", fib(i)); //long long ���� ��� ��ȯ���� %lld�� ����Ѵ�.
		
	}
	

	return 0;
}

long long fib(int num) {
	if (num <= 1) {
		return 1;
	}
	else {
		return fib(num - 1) + fib(num - 2);
	}
}