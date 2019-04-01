#include <stdio.h>

int get_parent_money(int k, int n, int m){
	int y = (k*n)-m;

	if(y<0){
		return 0;
	}
	else{
		return y;
	}
}

int main(){
	
	int k=0;
	int n=0;
	int m=0;
	
	scanf("%d", &k);
	scanf("%d", &n);
	scanf("%d", &m);

	printf("%d", get_parent_money(k,n,m));
}


