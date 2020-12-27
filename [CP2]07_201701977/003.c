#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* makeArray(int *intArray, int inputSize); //�迭�� ���Ұ��� �������� �־��ֱ� ���� �Լ�
void swap(int * x, int * y); // ���� �� ���� ��ġ�� �����ϴ� �Լ�
void sortArray(int *intArray, int inputSize) ; // ���� �迭�� ���������ϱ����� �Լ�


int main (void){

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

	printf("\n�迭: ");
	for(i=0; i<size; i++){ // �迭 ���
		printf("%d ",arr[i]);
	}
	printf("\n\n");


	sortArray(arr, size) ; //���� �����ϱ����� sortArray�Լ� ȣ��

	printf("���� ���� �迭: ");
	for(i=0; i<size; i++){ // ���������� �迭 ���
		printf("%d ",arr[i]);
	}
	printf("\n\n");

}

int* makeArray(int *intArray, int inputSize){ //int�����Ϳ� int �� �Ű������� ����
	
	int i;

	srand((unsigned int)time((time_t*)NULL)); //seed value


	for(i=0; i < inputSize; i++){ //�������� 999���� ���� �迭�� ���ҷ� �Է¹ޱ����� for��
		intArray[i] = rand()%1000;
	}

	return 0;
}

void swap(int * x, int * y){ //int������ 2���� �Ű������� ����
 int temp; 

 temp = *x; //temp�� (������ x�� ���� ���������� �̿��Ͽ�) ������ x�� ����ִ� �ּҰ��� ���Ұ��� �����Ѵ�.
 *x = *y; //(������ x�� ���� ���������� �̿��Ͽ�) x�� ����ִ� �ּҰ��� �����ڸ��� (������ y�� ���� ���������� �̿��Ͽ�) y�� ����ִ� �ּҰ��� ���Ұ��� �����Ѵ�.
 *y = temp; //(������ y�� ���� ���������� �̿��Ͽ�) ������ y�� ����ִ� �ּҰ��� �����ڸ��� temp�� �����Ѵ�.
}


void sortArray(int *intArray, int inputSize) { //int�����Ϳ� int �� �Ű������� ����
	int i,j,copy;
	int min;

	for (i=0;i<inputSize ; i++){ //i�� 0���� inputSize-1������ �ϳ��� �����ϸ� �ݺ��Ѵ�.
		min = intArray[i]; //min�� i��° �迭�� ���Ұ��� �����Ѵ�.
		
		for (j=i+1;j<inputSize;j++){ //j�� i+1���� inputSize-1������ �ϳ��� �����ϸ� �ݺ��Ѵ�.
		// i��° ������ �̹� �������� �Ǿ����Ƿ� i��° ������ �迭�� ���ϱ����ؼ�
			if(intArray[j] < min){ //���� j��° �迭�� min���� �������
			min = intArray[j]; //min�� j��° �迭�� ���Ұ��� �ִ´�.
			copy=j; //copy�� j���� �ִ´�.
			}
		} //for������ ������ i��° ���� inpuSize-1��°���� �� �������� ���� ã�Ҵٴ� �̾߱�.
		if(min != intArray[i]){ //���� min�� i��° �迭�� ���Ұ��� �ٸ��ٸ�
			swap(&intArray[i],&intArray[copy]); //swap�Լ��� i��° �迭�� �ּҰ��� copy��° �迭�� �ּҰ��� ����Ͽ� �Լ�ȣ���Ѵ�.
		}//�� ���� �ڸ��� �ٲ�鼭 i��° �迭�� i��° �������� �־����Եȴ�.
	
		//min�� i��° �迭�� ���Ұ��� ���ٸ� i��° �迭�� ���Ұ��� i��° ��������� �̾߱��̹Ƿ� �ڸ��� �̵��� �ʿ䰡 ����.
		}
}
