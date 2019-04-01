#include <stdio.h>

int score_count(int arr[], int n){

	int score=0;
	int streak=0;

	for(int i=0; i<n; i++){
		if(arr[i]){
			streak++;
			score += streak;
		}
		else{
			streak=0;
		}
	}

	return score;

}

int main(){

	int n = 0;
	
	scanf("%d", &n);

	int arr[n];

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("%d", score_count(arr, n));

	return 0;

}

