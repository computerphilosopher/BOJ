#include <stdio.h>

int main(){

	int ACard[10]={0};
	int BCard[10]={0};

	int APoint=0;
	int BPoint=0;

	for(int i=0; i<10; i++){
		scanf("%d",&ACard[i]);
	}
	
	for(int i=0; i<10; i++){
		
		scanf("%d",&BCard[i]);
		
		if(BCard[i] > ACard[i]){
			BPoint++;
		}
		else if(BCard[i] < ACard[i]){
			APoint++;
		}
	}

	if(APoint > BPoint){
		printf("A");
	}
	else if(APoint < BPoint){
		printf("B");
	}
	else{

		printf("D");
	}

	return 0;


}

