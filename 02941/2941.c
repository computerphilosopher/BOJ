#include <stdio.h>
#include <string.h>

int main(){
    char str[1001];
    scanf("%s", str);

    int i=0;
    int ans = 0;

    int len = strlen(str);

    while(str[i] != '\0'){
        
        if(str[i+1] == '\0'){
            ans++;
            break;
        }

        switch(str[i]){
            case 'c':
                if(str[i+1] == '=' || str[i+1] == '-'){
                    ans++;
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
                break;

            case 'd':
                if(i+2 <len && str[i+1] == 'z' && str[i+2] == '=') {
                    ans++;
                    i += 3;
                }
                else if(str[i+1] == '-'){
                    ans++;
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
                break;

            case 'l':
                if(str[i+1] == 'j'){
                    ans++;
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
                break;

            case 'n':
                if(str[i+1] == 'j'){
                    ans++;
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
                break;
            case 's':
                if(str[i+1] == '='){
                    ans++;
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
                break;
            case 'z':
                if(str[i+1] == '='){
                    ans++;
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
                break;
            default:
                ans++;
                i++;
                break;
        }
    }

    printf("%d", ans);

    return 0;
}
