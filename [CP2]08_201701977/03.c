
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20 //사이즈 최대값을 입력한 매크로 상수


void makeBingo(int * bingoArray, int inputSize) ; // inputSize*inputSize 빙고판을 생성하는 함수
void printBingo (int * bingoArray, int inputSize) ; //빙고판을 출력하는 함수
int checkBingo(int * bingoArray, int inputSize) ; //빙고가 있는지 확인하는 함수
int getRandomNumber(int * prevNumberList) ; //랜덤으로 현재까지 나오지 않을 수중 하나를 반환하는 함수
int getUserSelectNumber(int * prevNumberList); //번호를 입력받아서 반환하는 함수

int main(void){

	int bingo[MAX][MAX]={0}; //빙고판 배열
	int size; //사이즈를 입력받기위한 변수
	int i=0,j=0; //반복문을 위한 정수형 변수
	int bingoend =1; //빙고가 되었는지 알기위한 정수형 변수
	int x=-1; //추출숫자가 나왔는지 알기위한 정수형 변수
	int answer; //추출방식을 알기위한 정수형 변수
	int prevNumberList[402]={0}; //사이즈*사이즈 만큼의 수를 입력받고 추출된 숫자를 지우는 배열<

	srand((unsigned int)time((time_t*)NULL));

	printf("빙고판 사이즈를 입력하세요 : "); 
	scanf_s("%d",&size); //사이즈를 입력받음

	while(size < 1 || size > MAX){ //만약 size가 최대인 20을 넘어가면 (계속 20을 넘어가면 계속 반복한다.)
		printf("(1~%d) 빙고판 사이즈를 다시입력하세요 : ",MAX);
		scanf_s("%d",&size); //오류메세지를 출력하고 다시 입력받는다.
	}

	makeBingo((int *)bingo , size);//빙고판 만들기위한 함수호출
	printf("\n빙고판 생성\n");
	printBingo((int *)bingo , size); //빙고판 출력을 위한 함수호출

	for(i=1; i<=size*size ;i++){
		prevNumberList[i] = i; //배열에 빙고판안에 들어올수있는 숫자를 모두 입력한다. (1번째부터 size*size번째 까지)
	}

	prevNumberList[i] = 500; //최대 숫자를 알려주기 위해서 최대숫자+1 번째 배열에 500을 저장한다.


	/////////// * 401

	while(bingoend==1){ //bingoend가 1이라면 아직 빙고가 아니므로 계속 반복한다.

		printf("숫자 추출 방법을 선택[1:랜덤][2:사용자입력] : ");
		scanf("%d",&answer); //숫자추출방법을 선택하도록 숫자를 입력받는다.

		switch(answer) { //입력받은 수가
		case 1 : //1이라면 랜덤입력이므로
			x=getRandomNumber(prevNumberList) ; //getRandomNumber함수를 호출하고 반환값을 x에 저장한다.
			break; //switch문을 나온다.
		case 2://2라면 사용자 입력이므로
			x=getUserSelectNumber(prevNumberList); //getUserSelectNumber함수를 호출하고 반환값을 x에 저장한다.
			break; //switch문을 나온다.
		default ://1이나2가 아닐경우 오류메세지를 출력한다.
			printf("잘못되었습니다.\n"); 
			break; //switch문을 나온다.

		}

		if(x != -1){//x가 -1이 아닐경우 빙고숫자를 입력받은 것이므로

			for(i=0 ; i < size ; i++){ //행을 나타내는 i 0부터 size-1까지 반복
				for(j=0 ; j < size ; j++){ //열을 나타내는 j 0부터 size-1까지 반복
					if(bingo[i][j] == x) { //만약 행이 i번째 열이 j번째인 배열 원소값이 x일때 
						bingo[i][j] = 401; //행이 i번째 열이 j번째인 배열의 원소를 401로 저장한다.
						//'*'은 아스키코드로 42이고 크기가 7인 빙고판부터 숫자42를 나타내야하므로 
						//먼저 최대 크기 20의 최대 숫자 400 다음인 401로 저장하고 출력시에 *로 바꿀것이다.
					}
				}
			}

			prevNumberList[x] = 0; //그리고 빙고판에 401로 저장된 x값을 prevNumberList배열에서 삭제한다. x번째 배열 원소를 0으로 저장한다.

			bingoend =checkBingo((int *)bingo , size); //빙고가 되었는지 체크하기위해 checkBingo함수를 호출하고 반환값을 bingoend에 저장한다.
		}
	}

	printf("\n빙고!\n");
	printBingo((int *)bingo , size); //printBingo함수를 호출하여 빙고판을 출력한다.

	return 0;

}

