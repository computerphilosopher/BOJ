#include <stdio.h>

int main(){

	int arr[5] = {0};
	

	for(int i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	

	int power_sum= 0;

	for(int i=0; i<5; i++){

		power_sum += (arr[i] * arr[i]);

	}

	printf("%d", power_sum%10);


}
