#include <string>
#include <cstdio>
#include <utility>

using namespace std;

pair<int, int> solution(int brown, int red) {

    pair<int, int> ret;
    const int w_plus_h = (brown/2)+2;
    const int wh = red + brown;

    for(int i = 1; i<=5000; i++){
        for(int j = i; j<=5000; j++){
            if(i + j == w_plus_h && i*j == wh){
                ret.first = j;
                ret.second = i;
            }
        }
    }

    return ret;
}

int main(){

    int r = 0, b = 0;

    scanf("%d %d", &r, &b);
    
    const pair<int, int> res = solution(r, b); 

    printf("%d %d", res.first, res.second);

    return 0;
}
