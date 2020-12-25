#include <stdio.h>

int prime_check(int checkNum); //양수를 매개변수로 반아 소수 인지를 판단하는 메소드

int main(void) {

	int n,i; //입력받기위한 변수, 소수를 찾아 출력할 변수를 생성한다.
	int a=0; //한줄에 3개씩 출력하기 위하여 출력하는 소수가 몇번째 소수인지 알수 있는 변수를 만든다.

	printf("수를 입력하세요 : ");
	scanf_s("%d", &n); //수를 n에 입력받는다. 정수형 변환명세 %d를 사용한다.
	

	if (n < 2 ) {} // 입력받은 수가 2보다 작을경우 프로그램을 종료한다.
	else { //입력받은 수가 2이상일 경우
		for (i = 2; i <= n; i++) { 
			// 가장 작은 소수가 2이므로 for문을 이용해서 2부터 입력한수 n까지 소수인지를 판단할수있도록 한다. 			
			if (prime_check(i) == 0) { //리턴값이 0일경우 소수이므로 출력할 수 있도록한다.
				printf(" %d\t", i); //i를 출력한다. 줄을 맞추기 위해서 \t을 사용한다.
				a++; // 소수가 몇번째 소수인지 알수있도록 증감연산자를 이용한다.
				if((a) %3 ==0) //소수가 3배수번째인 경우 
				{	printf("\n");} //다음줄로 내려간다.
			}
		}
	}

}


int prime_check(int checkNum) {
	int num; //checkNum이 1인아닌 자연수의 배수인지를 알아보기 위해서 만든 변수
	if (checkNum == 2) { //checkNum이 2인경우 짝수에서 유일한 소수이므로 0을 리턴한다.
		return 0;
	}
	
	else {
		for (num = 2; num < checkNum; num++) { //num이 checkNum보다 작은 수 일때 checkNum의 약수인지를 알아보기 위해서 for문을 이용한다.
			if (checkNum % num == 0) { return 1;  } //checkNum을 num로 나눈 나머지가 0일경우 checkNum은 소수가 아니므로 1을 리턴한다.
		}
		return 0; //그것이 아니라면 checkNum은 소수이므로 0을 리턴한다.
	}


}



