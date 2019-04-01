#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp (const string &s1, const string &s2){

    auto len1 = s1.length();
    auto len2 = s2.length();

    if(len1 < len2){
        return true;
    }
    else if(len1 == len2){
        return s1 < s2;
    }
    else{
        return false;
    }
}
int main(){
    auto n = 0;
    cin.sync_with_stdio(false);
    cin >> n;

    vector<string> v;

    for(auto i=0; i<n; i++){
        string temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);

    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto str : v){
        cout << str << "\n";
    }
    return 0;
}

