#include <stdio.h>
#include <stdbool.h>

int main(){

	int a = 0;
	int b = 0;
	int n = 0;

	int ball_position = 1;

	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &a);
		scanf("%d", &b);

		if(ball_position == a){
			ball_position = b;
		}
		
		else if(ball_position == b){
			ball_position = a;
		}

	}

	printf("%d", ball_position);

	return 0;
}
