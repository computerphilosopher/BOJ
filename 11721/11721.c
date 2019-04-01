#include <stdio.h>

int main(){

	char str[100] = {0};

	scanf("%s", str);

	int i = 0;

	int j = 0;

	while(str[i] != '\0'){
		
		j++;
		printf("%c", str[i]);

		if(j>=10){
			printf("\n");
			j = 0;
		}
		i++;
	}
	return 0;
}