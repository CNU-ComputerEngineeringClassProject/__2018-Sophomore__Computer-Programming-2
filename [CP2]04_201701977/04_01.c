#include <stdio.h>

int main(void){

	int numberOfLine=1; //줄의 개수를 위한 변수이고, 1로 초기화 해준다.
	int numberOfColumns, frontBlank, createLine, createSpace; // 열의 개수, 별 앞의 빈칸 개수, 줄을 생성, 칸 생성을 위한 변수를 만든다.
	
	printf("사이즈를 입력하세요 : "); // 개수를 입력 받게 하는 메세지을 출력한다.
	scanf("%d",&numberOfLine); // 줄의 개수를 입력받는다.
	

	while(numberOfLine < 0 || numberOfLine>20){ //개수로 음수나 20이상의 수를 입력 받았을 경우 다시 입력하라는 메세지를 출력한다.
		if(numberOfLine < 0 || numberOfLine>20){
		printf("다시 입력해주세요!\n\n");
		}
		printf("사이즈를 입력하세요 : "); // 개수를 입력 받게 하는 메세지을 출력한다.
		scanf("%d",&numberOfLine); // 줄의 개수를 입력받는다.
		
	}

	if(numberOfLine%2 ==0 ){ //만약 입력받은 줄의 개수가 짝수일경우

		numberOfLine = numberOfLine / 2 ; //줄의 개수를 반으로 나눈다. (윗부분과 아랫부분을 따로 만들기 위해서)
		numberOfColumns = (numberOfLine * 2) -1; // 열의 개수를 계산한다. (입력받은 줄의 개수의 반 *2 -1)
		frontBlank =numberOfLine-1; // 첫 행에서 별출력 전 앞의 빈칸개수를 계산한다. (입력받은 줄의 개수의 반 -1)

		
	for(createLine=0 ; createLine<numberOfLine ; createLine++){ //사용자가 입력한 줄의 개수의 반만큼 출력하도록 한다. 
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

	//아랫부분 만들기 (윗부분은 삼각형이로 아래는 역삼각형이기때문에 반대로 만든다고 생각함.)

	frontBlank = 0; //별앞 빈칸 개수를 0으로 초기화 한다.

	for(createLine =0 ; createLine<numberOfLine ; createLine++){ //사용자가 입력한 줄의 개수의 반만큼 출력하도록 한다. 

		for(createSpace=1 ; createSpace<= numberOfColumns ; createSpace++){ // 칸생성이 열의 개수만큼만 만들어지도록 한다.
			
			if(createSpace <= frontBlank || createSpace > numberOfColumns-frontBlank){ 
				// 칸생성 변수가 별앞의 빈칸 개수와 같거나 작을때(별 앞부분의 빈칸을 생성하기 위해서), 
				// 또는 칸생성 변수가 열의개수에서 앞의 별의 개수를 뺀 수가 클때 (별 뒷부분의 빈칸을 생성하기위해서) 빈칸을 생성한다.
				putchar(' ');
			}else{ //그외에는 별을 출력한다.
				printf("*");
			}
		
		}//한 줄의 빈칸과 별이 모두 출력되었을때 나온다.

		frontBlank=frontBlank+1;// 별 앞 빈칸 개수를 하나 늘린다.
		putchar('\n'); //줄을 다음줄로 바꾼다.
	}
	}
	
	
	else{//줄의 개수가 홀수일경우

		numberOfLine = numberOfLine / 2 +1; //홀수는 중간에 가장 긴것이 한줄있기때문에 줄의 개수값을 2로 나눠 하나를 더해준다. (윗부분을 아랫줄보다 한줄 더 만들기 위해서)
		numberOfColumns = (numberOfLine * 2) -1; // 열의 개수를 계산한다. (numberOfLine *2 -1)
		frontBlank =numberOfLine-1; // 첫 행에서 별출력 전 앞의 빈칸개수를 계산한다. (numberOfLine -1)

		
	for(createLine=0 ; createLine<numberOfLine ; createLine++){ //사용자가 입력한 줄의 개수의 반+1 만큼 출력하도록 한다. 
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

	//아랫부분 만들기 (윗부분은 삼각형이로 아래는 역삼각형이기때문에 반대로 만든다고 생각함./)
	//그리고 홀수는 아랫부분을 한줄 덜 만들어야한다. (아랫부분은 중간에 빈칸없이 가장 긴부분이 없어야함)

	frontBlank = 1; // 별 앞 빈칸 개수를 1로 초기화 한다.

	for(createLine =1 ; createLine<numberOfLine ; createLine++){ //사용자가 입력한 줄의 개수의 반만큼 출력하도록 한다. 

		for(createSpace=1 ; createSpace<= numberOfColumns ; createSpace++){ // 칸생성이 열의 개수만큼만 만들어지도록 한다.
			
			if(createSpace <= frontBlank || createSpace > numberOfColumns-frontBlank){ 
				// 칸생성 변수가 별앞의 빈칸 개수와 같거나 작을때(별 앞부분의 빈칸을 생성하기 위해서), 
				// 또는 칸생성 변수가 열의개수에서 앞의 별의 개수를 뺀 수가 클때 (별 뒷부분의 빈칸을 생성하기위해서) 빈칸을 생성한다.
				putchar(' ');
			}else{ //그외에는 별을 출력한다.
				printf("*");
			}
		
		}//한 줄의 빈칸과 별이 모두 출력되었을때 나온다.

		frontBlank=frontBlank+1;// 별 앞 빈칸 개수를 하나 늘린다.
		putchar('\n'); //줄을 다음줄로 바꾼다.
	}




	}

	}