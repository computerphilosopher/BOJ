#include <stdio.h>

int main(){

	int score;
	int sum=0;

	for(int i=0; i<5; i++){
		scanf("%d", &score);
		
		if(score < 40){
			score = 40;
		}
		sum+=score;
	}

	printf("%d", sum/5);


}
