#include <stdio.h>
#include <string.h>

int func(char plate[]){
	
	char base = plate[0];
	int size = strlen(plate);
	int count=10;

	for(int i=1; i<size; i++){
		if(plate[i] == base){
			count+=5;
		}
		else{
			count += 10;
			base = plate[i];
		}
	}

	return count;

}

int main(){

	char plate[50];
	scanf("%s", plate);

	printf("%d",func(plate));

}
