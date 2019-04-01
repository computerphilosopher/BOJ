#include <stdio.h>
#include <stdlib.h>

int main(){

	int n = 0;
	int sum = 0;
	char str[1000] = {0};

	scanf("%d", &n);
	scanf("%s", str);

	for(int i=0; i<n; i++){
		char c = str[i];
		sum += c -'0';
	}

	printf("%d", sum);
}
