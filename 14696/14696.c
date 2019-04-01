#include <stdio.h>

typedef int card;

#define STAR 4
#define CIRCLE 3
#define RECT 2
#define TRIANGLE 1


void input_card(int arr[], int n){
	
	for(int i=0; i<n; i++){

		int temp = 0;

		scanf("%d", &temp);

		switch(temp){
			case STAR:
				(arr[STAR])++;
				break;
			case CIRCLE:
				(arr[CIRCLE])++;
				break;
			case RECT:
				(arr[RECT])++;
				break;
			case TRIANGLE:
				(arr[TRIANGLE])++;
				break;
		}
	}

}

char get_winner(card a[], card b[]){

	for(int i=STAR; i>=TRIANGLE; i--){
		if(a[i] > b[i]){
			return 'A';
		}
		else if(a[i] < b[i]){
			return 'B';
		}
	}

	return 'D';
}

int main(){

	int case_count = 0;

	int a_card_count = 0;
	int b_card_count = 0;


	scanf("%d", &case_count);

	for(int i=0; i<case_count; i++){

		card a[5] = {0};
		card b[5] = {0};
		
		scanf("%d", &a_card_count);

		input_card(a, a_card_count);

		scanf("%d", &b_card_count);

		input_card(b, b_card_count);

		printf("%c\n", get_winner(a, b));
	}

	return 0;

}

