
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20 //������ �ִ밪�� �Է��� ��ũ�� ���


void makeBingo(int * bingoArray, int inputSize) ; // inputSize*inputSize �������� �����ϴ� �Լ�
void printBingo (int * bingoArray, int inputSize) ; //�������� ����ϴ� �Լ�
int checkBingo(int * bingoArray, int inputSize) ; //���� �ִ��� Ȯ���ϴ� �Լ�
int getRandomNumber(int * prevNumberList) ; //�������� ������� ������ ���� ���� �ϳ��� ��ȯ�ϴ� �Լ�
int getUserSelectNumber(int * prevNumberList); //��ȣ�� �Է¹޾Ƽ� ��ȯ�ϴ� �Լ�

int main(void){

	int bingo[MAX][MAX]={0}; //������ �迭
	int size; //����� �Է¹ޱ����� ����
	int i=0,j=0; //�ݺ����� ���� ������ ����
	int bingoend =1; //���� �Ǿ����� �˱����� ������ ����
	int x=-1; //������ڰ� ���Դ��� �˱����� ������ ����
	int answer; //�������� �˱����� ������ ����
	int prevNumberList[402]={0}; //������*������ ��ŭ�� ���� �Է¹ް� ����� ���ڸ� ����� �迭<

	srand((unsigned int)time((time_t*)NULL));

	printf("������ ����� �Է��ϼ��� : "); 
	scanf_s("%d",&size); //����� �Է¹���

	while(size < 1 || size > MAX){ //���� size�� �ִ��� 20�� �Ѿ�� (��� 20�� �Ѿ�� ��� �ݺ��Ѵ�.)
		printf("(1~%d) ������ ����� �ٽ��Է��ϼ��� : ",MAX);
		scanf_s("%d",&size); //�����޼����� ����ϰ� �ٽ� �Է¹޴´�.
	}

	makeBingo((int *)bingo , size);//������ ��������� �Լ�ȣ��
	printf("\n������ ����\n");
	printBingo((int *)bingo , size); //������ ����� ���� �Լ�ȣ��

	for(i=1; i<=size*size ;i++){
		prevNumberList[i] = i; //�迭�� �����Ǿȿ� ���ü��ִ� ���ڸ� ��� �Է��Ѵ�. (1��°���� size*size��° ����)
	}

	prevNumberList[i] = 500; //�ִ� ���ڸ� �˷��ֱ� ���ؼ� �ִ����+1 ��° �迭�� 500�� �����Ѵ�.


	/////////// * 401

	while(bingoend==1){ //bingoend�� 1�̶�� ���� ���� �ƴϹǷ� ��� �ݺ��Ѵ�.

		printf("���� ���� ����� ����[1:����][2:������Է�] : ");
		scanf("%d",&answer); //������������ �����ϵ��� ���ڸ� �Է¹޴´�.

		switch(answer) { //�Է¹��� ����
		case 1 : //1�̶�� �����Է��̹Ƿ�
			x=getRandomNumber(prevNumberList) ; //getRandomNumber�Լ��� ȣ���ϰ� ��ȯ���� x�� �����Ѵ�.
			break; //switch���� ���´�.
		case 2://2��� ����� �Է��̹Ƿ�
			x=getUserSelectNumber(prevNumberList); //getUserSelectNumber�Լ��� ȣ���ϰ� ��ȯ���� x�� �����Ѵ�.
			break; //switch���� ���´�.
		default ://1�̳�2�� �ƴҰ�� �����޼����� ����Ѵ�.
			printf("�߸��Ǿ����ϴ�.\n"); 
			break; //switch���� ���´�.

		}

		if(x != -1){//x�� -1�� �ƴҰ�� ������ڸ� �Է¹��� ���̹Ƿ�

			for(i=0 ; i < size ; i++){ //���� ��Ÿ���� i 0���� size-1���� �ݺ�
				for(j=0 ; j < size ; j++){ //���� ��Ÿ���� j 0���� size-1���� �ݺ�
					if(bingo[i][j] == x) { //���� ���� i��° ���� j��°�� �迭 ���Ұ��� x�϶� 
						bingo[i][j] = 401; //���� i��° ���� j��°�� �迭�� ���Ҹ� 401�� �����Ѵ�.
						//'*'�� �ƽ�Ű�ڵ�� 42�̰� ũ�Ⱑ 7�� �����Ǻ��� ����42�� ��Ÿ�����ϹǷ� 
						//���� �ִ� ũ�� 20�� �ִ� ���� 400 ������ 401�� �����ϰ� ��½ÿ� *�� �ٲܰ��̴�.
					}
				}
			}

			prevNumberList[x] = 0; //�׸��� �����ǿ� 401�� ����� x���� prevNumberList�迭���� �����Ѵ�. x��° �迭 ���Ҹ� 0���� �����Ѵ�.

			bingoend =checkBingo((int *)bingo , size); //���� �Ǿ����� üũ�ϱ����� checkBingo�Լ��� ȣ���ϰ� ��ȯ���� bingoend�� �����Ѵ�.
		}
	}

	printf("\n����!\n");
	printBingo((int *)bingo , size); //printBingo�Լ��� ȣ���Ͽ� �������� ����Ѵ�.

	return 0;

}

