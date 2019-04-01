#include <stdio.h>
#include <stdlib.h>

int main(){

	int n=0;
	int x=0;
	int i=0;
	int count=0;

	int *arr=NULL;

	scanf("%d",&n);

	arr = (int*)malloc(sizeof(int)*n);

	scanf("%d",&x);

	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}

	for(i=0; i<n; i++){
		if(arr[i] < x){
			printf("%d ", arr[i]);
		}
	}
	
return 0;

}
