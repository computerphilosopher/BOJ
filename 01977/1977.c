#include <stdio.h>
#include <stdbool.h>


int main(){

	bool arr[10001] = {0};
	
	for(int i=1; i<= 100; i++){
		arr[i*i] = true;
	}

	int m = 0; 
	int n = 0;


	scanf("%d %d", &m, &n);

	int min = 10001;
	int sum = 0;
	
	for(int i=m; i<=n; i++){

		if(arr[i]){

			sum += i;
	
			if(i< min){
				min = i;
			}
		}

	}

	if(sum > 0){
		printf("%d\n%d", sum, min);
	}

	else{
		printf("-1");
	}

	return 0;

}