void makeBingo(int *bingoArray, int inputSize) {

	int i,j; //�ݺ����� ���� ������ ����
	int bingonum = inputSize*inputSize; //�������� �ִ���ڸ� �˱����� ������ ����
	int random, temp; //�������� �Է¹޴� ������ ����, �迭 ��ġ�� �ٲٱ����� ������ ����
	int arr[400]; //1���� bingonum���� ���� �����ϱ� ���� �迭

	for(i=0; i<bingonum; i++){ //i�� 0���� bingonum-1���� �ݺ��Ѵ�.
		arr[i] = i+1; //i��° �迭�� ���Ҵ� i+1�� �����Ѵ�.
	}

	for(i=0; i<bingonum; i++){//i�� 0���� bingonum-1���� �ݺ��Ѵ�.
		random= rand()%(bingonum); //ramdom�� 0���� bingonum-1������ ���� �������� �Է¹޴´�.

		temp= arr[i] ; //temp�� i��° ���Ұ��� �����Ѵ�.
		arr[i] = arr[random] ; //i��° �迭�� random��° ���Ұ��� �����Ѵ�.
		arr[random] = temp;//random��° �迭�� temp�� �����Ѵ�.

	}
	
	for(i=0 ; i <inputSize ; i++){ //���� ��Ÿ�������� i�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
		for(j=0;j<inputSize;j++){//���� ��Ÿ�������� j�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
			bingoArray[(i*MAX)+j] = arr[i*inputSize+j] ; //bingoArray�迭�� (i*MAX)+j��°�� arr�迭�� i*inputSize+j��° ���Ұ��� �����Ѵ�.
		}

	}
	

	

}
void printBingo (int * bingoArray, int inputSize) {
	int i,j; //�ݺ����� ���� ������ ����

	printf("\n");
	for(i=0;i < inputSize ; i++){ //���� ��Ÿ�������� i�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
		for(j=0;j<inputSize ;j++){//���� ��Ÿ�������� j�̴�. 0����inputSize-1���� �ݺ��Ѵ�.

			if(bingoArray[(i*MAX)+j] == 401){//i*MAX)+j��° �迭�� ���Ұ� 401�̶�� (�ҷ��� ���ڷ� �������)
				printf("*	"); //'*'�� ����Ѵ�.
			}
			else{ //401�� �ƴ϶��
				printf("%d	",bingoArray[(i*MAX)+j]); //���Ұ��� ����Ѵ�.
			}

		}
		printf("\n"); //���� �ٲٱ� ���Ͽ� ���๮�ڸ� ����Ѵ�.
	}
	printf("\n");
}
int checkBingo(int * bingoArray, int inputSize) {


	int bingChenk=0; //���� �Ǿ����� üũ�ϱ� ���� ������ ����
	int i,j; //�ݺ����� ���� ������ ����


	//����
	for(i=0 ; i <inputSize ; i++){ //���� ��Ÿ�������� i�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
		bingChenk=0;//bingChenk�� 0���� �ʱ�ȭ ��Ų��. (�����̹Ƿ� ���� �ٲ𶧸��� �ʱ�ȭ ��������Ѵ�.)
		for(j=0;j<inputSize;j++){ //���� ��Ÿ�������� j�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
			if(bingoArray[(i*MAX)+j] == 401) { //(i*MAX)+j ��° ���Ұ� 401�̶�� 
				bingChenk++; //bingChenk���� 1 ������Ų��.
			}
			if(bingChenk==inputSize) return 0; //bingChenk�� inputSize��� 0�� ��ȯ�Ѵ�.(����)
		}
	}

	//����

	for(i=0 ; i <inputSize ; i++){//���� ��Ÿ�������� i�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
		bingChenk=0;//bingChenk�� 0���� �ʱ�ȭ ��Ų��.(�����̹Ƿ� ���� �ٲ𶧸��� �ʱ�ȭ ��������Ѵ�.)
		for(j=0;j<inputSize;j++){//���� ��Ÿ�������� j�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
			if(bingoArray[(j*MAX)+i] == 401) {//(j*MAX)+i ��° ���Ұ� 401�̶�� 
				bingChenk++;//bingChenk���� 1 ������Ų��.
			}
			if(bingChenk==inputSize) return 0;//bingChenk�� inputSize��� 0�� ��ȯ�Ѵ�.(����)
		}
	}

	//�밢�� 1  ������
	bingChenk=0;//bingChenk�� 0���� �ʱ�ȭ ��Ų��.
	for(i=0 ; i <inputSize ; i++){//���� ��Ÿ�������� i�̴�. 0����inputSize-1���� �ݺ��Ѵ�.
		j=i; //j�� i���� �����Ѵ�.
		if(bingoArray[(i*MAX)+j] == 401) {//(i*MAX)+j ��° ���Ұ� 401�̶�� 
				bingChenk++;//bingChenk���� 1 ������Ų��.
			}
			if(bingChenk==inputSize) return 0;//bingChenk�� inputSize��� 0�� ��ȯ�Ѵ�.(����)
		
	}

	//�밢�� 2 ���ʾƷ� 
	bingChenk=0;//bingChenk�� 0���� �ʱ�ȭ ��Ų��.
	for(i=0 ; i < inputSize ; i++){//���� ��Ÿ�������� i�̴�. 0����inputSize-1���� �ݺ��Ѵ�.

		j=inputSize-(i+1); //j�� inputSize-(i+1)���� �����Ѵ�. 

			if(bingoArray[(i*MAX)+j] == 401) {//(i*MAX)+j ��° ���Ұ� 401�̶�� 
				bingChenk++;//bingChenk���� 1 ������Ų��.
			}
			if(bingChenk==inputSize) return 0;//bingChenk�� inputSize��� 0�� ��ȯ�Ѵ�.(����)
		
	}


	return 1; // �� ��� ��� bingChenk�� inputSize�� �ƴ϶��(���� �ƴ϶��) 1�� ��ȯ�Ѵ�.
}
int getRandomNumber(int * prevNumberList) {

	int i=rand()%400+1; //i�� 1���� 400(�ִ������ 20�� �ִ����)������ ���� �� �����ϰ� �ϳ��� �Է¹޴´�.

	while(prevNumberList[i] == 0 || prevNumberList[i] == 500) {//i��° �迭�� ���Ұ� 0�̰ų� 500�� ��� �ݺ��Ѵ�.
		i=rand()%400+1; //i�� �ٽ� i�� 1���� 400������ ���� �� �����ϰ� �ϳ��� �Է¹޴´�.
	}

	printf("���� ���ڸ� ���� : %d\n",i); //i�� �����ߴٴ� �޼����� ����Ѵ�.


	return i; //i�� ��ȯ�Ѵ�.
}
int getUserSelectNumber(int * prevNumberList){

	int num; //����ڰ� ���ϴ� ���ڸ� �Է¹ޱ� ���� ������ ����
	int i=0;//�ݺ����� ���� ������ ����

	printf("����� ���� ���� �Է� : ");
	scanf_s("%d",&num); //����ڰ� ���ϴ� ���ڸ� �Է¹ް� num�� �����Ѵ�.

	for(i=0;i<401;i++){ //i�� 0���� 400���� �ݺ�
		if(prevNumberList[i+1]==500)break; //i+1��° �迭 ���Ұ� 500�ϰ�� �ݺ����� ���´�.
	}

	if(num<1 ||num>i){//num�� 1���� �۰ų� i(�ִ����)���� Ŭ��
		printf("1���� %d���� ���� �Է� �����մϴ�.\n",i); //���� �޼����� ����ϰ�
		return -1; //-1�� ��ȯ�Ѵ�.
	}
	else if(prevNumberList[num] == 0) { //������ �������� �ִ� �����̰ų� �ִ� ���ڸ� �Ѿ���
		printf("�̹� �Էµ� �����Դϴ�.\n"); 
		return -1; // -1�� ��ȯ�Ѵ�.
	}

	return num; //num�� ��ȯ�Ѵ�.
}

