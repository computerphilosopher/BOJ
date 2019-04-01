#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){


	const string DayOfWeek[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};
	const int DayOfMonth[13] = 
	{ 0, 31, 28, 31, 30,
		31, 30, 31, 31, 
		30, 31, 30, 31
	};


	int month=0;
	int day=0;
	int sum=0;

	scanf("%d",&month);
	scanf("%d",&day);

	for(int i=0; i<month; i++){
		sum+=DayOfMonth[i];
	}

	sum+=(day-1);

	cout << DayOfWeek[sum%7] <<"\n";

}


