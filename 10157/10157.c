
#include <stdio.h>

typedef struct Seat {
	int x, y, num;
}Seat;

Seat func(Seat start, int row, int col, int k){

	Seat seat = {start.x, start.y, start.num};

	int limit = 2*(row + col)-4;
	limit += start.num-1;

	if(k==seat.num){
		return seat;
	}
	
	else if(k > limit){

		seat.x++;
		seat.y++;
		seat.num = limit+1;

		return func(seat, row-2, col-2, k);

	}

	else{

		for(int i=1; i<row; i++){
			seat.y++;
			seat.num++;
			if(k == seat.num){
				return seat;
			}
		}
		for(int i=1; i<col; i++){
			seat.x++;
			seat.num++;
			if(k == seat.num){
				return seat;
			}
		}

		for(int i=1; i<row; i++){
			seat.y--;
			seat.num++;
			if(k == seat.num){
				return seat;
			}
		}

		for(int i=1; i<col; i++){
			seat.x--;
			seat.num++;
			if(k == seat.num){
				return seat;
			}
		}

	}

}


int main(){

	Seat start = {1,1,1};
	int row =0;
	int col=0;
	int k=0;

	scanf("%d %d", &col, &row);

	scanf("%d", &k);

	if(k> row * col){
		printf("0");
		return 0;
	}

	Seat result = func(start, row, col, k);

	if(result.x == -1 && result.y == -1){
		printf("0");
		return 0;
	}

	printf("%d %d", result.x, result.y);

}
