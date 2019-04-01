#include <stdio.h>

int main(){

	int row = 0;
	int col = 0;

	scanf("%d %d", &row, &col);

	char arr[row][col];

	for(int i=0; i<row; i++){
			scanf("%s", &arr[i][0]);
	}

	for(int i=0; i<row; i++){
		for(int j=col-1; j>=0; j--){
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;


}
