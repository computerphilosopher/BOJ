#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

int main(){
    int r = 0; 
    scanf("%d", &r);
    printf("%.6f\n", M_PI * (r*r));
    printf("%.6f", 2.0 *(r*r));
    return 0;
}
