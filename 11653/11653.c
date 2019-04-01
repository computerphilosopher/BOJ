#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PRIME_MAX 10000000


void erato(bool arr[], int size){


	arr[0] = false;
	arr[1] = false;


	for(int i=0; i<size; i++){
		if(arr[i]){
			for(int j=2; i*j<size; j++){
				arr[i*j] = false;
			}
		}
	}
}

bool is_prime_divisor(bool prime[], int n, int divisor){

	return (prime[divisor] && n % divisor == 0);

}

void divide_by_prime(bool prime[], int n){

	for(int i=2; i<=n; i++){
		int temp = n;
		if(is_prime_divisor(prime, n,i)){
			while(temp % i == 0){	
				printf("%d\n", i);
				temp /= i;
			}
		}
	}
}


int main(){

	bool *prime = (bool*)malloc(sizeof(bool)*PRIME_MAX);
	memset(prime, true, sizeof(bool)*PRIME_MAX);

	erato(prime,PRIME_MAX);

	int a = 0;

	scanf("%d", &a);

	divide_by_prime(prime, a);

	free(prime);

	return 0;

}
