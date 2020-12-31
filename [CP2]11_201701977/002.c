#include <stdio.h>
struct student //학생의  정보를 만들 구조체 선언
{
	int num;//학번을 저장할 멤버
	char name[20]; //이름을 저장할 멤버
	int Kgrade; //국어점수를 저장할 멤버
	int Egrade; //영어점수를 저장할 멤버
	int Mgrade; //수학점수를 저장할 멤버
	int sum; //세 점수의 총합을 저장할 멤버
	double average; //평균점수를 저장할 멤버
	char grade; //학번을 저장할 멤버
};
typedef struct student Student; //Student형으로 재정의

void input_data(Student *pary,int inputSize); //학생정보를 입력받는 메소드 
void clac_data(Student *pary,int inputSize); //학생의 총점, 평균, 학점 계산하는 메소드
void sort_data(Student *pary,int inputSize); //학생의 데이터 정렬
void print_data(Student *pary,int inputSize); //학생데이터 출력



int main(void){

	int numOfStudent; //학생수를 입력받을 정수형 변수
	Student list[100]; //요소가 100개인 구조체 배열 선언
	int i; //반복문을 위한 정수형 변수

	printf(">학생수 입력 : ");
	scanf("%d",&numOfStudent); //학생수를 입력받는다.

	input_data(list,numOfStudent); //학생정보를 받기위해 함수를 호출한다.
	clac_data(list,numOfStudent); //학생의 입력받은 세점수를 이용하여 총점,평균,학점을 계산하는 함수를 호출

	printf("\n정렬 전 데이터 ...\n\n");
	print_data(list,numOfStudent); //학생데이터를 출력하는 함수를 호출한다.

	printf("\n# 정렬 후 데이터 ...\n\n");
	sort_data(list,numOfStudent); //데이터를 평균 기준 성적순으로 정렬하는 함수를 호출한다.
	print_data(list,numOfStudent); //학생데이터를 출력하는 함수를 호출한다.
	
	return 0;
}


void input_data(Student *pary,int inputSize){//학생정보를 입력받는 메소드 (매개변수는 Sudent형의 포인터, int형 변수)

	int i; //반복문을 위한 정수형 변수

	for(i=0;i<inputSize;i++){ //학생수 만큼 반복한다.
	printf(">학번 : "); 
	scanf("%d",&pary[i].num); //학번을 입력 받고 i번째 배열 num멤버에게 저장한다.
	printf(">이름 : ");
	scanf("%s",pary[i].name); //이름을 입력 받고 i번째 배열 name멤버에게 저장한다.
	printf(">국어,영어,수학 점수 : ");
	scanf("%d %d %d",&pary[i].Kgrade,&pary[i].Egrade,&pary[i].Mgrade);  //국어 영어 수학 점수를 차례로 입력 받고 i번째 배열 num멤버에게 저장한다.
	}
}
void clac_data(Student *pary,int inputSize){//학생의 총점, 평균, 학점 계산하는 메소드 (매개변수는 Sudent형의 포인터, int형 변수)
	
	int i; //반복문을 위한 정수형 변수
	for(i=0;i<inputSize;i++){ //학생수 만큼 반복한다.
		pary[i].sum = pary[i].Kgrade + pary[i].Egrade + pary[i].Mgrade; //i번째 배열 Kgrade, Egrade, Mgrade멤버의 값을 더하고 sum멤버에게 저장한다. (총합 구하기)
		pary[i].average = (double) pary[i].sum / 3; //i번째 배열 sum멤버의 값을 3으로 나누고 double형으로 형변화 한후 average멤버에게 저장한다. (평균 구하기)

		if(pary[i].average >= 90){ //i번째 배열 average멤버의 값이 90 이상이라면
			pary[i].grade = 'A'; //i번째 배열 grade멤버에게 'A'를 저장한다.
		}else if(pary[i].average >= 80){ //아닌 경우 i번째 배열 average멤버의 값이 90 이상이라면
				pary[i].grade = 'B'; //i번째 배열 grade멤버에게 'B'를 저장한다.
		}else if(pary[i].average >= 70){ //아닌 경우 i번째 배열 average멤버의 값이 90 이상이라면
				pary[i].grade = 'C'; //i번째 배열 grade멤버에게 'C'를 저장한다.
		}else{ //아닌 경우
			pary[i].grade = 'F'; //i번째 배열 grade멤버에게 'F'를 저장한다.
		}

	}

}
void sort_data(Student *pary,int inputSize){ //학생의 데이터 정렬 (매개변수는 Sudent형의 포인터, int형 변수)
	
	int i,j; //반복문을 위한 정수형 변수
	Student tempStu; //구조체 변수를 선언한다. 

	for(i=0;i<inputSize;i++){ //학생수 만큼 반복한다.
		for(j=i;j<inputSize;j++){ //학생수 만큼 반복한다.(j는 i부터 : 이전은 이미 정렬되어있기때문에) 
			if(pary[i].average < pary[j].average){ //i번째 배열의 average멤버의 값보다 j번째 배열 average멤버의 값이 더 클경우
				tempStu = *(pary+i); //tempStu에 pary+i배열의 요소를 저장한다.
				*(pary+i)=*(pary+j); //pary+i번째 배열에 pary+j배열의 요소를 저장한다.
				*(pary+j)=tempStu; //pary+j번째 배열에 tempStu를 저장한다.
			}
		}	
	}
}
void print_data(Student *pary,int inputSize){  //학생데이터 출력 (매개변수는 Sudent형의 포인터, int형 변수)

	int i; //반복문을 위한 정수형 변수

	for(i=0;i<inputSize;i++){ //학생수 만큼 반복한다.
	printf(" %d %s  %d %d %d	%d	%.1lf	%c\n",pary[i].num, pary[i].name,pary[i].Kgrade,pary[i].Egrade,pary[i].Mgrade,pary[i].sum,pary[i].average,pary[i].grade);
	//i번째 배열의 num, name, Kgrade, Egrade, Mgrade, sum, average, grade멤버의 값을 출력한다.
	//학생의 정보를 출력한다.
	}
}