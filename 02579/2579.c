#include <stdio.h>

int max(int a, int b){
	if(a>= b){
		return a;
	}
	else{
		return b;
	}
}

int memo[301]={0};

int sum(int stair[], int n){
	
	if(memo[n] !=0){
		return memo[n];
	}

	else if(n <= 1){
		
		return stair[n];
	}
	else if(n == 2){
		return stair[1] + stair[2];
	}

	else{
		memo[n] =  max(stair[n] + stair[n-1] + sum(stair, n-3), stair[n] + sum(stair, n-2));
		return memo[n];
	}

}
int main(){

	int n = 0;

	scanf("%d", &n);

	int stair[301] = {0};

	for(int i=1; i<=n; i++){
		scanf("%d", &stair[i]);
	}

	printf("%d", sum(stair, n));
	return 0;

}
