#include <stdio.h>
#include <stdlib.h>

int main(){

	int n=0;
	int i=0;
	int max=0;
	
	int max_index=-1;
	double *exam_score;
	double avg=0.0;

	scanf("%d",&n);

	exam_score=(double*)malloc(sizeof(double)*n);

	for(i=0; i<n; i++){
		scanf("%lf",&exam_score[i]);
		
		if(exam_score[i] > max){
			max=exam_score[i];
			max_index=i;
		}
	}

	for(i=0; i<n; i++){
		exam_score[i] = exam_score[i]/max*100;
	}

	for(i=0; i<n; i++){
		avg += exam_score[i];
	}

	avg=avg/n;

	printf("%.2lf",avg);

}

