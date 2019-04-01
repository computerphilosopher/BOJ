#include <stdio.h>
#include <stdbool.h>

bool func(int num, int tri_num[]){

	for(int i=1; i<100; i++){
		if(tri_num[i]> num){
			break;
		}

		for(int j=1; j<100; j++){

			if(tri_num[i]+tri_num[j]> num) {
				break;
			}

			for(int k=1; k<100; k++){
				if(tri_num[i]+tri_num[j]+tri_num[k]> num) {
					break;
				}

				if(tri_num[i]+tri_num[j]+tri_num[k] == num){
					return true;
				}
			}
		}
	}

	return false;
}

int main(){

	int tri_num[100] = {0};

	for(int i=1; i<100; i++){
		tri_num[i] = i*(i+1)/2;
	}

	int n = 0;
	scanf("%d", &n);

	int arr[n];

	int temp = 0;
	
	for(int i=0; i<n; i++){
		scanf("%d", &temp);
		arr[i] = func(temp, tri_num);
	}
	
	for(int i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}

	return 0;

}
