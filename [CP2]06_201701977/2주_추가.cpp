#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int makeArray(int *Array, int size);
int calSum(int *Array, int size);
int calAvg(int *Array, int size);
int findMin(int *Array, int size);
int findMax(int *Array, int size);

int main(void){
	
	int arr[MAX];
	int num,i;

	printf("배열 생성 사이즈 : ");
	scanf("%d",&num);

	makeArray(arr,num);

	for(i=0;i<num;i++){
		printf("%d ",*(arr+i));
	}
	printf("\n");


	printf("총합 : %d\n",calSum(arr,num));
	printf("평균 : %d\n",calAvg(arr,num));
	printf("최저 : %d\n",findMin(arr,num));
	printf("최고 : %d\n",findMax(arr,num));

	
	return 0;
}

int makeArray(int *Array, int size){
	int i;
	srand((unsigned int)time((time_t*)NULL));

	for(i=0;i<size;i++){
	Array[i] = (rand()%1000);
	}
	return 0;
}

int calSum(int *Array, int size){
int i,sum=0;

for(i=0;i<size;i++){
sum = sum+Array[i];
}
return sum;
}


int calAvg(int *Array, int size){
	return calSum(Array,size) / size;
}
int findMin(int *Array, int size){
	int min;
	int i;

	if(size==2){
		if(Array[0] < Array[1]){
		min = *Array;
		}
		else min= *(Array+1);

		return min;
	}
	else{
		return Array[size-1]< findMin(Array,size-1) ? min = Array[size-1] : min = findMin(Array,size-1);
	}
}
int findMax(int *Array, int size){
	int max;

	int rear_half = size / 2;
	int front_half = size - rear_half;

	int *r_Array = Array+front_half;

	if(rear_half==1 && front_half==1){
		return Array[0] < r_Array[0] ? max = *(r_Array) : max = Array[0] ;
	}
	else if(rear_half==1){
		return findMax(Array,front_half) < r_Array[0] ? max = *(r_Array) : max = findMax(Array,front_half);
	}
	else{
		return findMax(Array,front_half) < findMax(r_Array, rear_half) ? max=findMax(r_Array, rear_half) :max =findMax(Array,front_half);
	}


	return max;
}


