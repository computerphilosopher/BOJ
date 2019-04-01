#include <stdio.h>

void print_star(int n, int depth){

	if(depth > n){
		return;
	}


	for(int i=0; i<n-depth; i++){
		printf(" ");
	}
	
	for(int i=0; i<depth; i++){
		printf("*");
	}

	if(n-depth > 0){
		printf("\n");
	}

	print_star(n, depth+1);
}

void print_star2(int n, int depth){

	if(depth > n){
		return;
	}
	
	for(int i=0; i<depth; i++){
		printf(" ");
	}
	
	for(int i=0; i<n-depth+1; i++){
		printf("*");
	}
	if(n-depth > 0){
		printf("\n");
	}

	print_star2(n, depth+1);


}

int main(){

	int n = 0;
	scanf("%d", &n);

	print_star(n,1);

	printf("\n");
	print_star2(n-1, 1);

}
