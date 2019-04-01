#include <stdio.h>

int gcd(int a, int b){

	if( a % b == 0){
		return b;
	}

	else{
		return gcd(b, a%b);
	}

}

int lcm(int gcd, int a, int b){

	int x = a/gcd;
	int y = b/gcd;

	return gcd * x * y;

}

int main(){

	int a = 0;
	int b = 0;

	scanf("%d %d", &a, &b);

	printf("%d\n%d", gcd(a,b), lcm(gcd(a,b), a, b));

}


