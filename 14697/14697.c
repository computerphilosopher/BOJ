#include <stdio.h>
#include <stdbool.h>

bool is_possible(int r, int a, int b, int c){

	int n = 300; 

	for(int x=0; x<n; x++){
		for(int y=0; y<n; y++){
			for(int z=0; z<n; z++){
				if(r == (x*a) + (y*b) + (c*z)){
					return true;
				}
			}
		}
	}

	return false;
}


int main(){

	int a = 0;
	int b = 0;
	int c = 0;

	int rooms = 0;

	scanf("%d %d %d %d", &a, &b, &c, &rooms);

	printf("%d", is_possible(rooms, a, b, c));

}
