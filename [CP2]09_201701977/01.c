
#include <stdio.h>

int main(void) {

	int distance, speed; //거리와 속력을 입력받기 위한 정수형 변수
	int  hour, min; // 시와 분을 저장하기위한 정수형 변수
	double time, sec; // 시간과 초를 저장하기위한 실수형 변수
	
	printf("거리와 속력 입력 : ");
	scanf("%d %d", &distance, &speed ); //거리와 속력을 입력받는다. 정수형 변환명세%d 사용

	time = (double) distance / speed ; // 시간을 알기위해 (거리/속력)을 실수형으로 형변환한 뒤 시간변수인 time에 저장한다.

	hour = (int)time; //시간의 정수부분을 시 변수인 hour에 저장한다.

	time -= hour; //시간을 시간-시를 하여 저장한다. 정수부분을 뺀 실수부분이 남는다.
	time *= 60.0; //시간을 시간*60.0을 하여 저장한다. 시를 기준으로 되어있는 시간을 분이 기준이 되도록 바꾼다.

	min = (int)time; //시간의 정수부분을 분 변수인 min에 저장한다.

	time -= min; //시간을 시간-분을 하여 저장한다. 정수부분을 뺀 실수부분이 남는다.

	sec = time *60.0; //시간*60.0을 하여 초 변수인 sec에 저장한다. 시간을 초 기준으로 바꾸고 초에 저장.

	
	printf("소요시간은 %d시간 %d분 %.3lf초입니다.\n",hour,min,sec); //계산한 소요시간을 출력한다.
	//시와 분은 정수형 변환명세 %d를 사용하고, 초는 소수점 셋째자리 까지 나타내기 위해서 실수형 변환명세 %.3lf를 사용한다.

	return 0;
}
