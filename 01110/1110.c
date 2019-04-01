#include <stdio.h>
#include <stdlib.h>

int main(){

	int input=0;
	int tmp=0;

	int sum=0;
	
	int cycle_count=0;
	int tens=0;
	int units=0;

	int tmp_units=0;

	scanf("%d",&input);

	if(input < 10){
		input=input*10;
	}
	
	tmp = input;

	do{
		units = tmp%10;
		tens = (tmp- units)/10;


		tmp_units=(tens+units)%10;


		tmp = (units*10)+tmp_units;


		sum++;

	}while(input!=tmp);

		printf("%d\n",sum);

}

