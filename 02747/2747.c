#include <stdio.h> 

int memo[45];

unsigned int fib(unsigned int n){

	if(n < 2){
		return n;
	}
	else if(memo[n]){
		return memo[n];
	}

	else{
		memo[n] = fib(n-2) + fib(n-1);
		return memo[n];
	}
}

int main(){

	int n = 0;
	scanf("%d", &n);

	printf("%u", fib(n));

}
