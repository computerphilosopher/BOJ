#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector <int> > cache;

int dp(const string &s1, const string &s2, const int i, const int j){

    if(i == -1 || j == -1){
        return 0;
    }

    int &ret = cache[i][j];

    if(ret != -1){
        return ret;
    }

    if(s1[i] == s2[j]){
        return ret = dp(s1, s2, i-1, j-1)+1;
    }
    
    return ret = max(dp(s1, s2, i-1, j), dp(s1, s2, i, j-1));

}

int main(){

    string s1, s2;
    cin >> s1 >> s2;
    
    cache = vector<vector <int> >(1001, vector<int>(1001, -1));

    cout << dp(s1, s2, s1.length()-1, s2.length()-1);

    return 0;
    
}