void makeBingo(int *bingoArray, int inputSize) {

	int i,j; //반복문을 위한 정수형 변수
	int bingonum = inputSize*inputSize; //빙고판의 최대숫자를 알기위한 정수형 변수
	int random, temp; //랜덤값을 입력받는 정수형 변수, 배열 위치를 바꾸기위한 정수형 변수
	int arr[400]; //1부터 bingonum까지 값을 저장하기 위한 배열

	for(i=0; i<bingonum; i++){ //i는 0부터 bingonum-1까지 반복한다.
		arr[i] = i+1; //i번째 배열이 원소는 i+1을 저장한다.
	}

	for(i=0; i<bingonum; i++){//i는 0부터 bingonum-1까지 반복한다.
		random= rand()%(bingonum); //ramdom은 0부터 bingonum-1까지의 수중 랜덤으로 입력받는다.

		temp= arr[i] ; //temp에 i번째 원소값을 저장한다.
		arr[i] = arr[random] ; //i번째 배열에 random번째 원소값을 저장한다.
		arr[random] = temp;//random번째 배열에 temp를 저장한다.

	}
	
	for(i=0 ; i <inputSize ; i++){ //행을 나타내기위한 i이다. 0부터inputSize-1까지 반복한다.
		for(j=0;j<inputSize;j++){//열을 나타내기위한 j이다. 0부터inputSize-1까지 반복한다.
			bingoArray[(i*MAX)+j] = arr[i*inputSize+j] ; //bingoArray배열의 (i*MAX)+j번째에 arr배열의 i*inputSize+j번째 원소값을 저장한다.
		}

	}
	

	

}
void printBingo (int * bingoArray, int inputSize) {
	int i,j; //반복문을 위한 정수형 변수

	printf("\n");
	for(i=0;i < inputSize ; i++){ //행을 나타내기위한 i이다. 0부터inputSize-1까지 반복한다.
		for(j=0;j<inputSize ;j++){//열을 나타내기위한 j이다. 0부터inputSize-1까지 반복한다.

			if(bingoArray[(i*MAX)+j] == 401){//i*MAX)+j번째 배열의 원소가 401이라면 (불려진 숫자로 사라진것)
				printf("*	"); //'*'을 출력한다.
			}
			else{ //401이 아니라면
				printf("%d	",bingoArray[(i*MAX)+j]); //원소값을 출력한다.
			}

		}
		printf("\n"); //행을 바꾸기 위하여 개행문자를 사용한다.
	}
	printf("\n");
}
int checkBingo(int * bingoArray, int inputSize) {


	int bingChenk=0; //빙고가 되었는지 체크하기 위한 정수형 변수
	int i,j; //반복문을 위한 정수형 변수


	//가로
	for(i=0 ; i <inputSize ; i++){ //행을 나타내기위한 i이다. 0부터inputSize-1까지 반복한다.
		bingChenk=0;//bingChenk를 0으로 초기화 시킨다. (가로이므로 행이 바뀔때마다 초기화 시켜줘야한다.)
		for(j=0;j<inputSize;j++){ //열을 나타내기위한 j이다. 0부터inputSize-1까지 반복한다.
			if(bingoArray[(i*MAX)+j] == 401) { //(i*MAX)+j 번째 원소가 401이라면 
				bingChenk++; //bingChenk값을 1 증가시킨다.
			}
			if(bingChenk==inputSize) return 0; //bingChenk가 inputSize라면 0을 반환한다.(빙고)
		}
	}

	//세로

	for(i=0 ; i <inputSize ; i++){//열을 나타내기위한 i이다. 0부터inputSize-1까지 반복한다.
		bingChenk=0;//bingChenk를 0으로 초기화 시킨다.(세로이므로 열이 바뀔때마다 초기화 시켜줘야한다.)
		for(j=0;j<inputSize;j++){//행을 나타내기위한 j이다. 0부터inputSize-1까지 반복한다.
			if(bingoArray[(j*MAX)+i] == 401) {//(j*MAX)+i 번째 원소가 401이라면 
				bingChenk++;//bingChenk값을 1 증가시킨다.
			}
			if(bingChenk==inputSize) return 0;//bingChenk가 inputSize라면 0을 반환한다.(빙고)
		}
	}

	//대각선 1  왼쪽위
	bingChenk=0;//bingChenk를 0으로 초기화 시킨다.
	for(i=0 ; i <inputSize ; i++){//열을 나타내기위한 i이다. 0부터inputSize-1까지 반복한다.
		j=i; //j에 i값을 저장한다.
		if(bingoArray[(i*MAX)+j] == 401) {//(i*MAX)+j 번째 원소가 401이라면 
				bingChenk++;//bingChenk값을 1 증가시킨다.
			}
			if(bingChenk==inputSize) return 0;//bingChenk가 inputSize라면 0을 반환한다.(빙고)
		
	}

	//대각선 2 왼쪽아래 
	bingChenk=0;//bingChenk를 0으로 초기화 시킨다.
	for(i=0 ; i < inputSize ; i++){//열을 나타내기위한 i이다. 0부터inputSize-1까지 반복한다.

		j=inputSize-(i+1); //j에 inputSize-(i+1)값을 저장한다. 

			if(bingoArray[(i*MAX)+j] == 401) {//(i*MAX)+j 번째 원소가 401이라면 
				bingChenk++;//bingChenk값을 1 증가시킨다.
			}
			if(bingChenk==inputSize) return 0;//bingChenk가 inputSize라면 0을 반환한다.(빙고)
		
	}


	return 1; // 네 경우 모두 bingChenk가 inputSize가 아니라면(빙고가 아니라면) 1을 반환한다.
}
int getRandomNumber(int * prevNumberList) {

	int i=rand()%400+1; //i는 1부터 400(최대사이즈 20의 최대숫자)까지의 숫자 중 랜덤하게 하나를 입력받는다.

	while(prevNumberList[i] == 0 || prevNumberList[i] == 500) {//i번째 배열의 원소가 0이거나 500인 경우 반복한다.
		i=rand()%400+1; //i는 다시 i는 1부터 400까지의 숫자 중 랜덤하게 하나를 입력받는다.
	}

	printf("랜덤 숫자를 추출 : %d\n",i); //i를 추출했다는 메세지를 출력한다.


	return i; //i를 반환한다.
}
int getUserSelectNumber(int * prevNumberList){

	int num; //사용자가 원하는 숫자를 입력받기 위한 정수형 변수
	int i=0;//반복문을 위한 정수형 변수

	printf("사용자 선택 숫자 입력 : ");
	scanf_s("%d",&num); //사용자가 원하는 숫자를 입력받고 num에 저장한다.

	for(i=0;i<401;i++){ //i가 0부터 400까지 반복
		if(prevNumberList[i+1]==500)break; //i+1번째 배열 원소가 500일경우 반복문을 나온다.
	}

	if(num<1 ||num>i){//num이 1보다 작거나 i(최대숫자)보다 클때
		printf("1부터 %d까지 수만 입력 가능합니다.\n",i); //오류 메세지를 출력하고
		return -1; //-1을 반환한다.
	}
	else if(prevNumberList[num] == 0) { //기존에 나온적이 있는 숫자이거나 최대 숫자를 넘어선경우
		printf("이미 입력된 숫자입니다.\n"); 
		return -1; // -1을 반환한다.
	}

	return num; //num을 반환한다.
}

