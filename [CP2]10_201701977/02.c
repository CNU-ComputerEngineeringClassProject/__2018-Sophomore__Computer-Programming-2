#include <stdio.h>

void exchange(double *, double *); //�ּҸ� �μ��� �޾Ƽ� ����Ű�� �� ���� �ٲٴ� �޼ҵ�
void func(void(*fp)(double *,double *),double, double); //�μ��� ���� �� ���� ��� �� �Ŀ� exchange �Լ��� ����Ͽ� �� ���� �ٲٰ� �ٽ� ����ϴ� �޼ҵ�
int assign02(void); // ���� �����ϰ� func�Լ��� ȣ���ϴ� �޼ҵ�

int main(int argc, const char * argv[]){
	assign02(); //�Լ��� ȣ���Ѵ�.
	return 0;
}

int assign02(){  
	double a=10, b=20; //�Ǽ��� ���� a,b�� �����ϰ� ���� 10, 20���� �ʱ�ȭ ��Ų��.
	func(exchange, a,b); //fucn �Լ��� ȣ���Ѵ�.
	return 0; 
}

void exchange(double *x, double *y){ //�Ű������� �Ǽ��� ������ 2���� �޴´�.

	double temp = *x; //�Ǽ��� ����temp�� �����ϰ� *x���� �����Ѵ�.
	
	*x=*y; //�������������� �̿��Ͽ� x�� ����� �ּ��� �����ڸ��� �������������� �̿��Ͽ� y�� ����� �ּ��� ���Ұ��� �����Ѵ�.
	*y=temp; //�������������� �̿��Ͽ� y�� ����� �ּ��� �����ڸ��� temp ���� �����Ѵ�. 
}

void func(void(*fp)(double *,double *),double a, double b){// �Ű������� void�� �Լ� ������(�Ű������� �Ǽ��������ͺ��� 2��)�� �Ǽ��� ���� 2���� �Է¹޴´�.

	printf("a:%.1lf,b:%.1lf\n",a,b); // �μ��� ���� �ΰ��� �Ҽ��� ù°�ڸ����� ����Ѵ�.

	fp(&a,&b); //�Լ� �����ͷ� �Լ��� ȣ���Ѵ�.

	printf("a:%.1lf,b:%.1lf\n",a,b); // �Լ�ȣ���� ���� �ٲ���� �ΰ��� �Ҽ��� ù°�ڸ����� ����Ѵ�.
}