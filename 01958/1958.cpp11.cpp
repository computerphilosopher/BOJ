#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2, s3;

int cache[101][101][101];

int lcs(int i, int j, int k){

    if(i == -1 || j == -1 || k == -1){
        return 0;
    }

    int &ret = cache[i][j][k];

    if(ret != -1){
        return ret;
    }

    if(s1[i] == s2[j] && s2[j] == s3[k]){
        return ret = lcs(i-1, j-1, k-1)+1;
    }
     
    return ret = max(max(lcs(i-1, j, k), lcs(i, j-1, k)), lcs(i, j, k-1));
}

int main(){
    cin >> s1 >> s2 >> s3;

    fill(&cache[0][0][0], &cache[100][100][101], -1);

    cout << lcs(s1.length()-1, s2.length()-1, s3.length()-1);

    return 0;
}
