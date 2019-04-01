#include <stdio.h>

int get_score(int game_result[]){

	int dice_count[7] = {0};
	int num = 0;
	int same_count = 1;

	int max = 0;
	
	for(int i=1; i<=3; i++){

		dice_count[game_result[i]]++;

		if(max < game_result[i]){
			max = game_result[i];
		}

	}


	for(int i=1; i<=6; i++){

		if(dice_count[i]>1){
			same_count = dice_count[i];
			num = i;
		}
	}

	int score = 0;

	switch(same_count){
		case 3:
			score = 10000 + (1000*num);
			break;
		case 2:
			score = 1000 + (100*num);
			break;
		case 1:
			score = max * 100;
			break;

	}

	
	return score;

}

int main(){

	int n = 0;
	scanf("%d", &n);

	int score[n];

	int max = 0;

	int temp[4] = {0};

	for(int i=0; i<n; i++){
		for(int j=1; j<=3; j++){

			scanf("%d", &temp[j]);

		}
		score[i] = get_score(temp);
		if(score[i] > max){
			max = score[i];
		}
	}

	printf("%d", max);

}