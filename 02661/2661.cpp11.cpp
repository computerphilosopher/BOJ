#include <iostream>
#include <string>

using namespace std;

bool is_good(string picked){

    string str = picked;

    int s = str.length()-1;

    for(int len = 1; s-len >= 0; len++){
        string s1 = str.substr(s, len);
        string s2 = str.substr(s-len, len);

        if(s1 == s2){
            return false;
        }
        s--;
    }

    return true;
}

bool dfs(string picked, int n){
     
    if(picked.length() == n){
        if(picked.empty()){
            return false;
        }

        cout << picked << "\n";

        return true;
    }

    if(is_good(picked+'1')){
        if(dfs(picked+'1', n)){
            return true;
        }
    }
    
    if(is_good(picked+'2')){
        if(dfs(picked+'2', n)){
            return true;
        }

    }

    if(is_good(picked+'3')){

        if(dfs(picked+'3', n)){
            return true;
        }
    }

    return false;

}

int main(){

    int n = 0;

    cin >> n;

    dfs("", n);
}
