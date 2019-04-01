#include <stdio.h>
#include <string.h>

int main(){

	char string[1000000];

	memset(string, -1, sizeof(string));

	gets(string);

	char c = -1;

	int count = 0;
	int i = 0;

	while(c != '\0'){

		c = string[i++];

		if(c == ' ' && string[i] != '\0'){
			count++;
		}
	}

	if(string[0] == ' '){
		count--;
	}

	printf("%d", ++count);
}