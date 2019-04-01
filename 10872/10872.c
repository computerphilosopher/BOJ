#include <stdio.h>

int fac(int n){

	if(n==0){
		return 1;
	}

	if(n < 2){
		return n;
	}

	else{
		return n*fac(n-1);
	}
}

int main(){

	int n=0;

	scanf("%d", &n);

	printf("%d", fac(n));

}


