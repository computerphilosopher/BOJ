#include <stdio.h>

int main(){

	int max = 0;
	int index = 0;
	
	int num = 0;

	for(int i=1; i<=9; i++){
		scanf("%d", &num);

		if(num > max){
			max = num;
			index = i;
		}
	}

	printf("%d\n%d", max, index);

}
