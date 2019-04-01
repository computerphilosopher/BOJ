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

	int n = 0;

	scanf("%d", &n);
	
	int a[n];
	int b[n];

	for(int i=0; i<n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	for(int i=0; i<n; i++){
		printf("%d\n", lcm(gcd(a[i],b[i]), a[i], b[i]));
	}


}


