#include <stdio.h>
/*입력이 50이상일경우 long long형을 쓰더라도
결국 long long형의 값 저장크기를 벗어날것이다.
그러면 음수가 출력되게 된다.

조금이라도 큰 수를 출력하기 위해서는 unsigned long long형을 사용한다.
unsigned long long형도 저장크기를 벗어날수 있지만
long long형보다는 더 큰 값을 출력할수있다.

이는 피보나치 수열이 양의 정수만 출력하기때문에 가능하다.*/

long long fib(int num); //40 이상일경우 int형의 값 최대 저장크기를 넘겨버린다. 그러므로 long long형을 사용하여 크기를 늘린다.

int main(void) {
	int n = 1;
	 int i;



printf("음수가 아닌 수를 입력하세요 : ");
		scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		printf("%lld ", fib(i)); //long long 형의 출력 변환문자 %lld를 사용한다.
		
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