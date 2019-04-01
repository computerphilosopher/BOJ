#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

vector<int> solve(const vector<int> &towers){

    vector<int> ret(towers.size(), 0);
    priority_queue<pair<int, int>, vector<pair <int, int> >, greater<pair<int, int> > > pq;

    const int start = ret.size()-1;

    pq.push(make_pair(towers[start], start));

    for(int i = start-1; i>=0; i--){

        while(!pq.empty()){
            const pair<int, int> toh = pq.top();

            if(toh.first <= towers[i]){
                ret[toh.second] = i+1;
                pq.pop();
            }
            else{
                break;
            }
        }
        pq.push(make_pair(towers[i], i));
    }

    return ret;
}

int main(){
    int n = 0;
    vector<int> towers;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int temp = 0;
        scanf("%d", &temp);

        towers.push_back(temp);
    }

    vector<int> solution = solve(towers);

    for(auto s: solution){
        printf("%d ", s);
    }

    return 0;
}

