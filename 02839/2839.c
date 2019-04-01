#include <stdio.h>
#include <stdlib.h>

int main(){

	int n = 0;

	int a=0;
	int b=0;

	scanf("%d",&n);

	if(n==3){
		printf("%d",1);
	}

	else if(n%5 == 0){
		printf("%d",n/5);
	}

	else{
		a=n/5;

		while( a>=0 ){

			//printf("%d\n",a);

			if ((n-(5*a))%3 == 0){
				b= (n-(5*a))/3;

				printf("%d\n",a+b);
				return 0;
			}
			a--;
		}

		printf("%d",-1);
		return 0;

	}

}


