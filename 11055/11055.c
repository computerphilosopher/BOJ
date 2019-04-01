#include <stdio.h>

int cache[1001];

int max(int a, int b){
	return a>b ? a:b;
}

int dp(int A[], int n){
	int ret = 0;
	
	for(int i=0; i<n; i++){
		
		cache[i]= A[i];
		
		for(int j=0; j<i; j++){	
			if(A[j] < A[i]){
				if(cache[i] < cache[j] + A[i]){
					cache[i] = cache[j] + A[i];
				}
			}
		}	
		
		ret = max(ret, cache[i]);
	}
	return ret;
}

int main(){
	
	int n = 0;
	scanf("%d", &n);
	
	int A[n];
	
	for(int i=0; i<n; i++){
	scanf("%d", &A[i]);
	}
	
	printf("%d", dp(A, n));
	
}
