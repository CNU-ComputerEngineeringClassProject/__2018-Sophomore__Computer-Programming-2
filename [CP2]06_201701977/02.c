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


int findMin (int* intArray, int arraySize){

	int findmin;

	if(arraySize == 1){ //배열의 크기가 1일경우
		if(intArray[0] < intArray[1]){ // 0번째 배열원소와 1번째 배열원소를 비교해서 0번째 배열이 더 작을경우
			return intArray[0]; //0번째 배열을 리턴한다.
		}
		else{
			return intArray[1]; //1번째 배열이 더 작을경우 1번째 배열을 리턴한다.
		}
	}
	else{
		findmin = findMin(intArray,arraySize-1); //배열의 크기를 하나씩 줄이는 재귀함수를 만든다.

		if(findmin < intArray[arraySize-1]){ //재귀함수의 리턴값(비교한것들 중 작은값)과 arratSize-1번째 배열원소와 비교하여 재귀함수 리턴값이 더작으면
			return findmin; //재귀함수 리턴값을 리턴한다.
		}
		else{
			return intArray[arraySize-1]; //arraySize번째 배열 원소가 더 작으면 그 수를 리턴한다.
		}
	}
}


int findMax(int *intArray, int arraySize){

	int back_half = arraySize / 2 ; //배열의 크기를 2로 나눈 몫을 저장하는 변수 
	int front_half = arraySize - back_half; //배열의 크기에 back_half를 뺀 나머지를 저장하는 변수
	//(배열의 크기가 짝수일경우 front_half=back_half , 홀수일경우 front_half=back_half+1)

	int max, front_max, back_max;

	int* f = intArray; //0번째 배열주소값을 저장하는 포인터변수
	int* t = intArray+front_half; // front_half번째 배열 주소값을 저장하는 포인터변수
	
	
	if(front_half ==1 && back_half ==1){ //front_half가 1이고, back_half가 1일경우
	
		if(f[0] < t[0]){ // 앞부분 배열 원소와 뒷부분 배열 원소를 비교하여 뒷부분 배열원소값이 더 큰경우
			return t[0]; //뒷부분 원소 리턴한다.
		}else{
			return f[0]; //앞부분 원소를 리턴한다.
		}
	}else{
		if(back_half==1){ //front_half은 1이 아니지만, back_half이 1일경우 (이 경우 front_half는 2이다)
			front_max = findMax(f, front_half); // 재귀함수를 이용하여 배열에 앞부분 배열 2개 원소를 먼저 비교한다.
			if(front_max < t[0]){ //앞부분 배열의 비교하여 리턴한 최고값과 뒷부분 원소를 비교하여 뒷부분 원소가 더 큰경우
				front_max = t[0]; // front_max를 뒷부분 원소값으로 저장한다.
			}
			return front_max; //front_max를 리턴한다.

		}else{ //front_half도 1이 아니고, back_half도 1이 아닌경우
			front_max = findMax(f , front_half); //재귀함수를 이용하여 배열을 반 나눈 앞부분의 최고값을 구한다.
			back_max = findMax(t , back_half) ; //재귀함수를 이용하여 배열을 반 나눈 뒷부분의 최고값을 구한다.

			if(front_max < back_max){return back_max;} // 앞부분 배열의 최고값과 뒷부분 배열의 최고값을 비교하여 뒷부분 배열의 최고값이 더 큰경우 뒷부분배열 최고값을 리턴한다.
			else{return front_max;} // 앞부분 배열의 최고값이 더 큰경우 앞부분배열 최고값을 리턴한다.
		}		
	}	
}

	


