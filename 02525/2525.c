#include <stdio.h>

typedef struct TimeType{
	int hour;
	int minute;
}TimeType;

void add_time(TimeType *time, int spend_minute){

	int m = time->minute + spend_minute;

	while(m >= 60){
		m -= 60;
		time->hour = (time->hour+1)%24;
	}

	time->minute = m;
}

int main(){


	TimeType time;
	int spend_minute;

	scanf("%d", &time.hour);
	scanf("%d", &time.minute);
	scanf("%d", &spend_minute);

	add_time(&time, spend_minute);

	printf("%d %d", time.hour, time.minute);

}

