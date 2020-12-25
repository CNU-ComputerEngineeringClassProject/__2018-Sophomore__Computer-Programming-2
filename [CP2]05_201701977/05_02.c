#include <stdio.h>

int fib(int num); //피보나치 수열을 만들기위한 메소드

int main(void) {
	int n = 12; //1년후(12개월)를 알고 싶은 것이므로 12를 값으로 넣는다.
	int i; // 0항부터 n-1항까지 알기위해서 정수형 변수 i를 생성한다.

	for (i =0; i < n; i++) { //0항부터 n-1항까지 알기위해서 for문을 이용한다.
		printf("%d " , fib(i)); //피보나치 수열을 계산해서 출력한다.
	}

	return 0;
}

int fib(int num) { 
	if (num <= 1) { return 1;} //num이 0이거나 1일경우 1값을 리턴한다.
	else {
		return fib(num - 1) + fib(num - 2);
		//그외에 경우에는 num의 전수(n-1)와 전전수(n-2)의 피보나치 값을 더한 값을 리턴한다.
	}
}