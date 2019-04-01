#include <stdio.h>

void init(int card[]){
	for(int i=1; i<=20; i++){
		card[i]=i;
	}

	return;
}

void reverse(int a, int b, int card[]){

	int temp[b-a];

	for(int i=0; i<=b-a; i++){
		temp[i] = card[b-i];
	}
	
	for(int i=0; i<=b-a; i++){
		card[a+i] = temp[i];
	}

	
return;
}

int main(){

	int card[21];

	init(card);

	int a=0;
	int b=0;

	for(int i=0; i<10; i++){
		scanf("%d %d", &a, &b);
		reverse(a, b, card);
	}


	for(int i=1; i<=20; i++){
		printf("%d ", card[i]);
	}
	return 0;
	
}
