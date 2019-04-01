#include <stdio.h>

typedef struct Person{
	int height;
	int weight;
	int rank;
}Person;

int main(){

	int n=0;

	scanf("%d", &n);

	Person persons[n];

	for(int i=0; i<n; i++){
		scanf("%d %d", &persons[i].height, &persons[i].weight);
	}

	for(int i=0; i<n; i++){
		persons[i].rank = 1;
		for(int j=0; j<n; j++){
			if(persons[i].height < persons[j].height &&
					persons[i].weight < persons[j].weight){
				persons[i].rank++;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		printf("%d ", persons[i].rank);
	}

	return 0;

}
