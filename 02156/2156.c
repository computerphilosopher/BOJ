#include <stdio.h>
#include <stdlib.h>


int max(int a, int b, int c){

	int arr[3] = {a, b, c};

	int max = 0;

	for(int i=0; i<3; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}

	return max;
}

int dp(int wines[], int n, int memo[]){

	if(memo[n] != 0){
		return memo[n];
	}
	else if(n == 0){
		return 0; 
	}

	else if(n == 1){
		return wines[1]; 
	}

	else if(n == 2){
		return wines[1] + wines[2]; 
	}

	else{
		int maximum = max( dp(wines, n-3, memo) + wines[n-1] + wines[n], dp(wines, n-2, memo) + wines[n], dp(wines, n-1, memo));	

		memo[n] = maximum;
		return maximum;
	}

}

int main(){

	int n = 0;
	scanf("%d", &n);

	int *memo = (int*)calloc(n+1, sizeof(int));
	int *wines = (int*)calloc(n+1, sizeof(int));

	for(int i=1; i<=n; i++){
		scanf("%d", &wines[i]);
	}

	printf("%d", dp(wines, n, memo));

	free(memo);
	free(wines);

	return 0;
}
