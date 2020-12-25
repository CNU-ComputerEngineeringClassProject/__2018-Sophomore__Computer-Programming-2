#include <stdio.h>

long long fib(int num);
long long fibo(int n);

int main(void) {
	 int i;



	 /*
printf("음수가 아닌 수를 입력하세요 : ");
		scanf_s("%lld", &n);

	for (i = 0; i < n; i++) {
		printf("%lld ", fib(i));
		
	}
	
	/*
	int n, idx;

	printf("음수가 아닌 수를 입력하세요 : ");
		scanf_s("%d", &n);
		for(idx=0;idx<n;idx++){
		printf("%d ", fibo(idx));
		}
		*/

	
	int n, idx;

	printf("음수가 아닌 수를 입력하세요 : ");
		scanf_s("%d", &n);
		for(idx=0;idx<n;idx++){
		printf("%lld ", fibo(idx));
		}

	return 0;
}

long long fibo(int n){
	long long lastNum=1; 
	long long currentNum=1; 
	int i; 
  for (i=0; i<=n; i++){ 
        if (n == 0 || n == 1){ 
             lastNum = 1; 
             currentNum = 1; // fibo(0) = fibo(1) = 1; 
        } 
        else{ 
             int temp = lastNum; // fibo(n-2) 
             lastNum = currentNum; // fibo(n-1) 
             currentNum = temp + lastNum; // fibo(n) = fibo(n-1) + fibo(n-2) 
        } 
   } 
   return currentNum; 
}

/*
long long fib(int num) {
	if (num <= 1) {
		return 1;
	}
	else {
		return fib(num - 1) + fib(num - 2);
	}
}
*/