#include <stdio.h>

void print_repeat(char str[], int r){

	int i = 0;

	while(str[i] != '\0'){
		for(int j=0; j<r; j++){
			printf("%c", str[i]);
		}
		i++;
	}
}

int main(){

	int t = 0;
	int r = 0;

	char s[20] = {0};

	scanf("%d", &t);
	
	for(int i=0; i<t; i++){

		scanf("%d", &r);
		scanf("%s", s);

		print_repeat(s, r);

		printf("\n");

	}

	return 0;
}
