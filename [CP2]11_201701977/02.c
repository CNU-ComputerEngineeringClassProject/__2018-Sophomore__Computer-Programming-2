#include <stdio.h>

struct cracker{ //cracker정보 구조체 선언
	int price; //가격을 저장할 멤버
	int calories; //열량을 저장할 멤버
};

int main(void){
	struct cracker basasak; //cracker 구조체 변수 선언
	printf("바사삭의 가격과 열량을 입력하세요 : ");
	scanf("%d %d",&basasak.price, &basasak.calories); //가격과 열량을 입력 받고 각각 price멤버와 calories멤버에 저장한다.
	printf("바사삭의 가격 : %d원\n", basasak.price); //price멤버의 값을 출력한다. (가격 출력)
	printf("바사삭의 열량 : %dkcal\n",basasak.calories); //calories멤버의 값을 출력한다. (열량 출력)

	return 0;
}