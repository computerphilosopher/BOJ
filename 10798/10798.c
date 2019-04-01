#include <stdio.h>

int main(){

	char str[5][15]={0};

	for(int i=0; i<5; i++){
		gets(&str[i][0]);
	}

	for(int j=0; j<15; j++){
		for(int i=0; i<5; i++){
			char c=str[i][j];
			if(c!=' ' && c!=0){
				printf("%c", str[i][j]);
			}

		}
	}

	return 0;

}
