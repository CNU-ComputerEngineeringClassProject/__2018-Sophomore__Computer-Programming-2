#include <stdio.h>
#include <string.h>

void init_intro(char (*intro)[80], char **intp); //전달받은 intro의 주소를 intp로 복사하는 메소드
int input_intro(char (*intro)[80]); //문장을 입력받는 메소드 /end가 입력되면 입력종료 / end는 입력되지않음
void sort_intro(char **intp, int cnt); //사전순으로 정렬하는 메소드
void print_intro(int mode, void *vp, int cnt); //배열을 출력하는 메소드
int assign03(void); //배열을 생성하고 메인함수 대신 함수들을 호출하는 메소드

int main(void){
	assign03(); //함수를 호출한다.
	return 0;
}
void init_intro(char (*intro)[80], char **intp){//전달받은 intro의 주소를 intp로 복사하는 메소드
	int i=0; //반복문을 위한 정수형 변수

	for(i=0;i<10;i++){ //i가 0부터 10보다 작을때만 반복한다.(하나씩 증가)
		intp[i] = intro[i]; //i번째 intp배열의 자리에 i번째 intro배열의 주소를 저장한다.
	}
}
int input_intro(char (*intro)[80]){ //문장을 입력받는 메소드 /end가 입력되면 입력 종료 /end는 입력되지 않음 (매개변수는 문자형 변수 80개의 배열을 가리키는 배열포인터를 입력받는다.)

	int num=0; //문장의 개수를 저장하기위한 정수형 변수. 0으로 초기화 한다.

	printf(">문장 입력: ");
	scanf("%s",intro[num]); //문장을 입력받아 num번째 배열에 넣는다.

	while(strcmp(intro[num],"end") != 0){ //num번째 배열의 원소가 end이 아닐경우 (end라면 "end"와 비교했을때 일치하기때문에 0값이 나오므로) 
		++num; //num을 하나 증가시킨다.
		printf(">문장 입력: ");
		scanf("%s",&intro[num]); //문장을 입력받아 num번째 배열에 넣는다.
	}

	//end를 입력받아 입력을 종료시키고, 입력받은 end를 배열에서 없앤다.
	intro[num][0]='\0'; 
	intro[num][1]='\0';
	intro[num][2]='\0';

	return num; //num을 리턴한다.
}
void sort_intro(char **intp, int cnt){ //사전순으로 정렬하는 메소드 (매개변수로 문자형 이중포인터 변수하나와 정수형 변수하나를 입력받는다.)
	int i,j; //반복문을 위한 정수형 변수
	char *copy[80]={0}; // 80개의 char형 포인터 변수를 저장할수있는 포인터 배열을 선언하고 초기화한다.


	for(i=0;i<cnt;i++){ //i가 0부터 cnt보다 작을때만 반복한다.(하나씩 증가)
		for(j= i+1;j< cnt;j++){ //j가 i+1부터 cnt보다 작을때만 반복한다. (하나씩증가) i번째 이전은 이미 비교를 하고 정렬되어있다. 그러므로 이후 문장들과만 비교하면 되기때문에 j=i+1이 초기값이다.

			if(strcmp(intp[i],intp[j])>=1){ //i번째 배열과 j번째 배열을 비교해서 1보다 크다면(i번째 배열의 문장이 사전순으로 나중에 나오는 것이므로 바꿔야한다.)
				*copy = intp[i]; // copy에 간점참조하여 그자리에 i번째 배열의 문장을 넣는다.
				intp[i] = intp[j]; //i번째 배열의 원소자리에 j번째 배열 원소값을 넣는다.
				intp[j] = *copy; //j번째 배열의 원소자리에 copy에 간접참조를 하여 그값을 저장한다.
			}
		}
	}


}
void print_intro(int mode, void *vp, int cnt){ //배열을 출력하는 메소드 (매개변수로 두개의 정수형 변수와 하나의 void 포인터를 입력받는다.)

	int i; //반복문을 위한 정수형 변수
	char **a; //문자형 이중포인터 a를 선언한다. 
	char *b; //문자형 포인터 b를 선언한다.

	if(mode == 1){ //만약 mode가 1이라면 (사전순)
		printf("\n\n사전순으로 출력...\n");
		a=(char **)vp; //vp를 문자형 이중포인터로 형변환하여 a에 저장한다.
		for(i=0;i<cnt;i++){ //i가 0부터 cnt보다 작을때만 반복한다. (하나씩 증가)
			printf("%s\n", *(a+i) ); //(a+i)가 가리키는 변수를 참조하여 출력한다.

		}
	}
	else if(mode == 0){ //만약 mode가 0이라면(입력순)
		printf("\n\n입력순으로 출력...\n");
		b = (char *)vp; //vp를 문자형 포인터로 형변환하여 b에 저장한다.
		for(i=0;i<cnt;i++){ //i가 0부터 cnt보다 작을때만 반복한다. (하나씩 증가)
				printf("%s\n", b + (i*80)); // b + (i*80)의 값을 출력한다.
		}
	}
}
int assign03(void){

	char intro[10][80] ={0}; //크기가 행이 10이고 열이 80인 문자형 배열을 생성하고 초기화한다.
	char *intp[10]={0}; // 10개의 char형 포인터 변수를 저장할수있는 포인터 배열을 선언하고 초기화한다.
	int cnt; //문자열의 개수를 나타내는 정수형 변수

	init_intro(intro, intp); ////전달받은 intro의 주소를 intp로 복사하도록 함수를 호출한다.
	cnt= input_intro(intro); // 함수를 호출하여 문장을 입력받고 문장의 개수를 리턴하여 cnt에 저장한다.
	sort_intro(intp,cnt); //사전순으로 정렬되도록 함수를 호출한다.
	print_intro(1, intp, cnt); //사전순으로 정렬된 문자열 배열을 출력하도록 함수를 호출한다.
	print_intro(0, intro, cnt); //입력순으로 정렬된 문자열 배열을 출력하도록 함수를 호출한다.


	return 0;
}