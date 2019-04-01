#include <stdio.h>

int main(){

	int num={0};
	int sum = 0;
	int min = 101 ;

	for(int i=0; i<7; i++){
		scanf("%d", &num);

		if(num%2 != 0){
			sum += num;
			if(num < min){
				min = num;
			}
		}
	}

	if(sum == 0){
		printf("-1");
	}

	else{
		printf("%d\n%d", sum, min);
	}
	return 0;
}
