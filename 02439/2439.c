#include <stdio.h>

int main(){

	int n = 0;

	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		
		int c= n-(i+1);
		
		for(int j=0; j<c; j++){
			printf(" ");
		}

		for(int j=0; j<n-c; j++){
			printf("*");
		}

		printf("\n");
	}

	return 0;

}
