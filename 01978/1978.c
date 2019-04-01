#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(){

	int n=0;
	int count=0;
	int temp = 0;

	bool prime[1001] = {0};

	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for(int i=2; i<=1000; i++){

		if(prime[i] == false){
			continue;
		}
		else{
			for(int j=i*2; j<=1000; j+=i){
				prime[j] = false;
			}
		}
	}

	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &temp);
		if(prime[temp]){
			count++;
		}
	}

	printf("%d", count);


	return 0;

}


