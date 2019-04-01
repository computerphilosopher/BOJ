#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char str[]){

	char reverse[20]={0};

	char length = strlen(str);

	for(int i=0; i<length; i++){
		reverse[i] = str[length-1-i];
	}

	if(strcmp(str, reverse) == 0){
		return true;
	}
	else{
		return false;
	}

}
int main(){

	char str[20] = {0};
	scanf("%s", str);

	if(is_palindrome(str)){
		printf("true");
	}

	else{
		printf("false");
	}

}



