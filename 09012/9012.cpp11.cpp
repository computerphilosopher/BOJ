#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_vps(string ps){

    stack<char> s;
    
    for(int i=0; i<ps.length(); i++){

        char c = ps[i]; 

        if(c == '('){
            s.push(c);
        }

        else if(c == ')'){

            if(s.empty()){
                return false;
            }

            char prev = s.top(); 

            if(prev != '('){
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}

int main(){

    int n = 0;

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin >> n;

    for(int i=0; i<n; i++){

        string ps;
        cin >> ps;
         
        if(is_vps(ps)){
            cout << "YES" << "\n";
        } 
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;

}
