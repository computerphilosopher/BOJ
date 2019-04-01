#include <stdio.h>

void print_star(int n, int depth){

	if(n < depth){
		return;
	}
	
	int star = 2*depth-1;
	int white_space = ((2*n-1)-star)/2;

	for(int i=0; i<white_space; i++){
		printf(" ");
	}
	
	for(int i=0; i<star; i++){
		printf("*");
	}
	

	if(n-depth >= 1){
		printf("\n");
	}

	print_star(n, depth+1);
}

int main(){
	int n=0;
	scanf("%d", &n);

	print_star(n, 1);
}
