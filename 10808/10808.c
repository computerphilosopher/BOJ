#include <stdio.h>
#include <string.h>

#define ALPHABET_COUNT 26

int main(){

	char str[100] = {0};
	int alphabet[ALPHABET_COUNT] = {0};
	
	scanf("%s", str);

	for(int i=0; i<strlen(str); i++){
		char c= str[i];
		alphabet[c-'a']++;
	}

	for(int i=0; i<ALPHABET_COUNT; i++){
		printf("%d ", alphabet[i]);
	}
	return 0;

}
