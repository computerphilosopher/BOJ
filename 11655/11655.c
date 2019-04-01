#include <stdio.h>
#include <ctype.h>

int main(){
    char str[100];
    
    gets(str);

    int i = 0;

    while(str[i] != '\0'){
        if(isalpha(str[i])){
            if(str[i] >= 'n' || (str[i] >='N' && str[i] <= 'Z')){
                str[i] -= 13;
            }
            else{
                str[i] += 13;
            }

            
        }
        i++;
    }

    printf("%s", str);

}
