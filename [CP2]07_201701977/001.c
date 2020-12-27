
#include <stdio.h>

void inputScore(int *scoreArray, int intputIndex); //점수를 입력받기위한 함수
void printScore(int *scoreArray, int index, int intputIndex); //점수를 출력하기 위한 함수
int printSum(int *scoreArray, int inputIndex); // 학생의 세점수의 합을 계산하고 출력하며 합을 리턴하는 함수
int printAvg(int *scoreArray, int inputIndex); // 학생의 세점수의 평균점수를 계산하고 출력하며 평균을 리턴하는 함수 

int main(void) {

		int scoreArray[20][3]; //행의 크기가 20이고 열의 크기가 3인 배열을 생성한다.
		int inputStudentSize; // 학생수를 입력받을 변수
		int studentIndex; //반복문에 이용하기위한 변수
		
		printf("입력 받을 학생수를 입력하세요 : ");
		scanf_s("%d", &inputStudentSize); //학생수를 입력받는다.

		while(0 > inputStudentSize || inputStudentSize >20){ //학생수가 0보다 작거나 20보다 큰경우 
		printf("학생수는 1이상 20이하의 수만 가능합니다.\n\n"); //오류메세지를 출력하고
		printf("입력 받을 학생수를 입력하세요 : "); 
		scanf_s("%d", &inputStudentSize);//다시 입력받는다.
		}

		for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) //studentIndex가 0부터 inputStudentSize-1까지 하나씩 증가하며 반복한다.
		inputScore(&(scoreArray[studentIndex]), inputStudentSize); 
		//점수를 입력받기 위한 함수를 호출한다. (&(scoreArray[studentIndex]) : 행의 studentIndex번째의 열부분의 배열을 넣기위하여 &(주소값)을 사용한다.)

		for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) { //studentIndex가 0부터 inputStudentSize-1까지 하나씩 증가하며 반복한다.
			printScore(&(scoreArray[studentIndex]), studentIndex, inputStudentSize);
			//점수를 출력하기 위한 함수를 호출한다. (&(scoreArray[studentIndex]) : 행의 studentIndex번째의 열부분의 배열을 넣기위하여 &(주소값)을 사용한다.)
			printAvg(&(scoreArray[studentIndex]), inputStudentSize);
			//평균을 출력하기 위한 함수를 호출한다. (&(scoreArray[studentIndex]) : 행의 studentIndex번째의 열부분의 배열을 넣기위하여 &(주소값)을 사용한다.)
		}

		return 0;
		}

		void inputScore(int *scoreArray, int intputIndex) {
		printf("국어 성적 입력 : ");
		scanf_s("%d", &scoreArray[0]); //0번째 배열에 국어성적을 입력받는다.
		printf("영어 성적 입력 : ");
		scanf_s("%d", &scoreArray[1]); //1번째 배열에 영어성적을 입력받는다.
		printf("수학 성적 입력 : ");
		scanf_s("%d", &scoreArray[2]); //2번째 배열에 수학성적을 입력받는다.
		}

		void printScore(int *scoreArray, int index, int intputIndex) {
		printf("[%d] %d,%d,%d", index, scoreArray[0], scoreArray[1], scoreArray[2]);
		//배열의 index번째 학생의 국어 영어 수학 점수를 출력한다.
		}

		int printSum(int *scoreArray, int inputIndex) {
			int sum = 0;//총합을 저장하기 위한 변수 

			sum = scoreArray[0] + scoreArray[1]+ scoreArray[2]; //sum에 0,1,2번째 배열의 원소값을 더하고 저장한다.
			
			printf(", 총점 : %d", sum); //총합을 출력한다.

			return sum; //sum을 리턴한다.
		}
		int printAvg(int *scoreArray, int inputIndex) { 

			int average=1; //평균을 저장하기위한 변수

			average = printSum(scoreArray, inputIndex) / 3; //printSum함수를 호출하여 sum값을 리턴받아 그값에 3을 나눠 average값에 저장한다.

			printf(", 평균 : %d\n", average); //평균을 출력한다.

			return average; //average를 리턴한다.
		}
		