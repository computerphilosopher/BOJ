#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cache[1001][1001];


int dp(const string &s1, const string &s2, const int i, const int j){

    if(i == -1 || j == -1){
        return 0;
    }

    int &ret = cache[i][j];

    if(ret != -1){
        return ret;
    }

    if(s1[i] == s2[j]){
        return ret = dp(s1, s2, i-1, j-1) + 1;
    }

    else{
        return ret = max( dp(s1, s2, i-1, j), dp(s1, s2, i, j-1));
    }
}

string solve(const string& s1, const string& s2, const int i, const int j){

    if(i == -1 || j == -1){
        string empty;
        return empty;
    }

    if(s1[i] == s2[j]){
        return s1[i] + solve(s1, s2, i-1, j-1);
    }
    else{
        if(cache[i][j] == cache[i-1][j]){
            return solve(s1, s2, i-1, j);
        }
        else{
            return solve(s1, s2, i, j-1);
        }
    }
}


int main(){
    string s1, s2;
    cin >> s1 >> s2;

    fill(&cache[0][0], &cache[1000][1002], -1);

    cout << dp(s1, s2, s1.length()-1, s2.length()-1) << "\n";

    string solution = solve(s1, s2, s1.length()-1, s2.length()-1);

    reverse(solution.begin(), solution.end());

    cout << solution;

    return 0;
}
