#include <stdio.h>
struct student //�л���  ������ ���� ����ü ����
{
	int num;//�й��� ������ ���
	char name[20]; //�̸��� ������ ���
	int Kgrade; //���������� ������ ���
	int Egrade; //���������� ������ ���
	int Mgrade; //���������� ������ ���
	int sum; //�� ������ ������ ������ ���
	double average; //��������� ������ ���
	char grade; //�й��� ������ ���
};
typedef struct student Student; //Student������ ������

void input_data(Student *pary,int inputSize); //�л������� �Է¹޴� �޼ҵ� 
void clac_data(Student *pary,int inputSize); //�л��� ����, ���, ���� ����ϴ� �޼ҵ�
void sort_data(Student *pary,int inputSize); //�л��� ������ ����
void print_data(Student *pary,int inputSize); //�л������� ���



int main(void){

	int numOfStudent; //�л����� �Է¹��� ������ ����
	Student list[100]; //��Ұ� 100���� ����ü �迭 ����
	int i; //�ݺ����� ���� ������ ����

	printf(">�л��� �Է� : ");
	scanf("%d",&numOfStudent); //�л����� �Է¹޴´�.

	input_data(list,numOfStudent); //�л������� �ޱ����� �Լ��� ȣ���Ѵ�.
	clac_data(list,numOfStudent); //�л��� �Է¹��� �������� �̿��Ͽ� ����,���,������ ����ϴ� �Լ��� ȣ��

	printf("\n���� �� ������ ...\n\n");
	print_data(list,numOfStudent); //�л������͸� ����ϴ� �Լ��� ȣ���Ѵ�.

	printf("\n# ���� �� ������ ...\n\n");
	sort_data(list,numOfStudent); //�����͸� ��� ���� ���������� �����ϴ� �Լ��� ȣ���Ѵ�.
	print_data(list,numOfStudent); //�л������͸� ����ϴ� �Լ��� ȣ���Ѵ�.
	
	return 0;
}


void input_data(Student *pary,int inputSize){//�л������� �Է¹޴� �޼ҵ� (�Ű������� Sudent���� ������, int�� ����)

	int i; //�ݺ����� ���� ������ ����

	for(i=0;i<inputSize;i++){ //�л��� ��ŭ �ݺ��Ѵ�.
	printf(">�й� : "); 
	scanf("%d",&pary[i].num); //�й��� �Է� �ް� i��° �迭 num������� �����Ѵ�.
	printf(">�̸� : ");
	scanf("%s",pary[i].name); //�̸��� �Է� �ް� i��° �迭 name������� �����Ѵ�.
	printf(">����,����,���� ���� : ");
	scanf("%d %d %d",&pary[i].Kgrade,&pary[i].Egrade,&pary[i].Mgrade);  //���� ���� ���� ������ ���ʷ� �Է� �ް� i��° �迭 num������� �����Ѵ�.
	}
}
void clac_data(Student *pary,int inputSize){//�л��� ����, ���, ���� ����ϴ� �޼ҵ� (�Ű������� Sudent���� ������, int�� ����)
	
	int i; //�ݺ����� ���� ������ ����
	for(i=0;i<inputSize;i++){ //�л��� ��ŭ �ݺ��Ѵ�.
		pary[i].sum = pary[i].Kgrade + pary[i].Egrade + pary[i].Mgrade; //i��° �迭 Kgrade, Egrade, Mgrade����� ���� ���ϰ� sum������� �����Ѵ�. (���� ���ϱ�)
		pary[i].average = (double) pary[i].sum / 3; //i��° �迭 sum����� ���� 3���� ������ double������ ����ȭ ���� average������� �����Ѵ�. (��� ���ϱ�)

		if(pary[i].average >= 90){ //i��° �迭 average����� ���� 90 �̻��̶��
			pary[i].grade = 'A'; //i��° �迭 grade������� 'A'�� �����Ѵ�.
		}else if(pary[i].average >= 80){ //�ƴ� ��� i��° �迭 average����� ���� 90 �̻��̶��
				pary[i].grade = 'B'; //i��° �迭 grade������� 'B'�� �����Ѵ�.
		}else if(pary[i].average >= 70){ //�ƴ� ��� i��° �迭 average����� ���� 90 �̻��̶��
				pary[i].grade = 'C'; //i��° �迭 grade������� 'C'�� �����Ѵ�.
		}else{ //�ƴ� ���
			pary[i].grade = 'F'; //i��° �迭 grade������� 'F'�� �����Ѵ�.
		}

	}

}
void sort_data(Student *pary,int inputSize){ //�л��� ������ ���� (�Ű������� Sudent���� ������, int�� ����)
	
	int i,j; //�ݺ����� ���� ������ ����
	Student tempStu; //����ü ������ �����Ѵ�. 

	for(i=0;i<inputSize;i++){ //�л��� ��ŭ �ݺ��Ѵ�.
		for(j=i;j<inputSize;j++){ //�л��� ��ŭ �ݺ��Ѵ�.(j�� i���� : ������ �̹� ���ĵǾ��ֱ⶧����) 
			if(pary[i].average < pary[j].average){ //i��° �迭�� average����� ������ j��° �迭 average����� ���� �� Ŭ���
				tempStu = *(pary+i); //tempStu�� pary+i�迭�� ��Ҹ� �����Ѵ�.
				*(pary+i)=*(pary+j); //pary+i��° �迭�� pary+j�迭�� ��Ҹ� �����Ѵ�.
				*(pary+j)=tempStu; //pary+j��° �迭�� tempStu�� �����Ѵ�.
			}
		}	
	}
}
void print_data(Student *pary,int inputSize){  //�л������� ��� (�Ű������� Sudent���� ������, int�� ����)

	int i; //�ݺ����� ���� ������ ����

	for(i=0;i<inputSize;i++){ //�л��� ��ŭ �ݺ��Ѵ�.
	printf(" %d %s  %d %d %d	%d	%.1lf	%c\n",pary[i].num, pary[i].name,pary[i].Kgrade,pary[i].Egrade,pary[i].Mgrade,pary[i].sum,pary[i].average,pary[i].grade);
	//i��° �迭�� num, name, Kgrade, Egrade, Mgrade, sum, average, grade����� ���� ����Ѵ�.
	//�л��� ������ ����Ѵ�.
	}
}