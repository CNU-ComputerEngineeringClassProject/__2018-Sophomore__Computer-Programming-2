#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* makeArray(int *intArray, int inputSize); //배열에 원소값을 랜덤으로 넣어주기 위한 함수
void swap(int * x, int * y); // 받은 두 값의 위치를 변경하는 함수
void sortArray(int *intArray, int inputSize) ; // 받은 배열을 선택정렬하기위한 함수


int main (void){

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

	printf("\n배열: ");
	for(i=0; i<size; i++){ // 배열 출력
		printf("%d ",arr[i]);
	}
	printf("\n\n");


	sortArray(arr, size) ; //선택 정렬하기위한 sortArray함수 호출

	printf("선택 정렬 배열: ");
	for(i=0; i<size; i++){ // 선택정렬한 배열 출력
		printf("%d ",arr[i]);
	}
	printf("\n\n");

}

int* makeArray(int *intArray, int inputSize){ //int포인터와 int 를 매개변수로 선언
	
	int i;

	srand((unsigned int)time((time_t*)NULL)); //seed value


	for(i=0; i < inputSize; i++){ //랜덤으로 999까지 수를 배열의 원소로 입력받기위한 for문
		intArray[i] = rand()%1000;
	}

	return 0;
}

void swap(int * x, int * y){ //int포인터 2개를 매개변수로 선언
 int temp; 

 temp = *x; //temp에 (포인터 x에 간접 참조연산을 이용하여) 포인터 x가 담고있는 주소값의 원소값을 저장한다.
 *x = *y; //(포인터 x에 간접 참조연산을 이용하여) x가 담고있는 주소값의 원소자리에 (포인터 y에 간접 참조연산을 이용하여) y가 담고있는 주소값의 원소값을 저장한다.
 *y = temp; //(포인터 y에 간접 참조연산을 이용하여) 포인터 y가 담고있는 주소값의 원소자리에 temp를 저장한다.
}


void sortArray(int *intArray, int inputSize) { //int포인터와 int 를 매개변수로 선언
	int i,j,copy;
	int min;

	for (i=0;i<inputSize ; i++){ //i가 0부터 inputSize-1번까지 하나씩 증가하며 반복한다.
		min = intArray[i]; //min에 i번째 배열의 원소값을 저장한다.
		
		for (j=i+1;j<inputSize;j++){ //j가 i+1부터 inputSize-1번까지 하나씩 증가하며 반복한다.
		// i번째 이전은 이미 선택정렬 되었으므로 i번째 이후의 배열만 비교하기위해서
			if(intArray[j] < min){ //만약 j번째 배열이 min보다 작을경우
			min = intArray[j]; //min에 j번째 배열의 원소값을 넣는다.
			copy=j; //copy에 j값을 넣는다.
			}
		} //for문에서 나오면 i번째 부터 inpuSize-1번째까지 중 제일작은 수를 찾았다는 이야기.
		if(min != intArray[i]){ //만약 min이 i번째 배열의 원소값과 다르다면
			swap(&intArray[i],&intArray[copy]); //swap함수에 i번째 배열의 주소값과 copy번째 배열의 주소값을 사용하여 함수호출한다.
		}//두 수의 자리가 바뀌면서 i번째 배열에 i번째 작은수가 넣어지게된다.
	
		//min이 i번째 배열의 원소값과 같다면 i번째 배열의 원소값이 i번째 작은수라는 이야기이므로 자리를 이동할 필요가 없다.
		}
}
