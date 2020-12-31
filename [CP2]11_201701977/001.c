#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dup_check(char **sp,char *temp, int cnt); //이미 있는 단어인지 체크하는 메소드

int main(void){

	char temp[100]; //임시 char 배열
	char *word[100] ={0};//동적할당 영역을 연결할 포인터 배열
	char endWord,startWord; // 끝말잇기를 위해서 전단어의 마지막 알파벳과 입력단어의 첫 알파벳을 저장하기위한 문자형 변수
	int i=0; //반복문을 위한 정수형 변수

	


	while(i<100) //100개의 단어까지만 입력받기위한 조건식
{
		printf("단어입력 : "); 
		gets(temp); // 문자열 입력
		
		if(strcmp(temp,"end") == 0){break;} //end가 입력되면 반복 종료

		startWord = temp[0]; //입력받은 단어의 첫번째 알파벳을 저장한다.

		if(i!=0){ //만약 i가 0이 아닐경우 (0이라면 시작하는 단어 이기때문에 중복될일도 이어지지 않을 일도 없다.)
		while(dup_check(word,temp,i)==0 || endWord != startWord){ // 단어가 이미 있거나 전 단어와 이어지지않는 경우
			if(dup_check(word,temp,i)==0){printf(">이미 존재하는 단어입니다!\n");} //만약 단어가 이미 있는 경우에 이 메세지를 출력한다.
			else{	printf(">단어 잇기가 불가능합니다!\n");} //아닌경우(이어지지 않는 경우) 이 메세지를 출력한다.
			printf("단어입력 : "); 
			gets(temp); //다시 문자열을 입력받는다.
			if(strcmp(temp,"end") == 0){break;} //end가 입력되면 반복 종료
			startWord = temp[0]; //입력받은 단어의 첫번째 알파벳을 저장한다.
		}
		if(strcmp(temp,"end") == 0){break;} //end가 입력되면 반복 종료
		} 
		endWord = temp[strlen(temp)-1]; //입력받은 단어의 마지막 알파벳을 저장한다.

		word[i] = (char *) malloc (strlen(temp) +1); //문자열 저장 공간 할당
		strcpy(word[i],temp); //동적 할당 영역에 문자열 복사
		i++; //i를 하나 증가시킨다.

	}
	
	


	if(i==100) //만약 i가 100이라면 end가 아닌 단어를 100개 입력해서 나온것이므로
	{
		printf("입력가능 단어수 100가 넘었습니다.\n"); //더이상 입력이 되지 않는다는 메세지를 출력한다.
	}


	for(i=0;word[i]!=NULL;i++){ //word에 연결된 문자열이 없을 때까지
	printf("%s ",word[i]); //word에 연결된 문자열 출력
	}

	for(i=0;word[i]!=NULL;i++){ //word에 연결된 문자열이 없을 때까지
		free(word[i]); //동적 할당 영역 반환
	}
	return 0;
	
}

int dup_check(char **sp,char *temp, int cnt)//이미 있는 단어인지 체크하는 메소드
{
	int i; //반복문을 위한 정수형 변수
	for(i=0;i<cnt;i++){ //word에 저장된 단어의 개수만큼 반복
		if(strcmp(*sp++,temp) == 0){ //sp가 가리키는 포인터 배열의 요소와 temp와 같은 단어일 경우
		return 0;} //0을 리턴한다.
	}
	
	return 1; //중복단어가 없을 경우 1을 리턴한다.
}