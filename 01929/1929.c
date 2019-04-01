#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main(){

	int m=0;
	int n=0;

	int min = 10001;
	int sum = 0;

	bool prime [1000001];

	memset(prime, true, sizeof(prime));

	prime[0]= false;
	prime[1]= false;

	scanf("%d", &m);
	scanf("%d", &n);
	 
	for(int i=2; i<=n; i++){

		if(prime[i] == false){
			continue;
		}

		else{
			for(int j=i*2; j<=n; j+=i){
				prime[j] = false;
			}
		}
	}

	for(int i=m; i<=n; i++){

		if(prime[i]){

			printf("%d\n", i);
			
		}
	}

	return 0;

}
