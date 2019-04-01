#include <stdio.h>

int main(){

	int burger[3] = {0};
	int drink[2] = {0};
	
	int burger_min=9999;
	
	for(int i=0; i<3; i++){
		
		scanf("%d", &burger[i]);
		
		if(burger[i] < burger_min){
			burger_min = burger[i];
		}
	}

	int drink_min = 9999;
	
	for(int i=0; i<2; i++){
		scanf("%d", &drink[i]);
		if(drink[i] < drink_min){
			drink_min = drink[i];
		}

	}

	printf("%d", burger_min + drink_min-50);
	
	return 0;

}
