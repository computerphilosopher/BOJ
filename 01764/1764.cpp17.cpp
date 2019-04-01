#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> intersection(set<T> s1, set<T> s2){

    vector<T> ret;
    for(auto element : s1){
        if(s2.count(element)){
            ret.push_back(element);
        }
    }

    sort(ret.begin(), ret.end());
    return ret;
}


int main(){

    int n = 0, m = 0;

    cin >> n >> m;

    set<string> noHear;

    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        noHear.insert(name);
    }

    set<string> noSee;

    for (int j = 0; j < m; j++) {
        string name;
        cin >> name;
        noSee.insert(name);
    }

    auto answer = intersection<string>(noHear, noSee);

    cout << answer.size() << "\n";

    for(auto name : answer){
        cout << name << "\n";
    }
    
    return 0;
}
