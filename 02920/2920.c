#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SCALE_LENGTH 8

int main(){

	int i=0; 
	int arr[SCALE_LENGTH]={0};

	for(i=0; i<SCALE_LENGTH; i++){
		scanf("%d", &arr[i]);
	}

	if(arr[0]==1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5&& arr[5] == 6 && arr[6] == 7&& arr[7] == 8){
		printf("ascending");
	} 
	
	else if(arr[0]==8 && arr[1] == 7 && arr[2] == 6 && arr[3] == 5 && arr[4] == 4&& arr[5] == 3 && arr[6] == 2&& arr[7] == 1){
		printf("descending");
	} 

	else{
		printf("mixed");
	}


}

