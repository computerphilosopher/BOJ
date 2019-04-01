#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000;

vector<int> cache(5001, -1);

bool can_decode(const string &code, const int i, const int j){
    if(0 > i || j > code.length()-1){
        return false;
    }
    if(code[i] == '0'){
        return false;
    }
    const int decode = stoi(code.substr(i, j-i+1));
    return 1 <= decode && decode <= 26;
}

long long solve(const string &code, const int i){

    if(i >= code.length()){
        return 1;
    }
    if(i == code.length()-1){
        return can_decode(code, i, i);
    }

    int &ret = cache[i];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    if(can_decode(code, i, i)){
        ret += solve(code, i+1) % mod; 
    }
    
    if(can_decode(code, i, i+1)){
        ret += solve(code, i+2) % mod; 
    }

    return ret % mod;
}

int main(){
    string code;
    cin >> code;
    
    cout << solve(code, 0);

    return 0;
}
 
