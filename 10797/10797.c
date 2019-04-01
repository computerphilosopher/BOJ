#include <stdio.h>

int main(){
	int day=0;
	int cars[5];
	int sum=0;

	scanf("%d",&day);

	for(int i=0; i<5; i++){
		scanf("%d",&cars[i]);
	}

	for(int i=0; i<5; i++){
		if(cars[i]%10==day){
			sum++;
		}
	}

	printf("%d",sum);

}

