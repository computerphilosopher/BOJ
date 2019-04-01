#include <stdio.h>

int main(){

	int n = 0;
	int r = 0;

	int l= -1;
	int p = -1;
	int v = -1;

	int answer[10001]={0};

	int i = 1;

	while(1){
		
		scanf("%d %d %d", &l, &p, &v);

		if(l == 0 && p == 0 && v == 0){
			break;
		}

		n = v/p;
		r = v%p;

		if(r > l){
			r=l;
		}

		answer[i] = (n*l) + r; 
		i++;

	}

	i = 1;

	while(answer[i] != 0){
		
		printf("Case %d: %d",i,answer[i]);
		
		if(answer[i+1] != 0){
			printf("\n");
		}
		
		i++;
	}

	return 0;

}
