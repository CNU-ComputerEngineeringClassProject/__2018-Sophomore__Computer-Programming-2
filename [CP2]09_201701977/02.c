#include <stdio.h>

int disp_menu(void); //메뉴를 출력하고 선택된 메뉴를 반환
void enter_park(int(*park_space)[2][5], int(*reserved)[3]); //주차 기능 수행 메소드
void exit_park(int(*park_space)[2][5]);// 출차 기능 수행 메소드
void reserve_park(int(*reserved)[3]); //지정차량 등록 메소드
void print_park(int(*park_space)[2][5], int(*reserved)[3]); // 주차 현황 출력 메소드
void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]); // 주차 현황 출력
int check_reservation(int(*reserved)[3], int basement, int num); //지정차량이 있는 경우 1 아닐경우 0
int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num); // 차량이 지정 차량인지 확인 지정 차량일 경우 1을 반환 ➤ ﬂoor, resv_num에 지정차량 위치 저장
int ﬁnd_space(int(*park_space)[5], int floor, int(*reserved)[3]); //빈 공간이 얼마 있는지 확인하는 메소드


int main(void) {

	int park_space[3][2][5]={0}; //크기가 높이 3, 세로 2, 가로 5인 3차원 배열을 생성하고 초기화 한다. 3층에 한층당 공간이 10개인 주차장 만들기 
	int reserved[10][3]={0}; //크기가 세로가 10, 가로가 3인 2차원 배열을 생성하고 초기화 한다. 지정차량을 위한 배열만들기

	int answer; //선택한 메뉴를 입력받기위한 정수형 변수

	answer = disp_menu(); //disp_menu 함수를 호출하여 메뉴를 출력하고 선택메뉴를 입력받아 리턴한 값을 answer에 저장한다.

	while(answer!=0){ //answer이 0일때까지 반복하는 while문

	if (answer == 1) { //만약 answer이 1일때 ('주차'선택)
		enter_park(park_space,reserved); //주차기능을 수행하는 enter_park함수를 호출한다. 
	}
	else if (answer == 2) {//만약 answer이 2일때 ('출차'선택)
		exit_park(park_space); //출차기능을 수행하는 exit_park함수를 호출한다.
	}
	else if (answer == 3) {//만약 answer이 3일때 ('지정차량등록'선택)
		reserve_park(reserved); //지정차량을 등록하는 reserve_park함수를 호출한다.
	}
	else if (answer == 4) {//만약 answer이 4일때 ('주차장현황 출력'선택)
		print_park(park_space,reserved); //주차장 현황을 출력하는 print_park함수를 호출한다.
	}
	answer = disp_menu(); //해당 answer의 함수를 호출하면 다시 disp_menu 함수를 호출하여 메뉴를 출력하고 선택메뉴를 입력받아 리턴한 값을 answer에 저장한다.
	}


	return 0; //answer이 0이되어 while문을 나오면 프로그램을 종료한다.
}

