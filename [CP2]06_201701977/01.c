
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int makeArray(int *intArray, int arraySize); //�迭 ���Ҹ� �������� �ִ� �޼ҵ�
int calSum(int *intArray, int arraySize); //������ ���ϴ� �Լ�
int calAvg(int *intArray, int arraySize); // ����� ���ϴ� �Լ�
int findMin(int *intArray, int arraySize); //�ִ� ���� ã�� ��ȯ���ִ� �޼ҵ�
int findMax(int *intArray, int arraySize); //�ּ� ���� ã�� ��ȯ���ִ� �޼ҵ�

void main(){
	int size; // �迭 ũ�⸦ �Է¹ޱ����� ����
	int arr[20] = {0}; //�迭 ���� ũ�� max���� 20
	int i;

	
	printf("���� �� ���� ����� �Է��ϼ��� : ");
	scanf_s("%d",&size); // �迭�� ũ�⸦ �Է¹޴´�.
	

	while(size < 1||size > 20){ //�迭ũ�Ⱑ 1���� �۰ų� 20���� ū��찡 �ƴҶ����� �ݺ��Ѵ�.
	printf("\n������� 1�̻� 20������ ������ �Է����ּ���!\n");
	printf("���� �� ���� ����� �Է��ϼ��� : ");
	scanf_s("%d",&size); // �迭�� ũ�⸦ �Է¹޴´�.
	}

	makeArray(arr, size);  //makeArray�Լ��� ȣ���Ѵ�.

	printf("�迭: ");
	for(i=0; i<size; i++){ // �迭 ���
		printf("%d ",arr[i]);
	}
	printf("\n\n");

	printf("����: %d\n", calSum(arr, size)); //calSum�Լ��� ȣ���ϰ� ���ϰ��� ����Ѵ�.
	printf("���: %d\n", calAvg(arr, size)); //calAvg�Լ��� ȣ���ϰ� ���ϰ��� ����Ѵ�.
	printf("������ : %d\n", findMin(arr, size)); //findMin�Լ��� ȣ���ϰ� ���ϰ��� ����Ѵ�.
	printf("�ְ� : %d\n", findMax(arr, size)); //findMax�Լ��� ȣ���ϰ� ���ϰ��� ����Ѵ�.

	printf("\n\n");
}

int makeArray(int *intArray, int arraySize){ //�迭�� �����ͷ� �����´�. �׸��� �迭�� ũ�⸦ �����´�.
	
	int i;

	srand((unsigned int)time((time_t*)NULL)); //seed value


	for(i=0; i<arraySize; i++){ //�������� 999���� ���� �迭�� ���ҷ� �Է¹ޱ����� for��
		intArray[i] = rand()%1000;
	}

	return 0;
}

int calSum(int *intArray, int arraySize){
	int i;
	int sum=0; //�迭�� ���� �����Ұ��̱⶧���� ó���� 0���� �ʱ�ȭ �Ѵ�.

	for(i = 0 ; i<arraySize;i++){ //i�� 0���� �迭�� ũ�� ������ for���� ������. (i�� 1�� ����)
	sum = sum + intArray[i]; //sum�� ������ ����� sum�� i��° �迭�� ������ �����Ѵ�.
	}

	return sum; //sum�� �����Ѵ�.
}

int calAvg(int *intArray, int arraySize){

int average ; //����� �����ϱ����� ����

average = calSum(intArray,arraySize) / arraySize; //�迭�� ���� ��Ÿ���� �Լ� calSum�� �迭�� ũ�⸦ �̿��Ͽ� ����� ���Ѵ�.  

return average; //���� average�� �����Ѵ�.
}


int findMin(int *intArray, int arraySize){

int min=intArray[0]; //���� ���� �迭���Ҹ� ���ϱ� ���� ���� . ó���� �迭�� 0��° ���ҷ� ���� �Ѵ�.
int i;

for(i=1; i<arraySize ; i++){ //i�� �迭�� ũ�⺸�� �������� for���� �ݺ��Ѵ�. i�� 0���� �����ϸ� 1�� �����Ѵ�.
	if(intArray[i] < min){min = intArray[i];} //���� i��° �迭�� min���� ������� min�� i��° �迭�� �����Ѵ�.
}
	return min; //min�� �����Ѵ�.
}


int findMax(int *intArray, int arraySize){
int max=intArray[0]; //���� ū �迭 ���Ҹ� ���ϱ� ���� ����. ó���� �迭�� 0��° ���ҷ� ���� �Ѵ�.
int i;
for(i=1; i<arraySize ; i++){ //i�� �迭�� ũ�⺸�� �������� for���� �ݺ��Ѵ�. i�� 0���� �����ϸ� 1�� �����Ѵ�.
	if(intArray[i] > max){max = intArray[i];} //���� i��° �迭�� max���� Ŭ��� max�� i��° �迭�� �����Ѵ�.
}
	return max; //max�� �����Ѵ�.
}
