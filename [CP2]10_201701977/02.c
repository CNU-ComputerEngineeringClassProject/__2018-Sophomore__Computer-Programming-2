#include <stdio.h>

void exchange(double *, double *); //주소를 인수로 받아서 가리키는 두 값을 바꾸는 메소드
void func(void(*fp)(double *,double *),double, double); //인수로 받은 두 값을 출력 한 후에 exchange 함수를 사용하여 두 값을 바꾸고 다시 출력하는 메소드
int assign02(void); // 값을 생성하고 func함수를 호출하는 메소드

int main(int argc, const char * argv[]){
	assign02(); //함수를 호출한다.
	return 0;
}

int assign02(){  
	double a=10, b=20; //실수형 변수 a,b를 생성하고 각각 10, 20으로 초기화 시킨다.
	func(exchange, a,b); //fucn 함수를 호출한다.
	return 0; 
}

void exchange(double *x, double *y){ //매개변수로 실수형 포인터 2개를 받는다.

	double temp = *x; //실수형 변수temp를 생성하고 *x값을 저장한다.
	
	*x=*y; //간접참조연산을 이용하여 x에 저장된 주소의 원소자리에 간접참조연산을 이용하여 y에 저장된 주소의 원소값을 저장한다.
	*y=temp; //간접참조연산을 이용하여 y에 저장된 주소의 원소자리에 temp 값을 저장한다. 
}

void func(void(*fp)(double *,double *),double a, double b){// 매개변수로 void형 함수 포인터(매개변수로 실수형포인터변수 2개)와 실수형 변수 2개를 입력받는다.

	printf("a:%.1lf,b:%.1lf\n",a,b); // 인수로 받은 두값을 소수점 첫째자리까지 출력한다.

	fp(&a,&b); //함수 포인터로 함수를 호출한다.

	printf("a:%.1lf,b:%.1lf\n",a,b); // 함수호출을 통해 바뀌어진 두값을 소수점 첫째자리까지 출력한다.
}