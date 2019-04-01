#include <stdio.h>

int main(){

	int peoples = 0;
	int get_in = 0;
	int get_out = 0;

	int max=0;

	for(int i=0; i<4; i++){
		scanf("%d %d", &get_out, &get_in);

		peoples -= get_out;
		peoples += get_in;

		if(peoples > max){
			max = peoples;
		}
	}

	printf("%d", max);

	return 0;

}
