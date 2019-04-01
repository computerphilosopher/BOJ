#include <cstdio>
#include <utility>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

vector<vector <int> > stat;

pair<int, int> get_stat(const vector<int> &players){

    const int n = players.size() * 2;
    pair<int, int> ret;

    vector <bool> check(n, false);

    for(int i=0; i<players.size(); i++){

        check[players[i]] = true;
        
        for(int j=i+1; j<players.size(); j++){
            const int member1 = players[i];
            const int member2 = players[j];

            ret.first += stat[member1][member2];
            ret.first += stat[member2][member1];
        }
    }

    vector<int> others;

    for(int i=0; i<check.size(); i++){
        if(!check[i]){
            others.push_back(i);
        }
    }

    for(int i=0; i<others.size(); i++){
        for(int j=i+1; j<others.size(); j++){
            const int member1 = others[i];
            const int member2 = others[j];

            ret.second += stat[member1][member2];
            ret.second += stat[member2][member1];
        }
    }

    return ret;
}

int dfs(vector<int> &picked, int here, int n){


    if(picked.size() == n){
        pair<int, int> ret = get_stat(picked);
        return abs(ret.first - ret.second);
    }

    int ret = numeric_limits<int>::max();

    for(int next=here+1; next<2*n; next++){
        picked.push_back(next);
        ret = min(ret, dfs(picked, next, n));
        picked.pop_back();
    }

    return ret;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    stat.resize(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp = 0;
            scanf("%d", &temp);

            stat[i].push_back(temp);
        }
    }

    vector<int> picked;

    picked.push_back(0);

    printf("%d", dfs(picked, 0, n/2));
    
    return 0;
}
