#include <stdio.h>

int main(){

	int n = 0;
	int min = 1000001;
	int max = -1000001;
	 
	scanf("%d", &n);

	int arr[n];

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	for(int i=0; i<n; i++){
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
	}

	printf("%d %d", min, max);
	
	return 0;
		
}
