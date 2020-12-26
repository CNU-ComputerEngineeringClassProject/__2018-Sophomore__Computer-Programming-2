
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int makeArray(int *intArray, int arraySize); //배열 원소를 랜덤으로 넣는 메소드
int calSum(int *intArray, int arraySize); //총합을 구하는 함수
int calAvg(int *intArray, int arraySize); // 평균을 구하는 함수
int findMin(int *intArray, int arraySize); //최대 값을 찾아 반환해주는 메소드
int findMax(int *intArray, int arraySize); //최소 값을 찾아 반환해주는 메소드

void main(){
	int size; // 배열 크기를 입력받기위한 변수
	int arr[20] = {0}; //배열 생성 크기 max값은 20
	int i;

	
	printf("저장 할 값의 사이즈를 입력하세요 : ");
	scanf_s("%d",&size); // 배열의 크기를 입력받는다.
	

	while(size < 1||size > 20){ //배열크기가 1보다 작거나 20보다 큰경우가 아닐때까지 반복한다.
	printf("\n사이즈는 1이상 20이하의 정수로 입력해주세요!\n");
	printf("저장 할 값의 사이즈를 입력하세요 : ");
	scanf_s("%d",&size); // 배열의 크기를 입력받는다.
	}

	makeArray(arr, size);  //makeArray함수를 호출한다.

	printf("배열: ");
	for(i=0; i<size; i++){ // 배열 출력
		printf("%d ",arr[i]);
	}
	printf("\n\n");

	printf("총합: %d\n", calSum(arr, size)); //calSum함수를 호출하고 리턴값을 출력한다.
	printf("평균: %d\n", calAvg(arr, size)); //calAvg함수를 호출하고 리턴값을 출력한다.
	printf("최저값 : %d\n", findMin(arr, size)); //findMin함수를 호출하고 리턴값을 출력한다.
	printf("최고값 : %d\n", findMax(arr, size)); //findMax함수를 호출하고 리턴값을 출력한다.

	printf("\n\n");
}

int makeArray(int *intArray, int arraySize){ //배열을 포인터로 가져온다. 그리고 배열이 크기를 가져온다.
	
	int i;

	srand((unsigned int)time((time_t*)NULL)); //seed value


	for(i=0; i<arraySize; i++){ //랜덤으로 999까지 수를 배열의 원소로 입력받기위한 for문
		intArray[i] = rand()%1000;
	}

	return 0;
}

int calSum(int *intArray, int arraySize){
	int i;
	int sum=0; //배열의 합을 정의할것이기때문에 처음에 0으로 초기화 한다.

	for(i = 0 ; i<arraySize;i++){ //i를 0부터 배열의 크기 전까지 for문을 돌린다. (i는 1씩 증가)
	sum = sum + intArray[i]; //sum을 이전에 저장된 sum과 i번째 배열의 합으로 정의한다.
	}

	return sum; //sum을 리턴한다.
}

int calAvg(int *intArray, int arraySize){

int average ; //평균을 저장하기위한 변수

average = calSum(intArray,arraySize) / arraySize; //배열의 합을 나타내는 함수 calSum와 배열의 크기를 이용하여 평균을 구한다.  

return average; //변수 average를 리턴한다.
}


int findMin(int *intArray, int arraySize){

int min=intArray[0]; //제일 작은 배열원소를 구하기 위한 변수 . 처음을 배열의 0번째 원소로 정의 한다.
int i;

for(i=1; i<arraySize ; i++){ //i가 배열의 크기보다 작을때만 for문을 반복한다. i는 0부터 시작하며 1씩 증가한다.
	if(intArray[i] < min){min = intArray[i];} //만약 i번째 배열이 min보다 작을경우 min을 i번째 배열로 저장한다.
}
	return min; //min을 리턴한다.
}


int findMax(int *intArray, int arraySize){
int max=intArray[0]; //제일 큰 배열 원소를 구하기 위한 변수. 처음은 배열의 0번째 원소로 정의 한다.
int i;
for(i=1; i<arraySize ; i++){ //i가 배열의 크기보다 작을때만 for문을 반복한다. i는 0부터 시작하며 1씩 증가한다.
	if(intArray[i] > max){max = intArray[i];} //만약 i번째 배열이 max보다 클경우 max를 i번째 배열로 저장한다.
}
	return max; //max를 리턴한다.
}
