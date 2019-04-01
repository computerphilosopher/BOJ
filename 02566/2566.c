#include <stdio.h>

int main(){

	int max = 0;
	int row = 0;
	int col = 0;

	int tmp = 0;

	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			scanf("%d", &tmp);
			
			if(tmp > max){
				max = tmp;
				row = i;
				col = j;
			}
		}
	}

	printf("%d\n", max);
	printf("%d %d", row, col);

	return 0;
}

