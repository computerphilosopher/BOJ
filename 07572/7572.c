#include <stdio.h>

#define TENGAN 10
#define TWELVEZI 12

int main(){

    int year = 0;
    scanf("%d", &year);

    int gan[10] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
    char zi[12] = {'I', 'J', 'K', 'L', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    printf("%c%d", zi[year%TWELVEZI], gan[year%TENGAN]);

    return 0;
}
