#include <stdio.h>
#include <stdbool.h>

#define MALE 1
#define FEMALE 2

void print_switch(bool switches[], int length){

	for(int i=1; i<=length; i++){
		printf("%d ", switches[i]);
		
		if(i % 20 == 0){
			printf("\n");
		}
	}

	return;
}

void press_switch(bool *s){
	if(*s){
		*s = false;
	}
	else{
		*s = true;
	}
}

void female(bool switches[], int s, int length){

	int i=0;
	int j=0;

	while(switches[s-i] == switches[s+j] && s-i >= 1 && s+j <= length){

		
		press_switch(&switches[s-i]);
		
		if(i != 0){
			press_switch(&switches[s+j]);
		}

		i++;
		j++;
	}

	return; 
}

void male(bool switches[], int s, int length){

	int x = 1;

	int j = s;


	for(int i=s; i<=length; i=s*x){

		press_switch(&switches[i]);
		x++;

	}

	return;

}


int main(){


	int switch_count = 0; 

	scanf("%d", &switch_count);

	bool switches[switch_count+1];

	for(int i=1; i<=switch_count; i++){

		scanf("%d", &switches[i]);
	}

	int student_count = 0;

	scanf("%d", &student_count);


	for(int i=0; i<student_count; i++){

		int gender = 0;
		int num = 0;

		scanf("%d %d", &gender, &num);

		if(gender == MALE){
			male(switches, num, switch_count);
		}
		else{
			female(switches, num, switch_count);
		}

	}


	print_switch(switches, switch_count);

	return 0;
}
