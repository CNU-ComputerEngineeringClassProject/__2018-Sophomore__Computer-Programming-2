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


int findMin (int* intArray, int arraySize){

	int findmin;

	if(arraySize == 1){ //�迭�� ũ�Ⱑ 1�ϰ��
		if(intArray[0] < intArray[1]){ // 0��° �迭���ҿ� 1��° �迭���Ҹ� ���ؼ� 0��° �迭�� �� �������
			return intArray[0]; //0��° �迭�� �����Ѵ�.
		}
		else{
			return intArray[1]; //1��° �迭�� �� ������� 1��° �迭�� �����Ѵ�.
		}
	}
	else{
		findmin = findMin(intArray,arraySize-1); //�迭�� ũ�⸦ �ϳ��� ���̴� ����Լ��� �����.

		if(findmin < intArray[arraySize-1]){ //����Լ��� ���ϰ�(���Ѱ͵� �� ������)�� arratSize-1��° �迭���ҿ� ���Ͽ� ����Լ� ���ϰ��� ��������
			return findmin; //����Լ� ���ϰ��� �����Ѵ�.
		}
		else{
			return intArray[arraySize-1]; //arraySize��° �迭 ���Ұ� �� ������ �� ���� �����Ѵ�.
		}
	}
}


int findMax(int *intArray, int arraySize){

	int back_half = arraySize / 2 ; //�迭�� ũ�⸦ 2�� ���� ���� �����ϴ� ���� 
	int front_half = arraySize - back_half; //�迭�� ũ�⿡ back_half�� �� �������� �����ϴ� ����
	//(�迭�� ũ�Ⱑ ¦���ϰ�� front_half=back_half , Ȧ���ϰ�� front_half=back_half+1)

	int max, front_max, back_max;

	int* f = intArray; //0��° �迭�ּҰ��� �����ϴ� �����ͺ���
	int* t = intArray+front_half; // front_half��° �迭 �ּҰ��� �����ϴ� �����ͺ���
	
	
	if(front_half ==1 && back_half ==1){ //front_half�� 1�̰�, back_half�� 1�ϰ��
	
		if(f[0] < t[0]){ // �պκ� �迭 ���ҿ� �޺κ� �迭 ���Ҹ� ���Ͽ� �޺κ� �迭���Ұ��� �� ū���
			return t[0]; //�޺κ� ���� �����Ѵ�.
		}else{
			return f[0]; //�պκ� ���Ҹ� �����Ѵ�.
		}
	}else{
		if(back_half==1){ //front_half�� 1�� �ƴ�����, back_half�� 1�ϰ�� (�� ��� front_half�� 2�̴�)
			front_max = findMax(f, front_half); // ����Լ��� �̿��Ͽ� �迭�� �պκ� �迭 2�� ���Ҹ� ���� ���Ѵ�.
			if(front_max < t[0]){ //�պκ� �迭�� ���Ͽ� ������ �ְ��� �޺κ� ���Ҹ� ���Ͽ� �޺κ� ���Ұ� �� ū���
				front_max = t[0]; // front_max�� �޺κ� ���Ұ����� �����Ѵ�.
			}
			return front_max; //front_max�� �����Ѵ�.

		}else{ //front_half�� 1�� �ƴϰ�, back_half�� 1�� �ƴѰ��
			front_max = findMax(f , front_half); //����Լ��� �̿��Ͽ� �迭�� �� ���� �պκ��� �ְ��� ���Ѵ�.
			back_max = findMax(t , back_half) ; //����Լ��� �̿��Ͽ� �迭�� �� ���� �޺κ��� �ְ��� ���Ѵ�.

			if(front_max < back_max){return back_max;} // �պκ� �迭�� �ְ��� �޺κ� �迭�� �ְ��� ���Ͽ� �޺κ� �迭�� �ְ��� �� ū��� �޺κй迭 �ְ��� �����Ѵ�.
			else{return front_max;} // �պκ� �迭�� �ְ��� �� ū��� �պκй迭 �ְ��� �����Ѵ�.
		}		
	}	
}

	


