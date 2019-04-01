#include <cstdio> 
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main(){


    int n = 0;
    scanf("%d", &n);

    stack<int> s;
    queue<int> q;

    string answer;

    for(int i=1; i<=n; i++){
        q.push(i);
    }

    s.push(0);

    bool is_legal= true;

    for(int i=1; i<=n; i++){

        int k = 0;
        scanf("%d", &k);

        if(k > s.top()){

            if(q.empty()){
                is_legal = false;
                break;
            }

            while(s.top() < k){

                s.push(q.front());
                q.pop();
                answer.append("+");
            }

            answer.append("-");
            s.pop();
        }

        else{

            if(s.empty()){
                is_legal = false;
            }
            while(s.top() >= k){
                s.pop();
                answer.append("-");
            }
        }

    }

    if(is_legal){
        for(int i=0; i<answer.length(); i++){
            printf("%c\n", answer[i]);
        }
    }
    else{
        printf("NO");
    }

}
