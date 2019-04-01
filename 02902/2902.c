#include <stdio.h>

int main(){

	char input[100] = {0};

	char solution[100] = {0};

	scanf("%s", input);

	int i = 0;
	int j = 0;

	while(input[i] != '\0'){
		if (input[i] >= 'A' && input[i] <= 'Z'){
			solution[j++] = input[i];
		}
		i++;
	}

	solution[j] = '\0';

	printf("%s", solution);

	return 0;
}
