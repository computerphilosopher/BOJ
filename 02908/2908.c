#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char num[]){

	char temp = num[0];

	num[0] = num[2];
	num[2] = temp;
}

int main(){

	char a[4] = {0};
	char b[4] = {0};

	scanf("%s", a);
	scanf("%s", b);

	reverse(a);
	reverse(b);

	int x = atoi(a);
	int y = atoi(b);

	if(x>=y){
		printf("%d", x);
	}
	else{
		printf("%d", y);
	}

	return 0;

}
