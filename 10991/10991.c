#include <stdio.h>

void print_star(int n, int depth){

	if(n < depth){
		return;
	}

	for(int i=0; i<n-depth; i++){
		printf(" ");
	}
	
	for(int i=0; i<depth; i++){
		printf("* ");
	}

	if(n != depth){
		printf("\n");
	}

	print_star(n, depth+1);
}

int main(){

	int n=0;
	scanf("%d", &n);

	print_star(n, 1);

}
