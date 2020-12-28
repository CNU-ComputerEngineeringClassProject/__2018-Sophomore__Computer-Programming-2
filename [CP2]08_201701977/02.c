
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int checkLottoNumber(int * lottoNums) ; //���ڸ� �Է¹޾� lottoNums���� ���� ���ڰ� �ִ��� Ȯ���ϴ� �Լ�
void makeLottoNumber(int * lottoNums) ; //�迭�� �ζ� ��ȣ�� �������� �Է��ϴ� �Լ� 

int main(void){

	int lottoNumber[6] = {0}; //�ζ� ��ȣ�� �����ϴ� �迭.
	int Lotto; //���� ������ ������ ������ ����
	int i; //�ݺ����� ����ϱ����� ������ ����

	srand((unsigned int)time((time_t*)NULL));

	makeLottoNumber(lottoNumber); //�ζ� ��ȣ ������ ���� �Լ��� ȣ���Ѵ�.

	Lotto = checkLottoNumber(lottoNumber); //�ζǹ�ȣ ��� ������� �˱� ���ؼ� �Լ��� ȣ���ϰ� ��ȯ���� Lotto�� �����Ѵ�.

	
	printf("�ζ� ��ȣ : ");

	for(i=0;i<6;i++){ //�ζ� ��ȣ�� ����ϴ� �ݺ���
		printf("%d ",lottoNumber[i]);
	}

	
	printf("\n�� %d���� �´� ���ڰ� �ֽ��ϴ�.\n",Lotto); //��� ������� �����.

	return 0;
}


void makeLottoNumber(int * lottoNums) {
	
	int i,j; //�ݺ����� ���� ������ ����

	
	for(i=0; i<6; i++){ //�������� 1~45���� ���� �迭�� ���ҷ� �Է¹ޱ����� for��
		lottoNums[i] = rand()%45+1; //lottoNums�� i��°�� 1~45�� �ϳ��� ���� �Է¹޴´�.
		for(j=0;j<i;j++){ //0~i-1���� �迭 ���Ұ��� i��° �迭 ���Ұ��� ���Ͽ� ���� ���� �ִ����� �˾ƺ��� �ݺ���
			if(lottoNums[j]==lottoNums[i]){ //���� j��° �迭�� i��° �迭�� ���Ұ��� ���ٸ�
			lottoNums[i] = rand()%45 +1;//i��° �迭���� �ٽ� �Է� �޴´�.
			j=0;//�׸��� j�� 0���� �����Ͽ� �ٽ� 0~i-1���� ���� �Է¹��� i��° ���Ұ��� ������ ���Ѵ�.
			}
		}
	}
}

int checkLottoNumber(int * lottoNums){

	int inarr[6] = {0}; //ũ�Ⱑ 6�� �迭�� �����.(����ڰ� �Է��� ���� �����ϱ�����)
	int num; //����ڰ� �Է��� ���ڸ� �Է¹ޱ����� ������ ����
	int i=0, j=0;//�ݺ����� ���� ������ ����
	int Lotto=0; //� ������� �˱����� ������ ����


	while(inarr[5]==0){ // ��������° �迭���Ұ��� ä������������ �ݺ����� �����Ѵ�.

	printf("��ȣ �Է� : ");
	scanf("%d",&num); //��ȣ�� �Է¹޾� num�� �����Ѵ�.

	
	
	for(i=0;i < 6;i++){
		if( num <1 || num > 45){ //num�� 1���� �۰ų� 45���� Ŭ�� 
			printf("(1~45)��ȣ�� �Է��ϼ���!\n"); //�����޼����� ����ϰ�
			break; //�ݺ����� ���´�.
		}
		else if(inarr[i] == num) { //num�� �̹� �ҷ��� ���ڶ��
			printf("���� ��ȣ�� �ֽ��ϴ�!\n"); //�����޼����� ����ϰ�
			break;//�ݺ����� ���´�.
		}

		else if(inarr[i] == 0){//num�� 1~45 ���� �ϳ��� ó�� �ҷ����� �����̰� i��° ���Ұ� 0�ϰ��(���� ��ȣ�Է��� �ȵȰ�)
			inarr[i] = num; //i��° �迭�� ���Ұ����� num�� �����Ѵ�.

			for(j=0 ; j<6 ; j++){//�ζ� ��ȣ�� num�� ��ġ�ϴ��� �˱����� �ݺ���
				if(lottoNums[j] == num){//j��° �迭�� ���Ұ��� num�� ��ġ�Ѵٸ�
					Lotto++;//Lotto�� �ϳ� ������Ű��
					break;//�ݺ����� ���´�.
				}

			}

			break;//�ݺ����� ���´�.
		}
	}
	
	}
return Lotto; //Lotto�� �����Ѵ�.;
}

