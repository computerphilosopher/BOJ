#include <stdio.h>
 
#include <string.h>
#include <stdbool.h>

bool set[21];

int main(){

    int n = 0;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char cmd[100];

        scanf("%s", cmd);

        if(!strcmp(cmd, "add")){
            int x = 0;
            scanf("%d", &x);

            set[x] = true;
        }
         
        if(!strcmp(cmd, "remove")){
            int x = 0;
            scanf("%d", &x);

            set[x] = false;
        }
         
        if(!strcmp(cmd, "check")){
            int x = 0;
            scanf("%d", &x);

            printf("%d\n", set[x]);
        }
        
        if(!strcmp(cmd, "toggle")){
            int x = 0;
            scanf("%d", &x);

            set[x] = set[x] ? false : true;
        }
        
        if(!strcmp(cmd, "all")){
            memset(set, true, sizeof(set));
        }
        
        if(!strcmp(cmd, "empty")){
            memset(set, false, sizeof(set));
        }

    }

    return 0;
}

