#include <stdio.h>

int main(){

	int n=0;
	int i=0;
	int j=0;

	scanf("%d",&n);

	for(i=n-1; i>=0; i--){
		for(j=i; j>=0; j--){
			printf("*");
		}
		printf("\n");
	}

}

