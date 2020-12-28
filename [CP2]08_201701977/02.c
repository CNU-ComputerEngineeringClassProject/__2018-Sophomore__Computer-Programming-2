
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int checkLottoNumber(int * lottoNums) ; //숫자를 입력받아 lottoNums에서 같은 숫자가 있는지 확인하는 함수
void makeLottoNumber(int * lottoNums) ; //배열에 로또 번호를 랜덤으로 입력하는 함수 

int main(void){

	int lottoNumber[6] = {0}; //로또 번호를 저장하는 배열.
	int Lotto; //맞은 개수를 저장할 정수형 변수
	int i; //반복문에 사용하기위한 정수형 변수

	srand((unsigned int)time((time_t*)NULL));

	makeLottoNumber(lottoNumber); //로또 번호 생성을 위해 함수를 호출한다.

	Lotto = checkLottoNumber(lottoNumber); //로또번호 몇개를 맞췄는지 알기 위해서 함수를 호출하고 반환값을 Lotto에 저장한다.

	
	printf("로또 번호 : ");

	for(i=0;i<6;i++){ //로또 번호를 출력하는 반복문
		printf("%d ",lottoNumber[i]);
	}

	
	printf("\n총 %d개의 맞는 숫자가 있습니다.\n",Lotto); //몇개를 맞췄는지 출력함.

	return 0;
}


void makeLottoNumber(int * lottoNums) {
	
	int i,j; //반복문을 위한 정수형 변수

	
	for(i=0; i<6; i++){ //랜덤으로 1~45까지 수를 배열의 원소로 입력받기위한 for문
		lottoNums[i] = rand()%45+1; //lottoNums의 i번째에 1~45중 하나의 수를 입력받는다.
		for(j=0;j<i;j++){ //0~i-1까지 배열 원소값과 i번째 배열 원소값을 비교하여 같은 값이 있는지를 알아보는 반복문
			if(lottoNums[j]==lottoNums[i]){ //만약 j번째 배열과 i번째 배열의 원소값이 같다면
			lottoNums[i] = rand()%45 +1;//i번째 배열값을 다시 입력 받는다.
			j=0;//그리고 j를 0으로 설정하여 다시 0~i-1까지 지금 입력받은 i번째 원소값과 같은지 비교한다.
			}
		}
	}
}

int checkLottoNumber(int * lottoNums){

	int inarr[6] = {0}; //크기가 6인 배열을 만든다.(사용자가 입력한 수를 저장하기위해)
	int num; //사용자가 입력한 숫자를 입력받기위한 정수형 변수
	int i=0, j=0;//반복문을 위해 정수형 변수
	int Lotto=0; //몇개 맞췄는지 알기위한 정수형 변수


	while(inarr[5]==0){ // 마지막번째 배열원소값이 채워지기전까지 반복문을 실행한다.

	printf("번호 입력 : ");
	scanf("%d",&num); //번호를 입력받아 num에 저장한다.

	
	
	for(i=0;i < 6;i++){
		if( num <1 || num > 45){ //num이 1보다 작거나 45보다 클때 
			printf("(1~45)번호를 입력하세요!\n"); //오류메세지를 출력하고
			break; //반복문을 나온다.
		}
		else if(inarr[i] == num) { //num이 이미 불려진 숫자라면
			printf("같은 번호가 있습니다!\n"); //오류메세지를 출력하고
			break;//반복문을 나온다.
		}

		else if(inarr[i] == 0){//num이 1~45 중의 하나고 처음 불려지는 숫자이고 i번째 원소가 0일경우(아직 번호입력이 안된것)
			inarr[i] = num; //i번째 배열의 원소값으로 num을 저장한다.

			for(j=0 ; j<6 ; j++){//로또 번호와 num이 일치하는지 알기위한 반복문
				if(lottoNums[j] == num){//j번째 배열의 원소값와 num이 일치한다면
					Lotto++;//Lotto를 하나 증가시키고
					break;//반복문을 나온다.
				}

			}

			break;//반복문을 나온다.
		}
	}
	
	}
return Lotto; //Lotto를 리턴한다.;
}

