#include <stdio.h>

int main(){

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int n = a*b*c;

	int answer[10] = {0};
	int temp = 0;
	
	while(n > 0){
		
		temp = n % 10;
		answer[temp]++;  
		n /= 10;
	}

	for(int i=0; i<10; i++){
		printf("%d\n", answer[i]);
	}

	return 0;
}
