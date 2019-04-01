#include <stdio.h>

int main(){

	int count[100] = {0};
	int sum = 0;

	int input[11] ={0};

	for(int i=1; i<=10; i++){

		scanf("%d", &input[i]);

	}
	
	for(int i=1; i<=10; i++){

		sum += input[i];

		count[input[i]/10]++;

	}
	
	int max = 0;
	for(int i=1; i<100; i++){

		if(count[i] > max){
			max = i;
		}

	}

	printf("%d\n%d", sum/10, max*10 );

}
