
#include <stdio.h>

void inputScore(int *scoreArray, int intputIndex); //������ �Է¹ޱ����� �Լ�
void printScore(int *scoreArray, int index, int intputIndex); //������ ����ϱ� ���� �Լ�
int printSum(int *scoreArray, int inputIndex); // �л��� �������� ���� ����ϰ� ����ϸ� ���� �����ϴ� �Լ�
int printAvg(int *scoreArray, int inputIndex); // �л��� �������� ��������� ����ϰ� ����ϸ� ����� �����ϴ� �Լ� 

int main(void) {

		int scoreArray[20][3]; //���� ũ�Ⱑ 20�̰� ���� ũ�Ⱑ 3�� �迭�� �����Ѵ�.
		int inputStudentSize; // �л����� �Է¹��� ����
		int studentIndex; //�ݺ����� �̿��ϱ����� ����
		
		printf("�Է� ���� �л����� �Է��ϼ��� : ");
		scanf_s("%d", &inputStudentSize); //�л����� �Է¹޴´�.

		while(0 > inputStudentSize || inputStudentSize >20){ //�л����� 0���� �۰ų� 20���� ū��� 
		printf("�л����� 1�̻� 20������ ���� �����մϴ�.\n\n"); //�����޼����� ����ϰ�
		printf("�Է� ���� �л����� �Է��ϼ��� : "); 
		scanf_s("%d", &inputStudentSize);//�ٽ� �Է¹޴´�.
		}

		for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) //studentIndex�� 0���� inputStudentSize-1���� �ϳ��� �����ϸ� �ݺ��Ѵ�.
		inputScore(&(scoreArray[studentIndex]), inputStudentSize); 
		//������ �Է¹ޱ� ���� �Լ��� ȣ���Ѵ�. (&(scoreArray[studentIndex]) : ���� studentIndex��°�� ���κ��� �迭�� �ֱ����Ͽ� &(�ּҰ�)�� ����Ѵ�.)

		for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) { //studentIndex�� 0���� inputStudentSize-1���� �ϳ��� �����ϸ� �ݺ��Ѵ�.
			printScore(&(scoreArray[studentIndex]), studentIndex, inputStudentSize);
			//������ ����ϱ� ���� �Լ��� ȣ���Ѵ�. (&(scoreArray[studentIndex]) : ���� studentIndex��°�� ���κ��� �迭�� �ֱ����Ͽ� &(�ּҰ�)�� ����Ѵ�.)
			printAvg(&(scoreArray[studentIndex]), inputStudentSize);
			//����� ����ϱ� ���� �Լ��� ȣ���Ѵ�. (&(scoreArray[studentIndex]) : ���� studentIndex��°�� ���κ��� �迭�� �ֱ����Ͽ� &(�ּҰ�)�� ����Ѵ�.)
		}

		return 0;
		}

		void inputScore(int *scoreArray, int intputIndex) {
		printf("���� ���� �Է� : ");
		scanf_s("%d", &scoreArray[0]); //0��° �迭�� ������� �Է¹޴´�.
		printf("���� ���� �Է� : ");
		scanf_s("%d", &scoreArray[1]); //1��° �迭�� ������� �Է¹޴´�.
		printf("���� ���� �Է� : ");
		scanf_s("%d", &scoreArray[2]); //2��° �迭�� ���м����� �Է¹޴´�.
		}

		void printScore(int *scoreArray, int index, int intputIndex) {
		printf("[%d] %d,%d,%d", index, scoreArray[0], scoreArray[1], scoreArray[2]);
		//�迭�� index��° �л��� ���� ���� ���� ������ ����Ѵ�.
		}

		int printSum(int *scoreArray, int inputIndex) {
			int sum = 0;//������ �����ϱ� ���� ���� 

			sum = scoreArray[0] + scoreArray[1]+ scoreArray[2]; //sum�� 0,1,2��° �迭�� ���Ұ��� ���ϰ� �����Ѵ�.
			
			printf(", ���� : %d", sum); //������ ����Ѵ�.

			return sum; //sum�� �����Ѵ�.
		}
		int printAvg(int *scoreArray, int inputIndex) { 

			int average=1; //����� �����ϱ����� ����

			average = printSum(scoreArray, inputIndex) / 3; //printSum�Լ��� ȣ���Ͽ� sum���� ���Ϲ޾� �װ��� 3�� ���� average���� �����Ѵ�.

			printf(", ��� : %d\n", average); //����� ����Ѵ�.

			return average; //average�� �����Ѵ�.
		}
		