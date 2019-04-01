#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_proper(const string &s){

    int mo = 0, ja = 0;

    for(auto ch : s){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            mo++;
        }
        else{
            ja++;
        }
    }

    return mo > 0 && ja > 1;
}

void dfs(const string &s, string &picked, int here, int len){

    if(len == picked.length()){
        if(is_proper(picked)){
            cout << picked << "\n";
        }
        return;
    }

    for(int i=here+1; i<s.length(); i++){
        picked.push_back(s[i]);
        dfs(s, picked, i, len);
        picked.pop_back();
    }

    return;
}

int main(){

    int l = 0, c = 0;
    string input;

    cin.sync_with_stdio(false);

    cin >> l >> c;

    for(int i=0; i<c; i++){
        char temp = 0;
        cin >> temp;

        input += temp;
    }

    sort(input.begin(), input.end());

    string picked;

    for(int i=0; i<input.length(); i++){
        picked.push_back(input[i]);
        dfs(input, picked, i, l);
        picked.pop_back();
    }
    return 0;
}
