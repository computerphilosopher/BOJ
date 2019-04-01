#include <stdio.h>
#include <stdlib.h>

int main(){

    int t = 0;
    scanf("%d", &t);

    for(int tc=0; tc<t; tc++){
        int n = 0;
        scanf("%d", &n);

        int D[n+1][2];

        D[0][0] = 1;
        D[0][1] = 0;

        D[1][0] = 0;
        D[1][1] = 1;

        for(int i=2; i<=n; i++){

            D[i][0] = D[i-1][0] + D[i-2][0];
            D[i][1] = D[i-1][1] + D[i-2][1];
        }

        printf("%d %d\n", D[n][0], D[n][1]);
    }

    return 0;
}
