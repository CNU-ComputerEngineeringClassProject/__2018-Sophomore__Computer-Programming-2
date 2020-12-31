#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	char temp[32]; // 임시 char배열
	char *ps, *pt; // 할당한 저장 공간을 연결할 포인터
	int len =1; //
	ps = (char *)calloc(1,1); //1개의 저장공간을 할당한다.
	while (1){ 
		printf("메모입력 : ");
		fgets(temp, sizeof(temp), stdin); //stdin으로부터 문자열을 입력받아서 배열 temp의 길이 만큼 배열에 저장
		temp[strlen(temp) -1] = '\0'; // temp의 문자열 마지막에 있는 개행문자를 널문자로 바꿔 넣는다.
		if(strcmp(temp, "end") == 0) break; //end가 입력되면 반복 종료
		len += strlen(temp) +1; // len와 temp 문자열의 길이+1을 더하여 len에 저장한다.
		pt = (char*) realloc(ps, len); //  ps 길이가 len인 char형 배열로 확장하여 재할당한 메모리 주소를 pt에 저장한다.
		if (pt == NULL) //동적할당에 실패하면 NULL 포인터 반환
		{
		printf("메모리 부족...\n"); //메세지 출력
		break; //종료
		}
		ps=pt; // 배열이 성공적으로 재할당되었다면 ps에 ps를 새로 재할당된 pt를 할당한다.
		strcat(ps, temp); //ps안의 문자열에 temp를 이어붙인다.
		strcat(ps, " "); //temp를 넣은 바로 다음 자리에 " "(white space)를 붙인다.
	}
	printf("%s\n",ps); //입력한 데이터 출력
	free(ps); //동적 할당 저장 공간 반납
	return 0;
}