#include <stdio.h>

double get_avg(double arr[], int size){

	double avg = 0.0;

	double sum = 0;

	for(int i = 0; i<size; i++){
		sum += arr[i];
	}
	
	avg = sum/size;
	return avg;
}

double over_avg(double avg, double arr[], int size){

	double sum = 0;

	for(int i=0; i<size; i++){
		if(arr[i] > avg){
			sum++;
		}
	}

	return (sum/size)*100;
}

int main(){

	int c = 0;

	scanf("%d", &c);

	double answer[c];

	for(int i=0; i<c; i++){
		int n = 0;
		scanf("%d", &n);

		double arr[n];

		for(int j=0; j<n; j++){

			scanf("%lf", &arr[j]);

		}

		answer[i] = over_avg(get_avg(arr,n), arr, n);

	}

	for(int i=0; i<c-1; i++){
		printf("%.3lf%\n", answer[i]);
	}

	printf("%.3lf%\n", answer[c-1]);
	return 0;

}