int disp_menu(void) { //메뉴를 출력하고 선택된 메뉴를 반환하는 메소드

	int answer; //선택메뉴를 입력받는 정수형 변수

	//메뉴 출력
	printf("\n1. 주차\n2. 출차\n3. 지정차량 등록\n4. 주차현황 출력\n0. 종료\n> 번호 선택 : ");
	
	scanf("%d", &answer); //선택메뉴를 입력받는다. 정수형 변환명세 %d를 사용.

	return answer; //answer을 리턴한다.

}
void enter_park(int(*park_space)[2][5], int(*reserved)[3]) { //주차 기능 수행하는 메소드 (매개변수로 정수형 포인터배열을 받는다. (3차,2차))

	int carNum; //차번호를 입력받기위한 정수형 변수
	int i, j, z; //반복문을 위한 i , 0~9 구역을 [2][5] 배열로 나눠 표현 하기 위한 z,j 
	int floor=0; //층을 저장하기 위한 변수 (실제 층아닌 배열기준 층이므로 실제 층은 floor+1층이다.)
	int answer=0; //몇번 주차장 자리인지 저장하기 위한 변수 (실제 구역이 아닌 배열기준 구역이므로 주차장 기준으로는 answer+1이다.)
	int upAndDown=0; //층 올라가고 내려가기 위한 변수 (0일때 올라감 1일때 내려감)


	printf("\n> 차번 입력(숫자 4자리) : ");
	scanf("%d", &carNum); //차번호를 입력받는다. 정수형 변환명세 %d를 사용한다.

	if(check_reserved_num(reserved,carNum,&floor,&answer)==1){ //지정차량인지 아닌지 알아보는 check_reserved_num 함수를 호출하여 1이 반환되었을 경우 (지정차량일 경우)

			z=answer/5; //지정차량의 구역인 answer에서 /5 를 하면 answer에서 5를 나눈 몫이 z에 저장된다.
			j=answer%5; //지정차량의 구역인 answer에서 %5 를 하면 answer에서 5를 나눈 나머지가 z에 저장된다.
				
				park_space[floor][z][j] = carNum; // 높이가 floor이고, 세로가 z, 가로가 j인 park_space배열에 차번호를 저장한다. (주차하는 것)
				printf("\n@ 지정차량 : %d층 %d번 주차했습니다.\n",floor+1,answer+1); //floor+1층 answer+1구역에 주차가 되었다는 메세지를 출력한다.
				return ; //지정차량을 주차했으면 enter_park함수를 종료한다.
		}

	printf("\n@ 주차 가능 공간 :"); 
	for (i = 0; i <3; i++) { //층마다 남은 공간을 세기위해서 (배열기준)높이를 나타내는 i을 사용하여 반복문을 실행한다. 
		printf("  %d층[%d대]", i+1, ﬁnd_space(park_space[i],i,reserved)); //ﬁnd_space 함수를 호출하여 i+1층 주차장의 남은 공간이 몇대인치 출력한다.
	}
	printf("\n\n");
	
	for(i=0;;){ 
		//층마다 방문하기위한 (배열기준)높이를 나타내는 i을 사용하여 반복문을 실행한다. 
		//answer이 -1이기전까지 반복해야하므로 이는 따로 조건을 달고 for문에는 조건문을 생략하고 무한반복을 한다. i도 따로 증가,감소를 할것이므로 for문에 증감식을 쓰지않는다.
		print_basement(park_space[i],i,reserved); // i+1층인 주차현황을 출력하는 print_basement함수를 호출한다.
		printf("> 주차 번호 입력(다른 층 0, 취소 -1) : ");
		scanf("%d",&answer); //주차번호를 입력받다. 정수형 변환명세 %d를 사용한다.

		if(answer==-1){ //answer가 -1일경우
			return ; // enter_park함수를 종료한다.
		}
		else if(answer==0){ //answer가 0일경우

			if(upAndDown==0){ //upAndDown이 0일경우 올라감
				i++; //i를 1증가시킨다.
				if(i==2){ //i가 2일경우 (3층이므로 이제 내려가야함)
				upAndDown=1; //upAndDown을 1로 바꾼다.
				}
			}
			
			else{ //upAndDown이 1일경우 내려감
				i--; //i를 1감소시킨다.
				if(i==0){ //i가 0일경우 (1층이므로 이제 올라가야함)
				upAndDown=0; //upAndDown을 0으로 바꾼다.
				}
			}

		}
		else{ //answer가 0,-1 이 아닐경우 
			
			answer = answer-1; //answer을 1빼서 저장한다. (배열에서의 구역번호는 실제 구역보다 1작으므로)
			z=answer/5; //주차구역인 answer에서 /5 를 하면 answer에서 5를 나눈 몫이 z에 저장된다.
			j=answer%5; //주차구역인 answer에서 %5 를 하면 answer에서 5를 나눈 나머지가 z에 저장된다.
			park_space[i][z][j] = carNum; // 높이가 i이고, 세로가 z, 가로가 j인 park_space배열에 차번호를 저장한다. (주차하는 것)
			printf("\n@ 주차되었습니다!\n"); //주차했음을 알리는 메세지를 출력한다.
			return ; //주차를 했으면 enter_park함수를 종료한다.
		}
	}
		printf("\n");
}
void exit_park(int(*park_space)[2][5]) { // 출차 기능 수행 메소드 (매개변수로 정수형 포인터배열을 받는다. (3차))

	int carNum; //차번호를 입력받는 정수형 변수
	int i, j, z; //삼차원 배열의 높이를 나타내기위한 i , 세로를 나타내기 위한 j, 가로를 나타내기 위한 z 

	printf("\n> 차번 입력(숫자 4자리) : ");
	scanf_s("%d", &carNum); //차번호를 입력받는다. 정수형 변환명세 %d를 사용한다.

	for (i = 0; i < 3; i++) { //(배열기준)높이를 나타내는 i을 사용하여 반복문을 실행한다. 
		for (j = 0; j < 2; j++) { //(배열기준)세로를 나타내는 j을 사용하여 반복문을 실행한다. 
			for (z = 0; z < 5; z++) { //(배열기준)가로를 나타내는 z을 사용하여 반복문을 실행한다. 
				if (park_space[i][j][z] == carNum) { //높이가 i, 세로가 j, 가로가 z인 배열의 원소값이 차번호와 같을때 (주차되었을때)
					park_space[i][j][z] = 0; //원소값을 0으로 바꾸고
					printf("@ 출차되었습니다.\n"); //출차되었다는 메세지를 출력한다.
					return; // 출차되었으면 exit_park 함수를 종료한다.
				}
			}
		}

	}

	printf("@ 해당 차량이 없습니다.\n"); //만약 for문을 나왔을경우 (입력한 차가 주차되지 않았을 경우) 주차된 차량이 없다는 메세지를 출력한다.

}
void reserve_park(int(*reserved)[3]) { // 지정차량 등록 메소드 (매개변수로 정수형 포인터배열을 받는다. (2차))

	int carNum, floor, num; //차번호 , 층, 구역을 입력하는 정수형 변수

	printf("\n> 층과 번호 입력(종료 0) : ");
	scanf("%d", &floor); //층을 입력받는다. 정수형 변수 %d를 사용한다.
	if(floor==0) return ; //0을 입력받으면 함수를 끝낸다.
	scanf(" %d",&num); //구역을 입력받는다. 정수형 변수 %d를 사용한다.


	while (floor!=0) { //층이 0이 아니라면 (0일경우 종료)
		printf("> 등록차량 번호 입력 : ");
		scanf("%d", &carNum); //차번호를 입력받는다. 정수형 변수 %d를 사용한다.
		if(check_reservation(reserved, floor, num) == 1){ //지정차량이 있는지 확인하는 check_reservation함수를 호출하여 반환값이 1이라면 (지정차량이 있다면)
		printf("@ 이미 지정차량이 있습니다.\n"); //지정차량이 있다는 메세지를 출력한다.
		}
		else{
			reserved[num-1 ][floor-1 ] = carNum; //세로가 num-1이고 가로가 floor-1인 배열의 원소값을 차번호로 저장한다.
			printf("@ 등록되었습니다.\n"); //지정차량으로 등록되었다는 메세지를 출력한다.
		}
		printf("\n> 층과 번호 입력(종료 0) : "); //0을 입력받기 전까지 계속해서 반복하기위해
			scanf("%d", &floor); //층을 입력받는다. 정수형 변수 %d를 사용한다.
			if(floor==0)break; //0을 입력받으면 while문을 나온다.
			scanf(" %d",&num); //구역을 입력받는다. 정수형 변수 %d를 사용한다.
	}
}
void print_park(int(*park_space)[2][5], int(*reserved)[3]) {//주차 현황 출력 메소드 (매개변수로 정수형 포인터배열을 받는다. (3차,2차))

	int i, j, k; //삼차원 배열의 높이를 나타내기위한 i, 세로를 나타내기위한 j, 가로를 나타내기 위한 k

	printf("\n");
	for (i = 0; i < 3; i++) {//i는 0부터 하나씩 증가하며 3보다 작을때까지 반복문을 실행한다. 배열의 높이

		printf("\n[ %d층]=============================\n", i + 1); //i+1층을 출력한다.

		for (j = 0; j < 2; j++) { //j는 0부터 하나씩 증가하며 2보다 작을때까지 반복문을 실행한다. 배열의 세로

			for (k = 0; k < 5; k++) {//k는 0부터 하나씩 증가하며 5보다 작을때까지 반복문을 실행한다. 배열의 가로

				if(park_space[i][j][k]!=0){ //높이가 i 세로가 j 가로가 k인 배열의 원소값이 0이 아닐때 (주차되어있지않을때)
					printf("[%d] ", park_space[i][j][k]); //원소값으로 저장되어있는 차번호를 출력한다.
				
				}
				else if (reserved[(j * 5) + k][i] != 0) { //세로가 (j*5)+k 이고 가로가 i 인 배열의 원소값이 0이 아닐때 (지정차량 등록되어있을때)
					printf("[resv] "); //예약메세지를 출력한다.
				}
				else { //그 외에는 주차,지정차량이 아닌 빈공간을 의미하므로 주차구역의 번호를 출력한다. if문이 있는 이유는 일의 자리 수일때와 10일때 출력칸을 맞추기 위해서 이다.
					if((j * 5) + k +1==10){ 
						printf("[ %d ] ", (j * 5) + k +1);
					}
					else{
					printf("[  %d ] ", (j * 5) + k +1);
					}
				}
			}
			printf("\n");
		}
		printf("\n");
	}


}
void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]) { // 주차 현황 출력 (매개변수로 정수형과 정수형 포인터배열을 받는다. (2차,2차))

	int  j, k; //이차원 배열의 세로를 나타내기위한 i, 가로를 나타내기 위한 j

		printf("\n[ %d층]=============================\n", floor+1); //floor+1층을 출력한다.

		for (j = 0; j < 2; j++) { //j는 0부터 하나씩 증가하며 2보다 작을때까지 반복문을 실행한다. 배열의 세로
			for (k = 0; k < 5; k++) {//k는 0부터 하나씩 증가하며 5보다 작을때까지 반복문을 실행한다. 배열의 가로
				if(park_space[j][k]!=0){ //세로가 j 가로가 k인 배열의 원소값이 0이 아닐때 (주차되어있지않을때)
					printf("[%d] ", park_space[j][k]);//원소값으로 저장되어있는 차번호를 출력한다.
				}    
				else if (reserved[j*5+k][floor] != 0) {//세로가 (j*5)+k 이고 가로가 floor 인 배열의 원소값이 0이 아닐때 (지정차량 등록되어있을때)
					printf("[resv] "); //예약메세지를 출력한다.
				}      
				else { //그 외에는 주차,지정차량이 아닌 빈공간을 의미하므로 주차구역의 번호를 출력한다. if문이 있는 이유는 일의 자리 수일때와 10일때 출력칸을 맞추기 위해서 이다.
					if(j*5+k+1 == 10){
						printf("[ %d ] ",j*5+k+1);
					}
					else{
					printf("[  %d ] ",j*5+k+1);
				}
				}
			}
			printf("\n");
		}
		printf("\n");
}
int check_reservation(int(*reserved)[3], int basement, int num) {// 주차구역에 지정차량이 있는지 확인하는 메소드,지정차량이 있는 경우 1 아닐경우 0 (매개변수로 정수형과 정수형 포인터배열을 받는다. (2차))

	if (reserved[num-1][basement-1] != 0) { //세로(배열구역)가 num-1이고 가로(높이)가 basement-1인 원소값이 0이 아닐경우 (지정차량이 있는경우)
		return 1; //지정차량이 있으므로 1을 반환한다.
	}
	return 0; //지정차량이 없으므로 0을 반환한다.

}
int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num) { // 차량이 지정 차량인지 확인하는 메소드, 지정 차량일 경우 1을 반환 (매개변수로 정수형과 정수형 포인터와 정수형 포인터배열을 받는다. (2차))

	int i, j; //이차원 배열의 세로(구역)를 나타내기위한 j, 가로(높이)를 나타내기 위한 i

	for (i = 0; i < 3; i++) { //i는 0부터 하나씩 증가하며 3보다 작을때까지 반복문을 실행한다. 배열의 가로(주차의 높이)
		for (j = 0; j < 10; j++) { //j는 0부터 하나씩 증가하며 5보다 작을때까지 반복문을 실행한다. 배열의 세로 (주차의 구역)
			if (reserved[j][i] == car_num) { //배열의 세로가 j이고 가로가 i인 원소값이 차번호 일때
				*floor = i; //포인터 floor는 i로 저장한다.
				*resv_num = j; //포인터 resv_num은 j로 저장한다.
				return 1; //지정차량이므로 1을 반환한다.
			}
		}
	}

	return 0; // 지정차량이 아니므로 0을 반환한다.

}
int ﬁnd_space(int(*park_space)[5], int floor, int(*reserved)[3]) { //빈 공간이 얼마 있는지 확인하는 메소드 (매개변수로 정수형과 정수형 포인터배열을 받는다. (2차,2차))
	
	int i,j; //이차원 배열의 세로를 나타내기위한 i, 가로를 나타내기 위한 j
	int empty=0; //빈공간의 개수를 세기위한 정수형 변수 0으로 초기화 시킨다.

	for(i=0;i<2;i++){ //i는 0부터 하나씩 증가하며 2보다 작을때까지 반복문을 실행한다. 배열의 세로
		for(j=0;j<5;j++){ //j는 0부터 하나씩 증가하며 5보다 작을때까지 반복문을 실행한다. 배열의 가로
			if(park_space[i][j]==0){ //세로가i이고 가로가 j인 배열의 원소값이 0일때 (그 구역에 주차되어있는 차가 없을때)
				if(reserved[i*5+j][floor]==0){ //배열의 세로(구역)이 i*5+j이고 가로(높이)가 floor인 원소값이 0일때 (구역에 지정차량이 없을때)
				empty++; //빈공간이므로 empty를 하나 증가시킨다.
				}
			}
		}
	}

	return empty; //empty를 리턴한다.
}
