#include <stdio.h>
#define MAX 100 //매크로 상수를 이용한다.

void invertedOutput(char str[]); //문자열을 역순으로 만들어서 출력하기 위한 함수


int main(void) {

	char str[MAX]={0}; //매크로상수를 이용하여 str배열의 크기를 지정하고 배열을 초기화 한다.

	printf("한 줄을 입력하세요. >>\n"); 
	
	gets(str); //gets를 이용하여 문자열을 입력받는다.

	invertedOutput(str); //문자열을 거꾸로 출력하는 함수를 호출한다.

	return 0;
}


void invertedOutput(char str[]) {

	int i;

	printf("\n위에서 입력한 문자열을 거꾸로 출력합니다.\n");

	for (i = MAX-1; i >= 0; i--) { //거꾸로 출력하기 위하여 i를 max-1부터 0까지 하나씩 감소시키며 반복한다.
		if(str[i] == 32){ //만약 i번째 str배열이 ' '(아스키코드로 32) 값일 경우 
		printf(" "); //" "를 출력한다.
		}
		else if(str[i]=='\0'){} //i번째 배열이 '\0'일경우 아무것도 출력하지 않는다. (초기화 했으므로 입력받지 않은 i번째 배열은 '\0'일것이다.)
		else{
			printf("%c",str[i]); //위 두경우가 아니라면 i번째 배열을 출력한다. (문자형이므로 %c 변환명세를 이용한다.)
		}
	}
	printf("\n"); 
}