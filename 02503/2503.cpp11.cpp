#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool is_proper(const int num){

    if(num < 100){
        return false;
    }
    int n = num;
    bool checked[10] = {false};

    while(n){
        const int digit = n%10;
        if(checked[digit]){
            return false;
        }

        else if(digit == 0){
            return false;
        }
        else{
            checked[digit] = true;
        }
        n /= 10;
    }
    return true;
}

pair<int, int> judge(const int origin, const int guess){

    int o = origin;
    int g = guess;

    int check[10] = {0};
    queue<int> oq;

    while(o){
        const int digit = o % 10;
        oq.push(digit);
        check[digit]++;

        o /= 10;
    }

    int strike = 0,  ball = 0;

    while(g){

        const int o_digit = oq.front();
        oq.pop();

        const int digit = g %10;

        if(o_digit == digit){
            strike++;
        }
        else if(check[digit]){
            ball++;
        }

        g /= 10;
    }

    return make_pair(strike, ball);
}

int solution(const vector<vector<int>> &baseball) {

    int answer = 0;

    for(int num=100; num<1000; num++){
        if(is_proper(num)){
            bool is_ok = true;

            for(int i = 0; i<baseball.size(); i++){
                pair<int, int> temp = judge(num, baseball[i][0]);
                if(temp.first != baseball[i][1] || temp.second != baseball[i][2]){
                    is_ok = false;
                }
            }

            if(is_ok){
                answer++;
            }
        }
    }
    return answer;
}

int main(){

    int n = 0;
    scanf("%d", &n);

    vector< vector<int> > baseball(n);

    for(int i=0; i<n; i++){
    
        int num = 0;
        scanf("%d", &num);
        
        baseball[i].push_back(num);

        int strikes = 0;
        scanf("%d", &strikes);
        
        baseball[i].push_back(strikes);
        
        int ball = 0;
        scanf("%d", &ball);
        
        baseball[i].push_back(ball);
    }

    printf("%d", solution(baseball));

    return 0;
}
