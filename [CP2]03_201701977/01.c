#include <stdio.h>

int main(void){

	int numberOfLine=1; //줄의 개수를 위한 변수이고, 1로 초기화 해준다.
	int numberOfColumns, frontBlank, createLine, createSpace; // 열의 개수, 별 앞의 빈칸 개수, 줄을 생성, 칸 생성을 위한 변수를 만든다.
	
	while(numberOfLine !=0 ){ //0을 입력 받기 전까지 계속해서 프로그램을 실행시킨다.

	printf("개수를 입력해 주세요 : [종료 : 0]\n"); // 개수를 입력 받게 하는 메세지을 출력한다.
	scanf("%d",&numberOfLine); // 줄의 개수를 입력받는다.
	
	if(numberOfLine ==0){ //개수로 0을 입력받았을 경우 프로그램을 종료한다. 
		return 0;
	}
	else if(numberOfLine < 0 || numberOfLine>10){ //개수로 음수나 10이상의 수를 입력 받았을 경우 다시 입력하라는 메세지를 출력한다.
		printf("다시 입력해주세요!\n\n");

	}else{	// 개수로 0보다 크고 10보다 같거나 작은 수를 입력받았을 경우.

		numberOfColumns = (numberOfLine * 2) -1; // 열의 개수를 계산한다. (입력받은 줄의 개수 *2 -1)
		frontBlank =numberOfLine-1; // 첫 행에서 별출력 전 앞의 빈칸개수를 계산한다. (입력받은 줄의 개수 -1)

		
	for(createLine=0 ; createLine<numberOfLine ; createLine++){ //사용자가 입력한 줄의 개수만큼 출력하도록 한다. 
		for(createSpace=1 ; createSpace<= numberOfColumns ; createSpace++){ // 칸생성이 열의 개수만큼만 만들어지도록 한다.
			
			if(createSpace <= frontBlank || createSpace > numberOfColumns-frontBlank){ 
				// 칸생성 변수가 별앞의 빈칸 개수와 같거나 작을때(별 앞부분의 빈칸을 생성하기 위해서), 
				// 또는 칸생성 변수가 열의개수에서 앞의 별의 개수를 뺀 수가 클때 (별 뒷부분의 빈칸을 생성하기위해서) 빈칸을 생성한다.
				putchar(' ');
			}else{ //그외에는 별을 출력한다.
				printf("*");
			}
		
		}//한 줄의 빈칸과 별이 모두 출력되었을때 나온다.

		frontBlank=frontBlank-1;// 별 앞 빈칸 개수를 하나 줄인다.
		putchar('\n'); //줄을 다음줄로 바꾼다.
	}
		
	}
	
	}
}