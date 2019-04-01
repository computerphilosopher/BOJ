#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;

bool prime[10000];
int parent[10000];

void erato(){
    
    prime[0] = false;
    prime[1] = false;
     
    for(int i=2; i<10000; i++){
         
        if(prime[i]){
            for(int j=2; i*j<10000; j++){
                prime[i*j] = false;
            }
        }
    }
}

int bfs(string start, int dest){

    queue<string> q;
    
    vector<int> dist(10000, numeric_limits<int>::max());

    int s = stoi(start);
    dist[s] = 0;
    parent[s] = s;
     
    q.push(start);

    while(!q.empty()){

        const string here = q.front();
        q.pop();

        int h = stoi(here);

        for(int i = 0; i<4; i++){

            string copy = here;

            for(int j = 1; j<=10; j++){
                 
                int temp = here[i] - '0';
                temp = (temp+j)%10;

                copy[i] = temp + '0';

                int num = stoi(copy);

                if(prime[num] && num >= 1000){
                    if(dist[num] > dist[h]+1){
                        parent[num] = h;
                        dist[num] = dist[h]+1;
                        q.push(copy);
                    }
                }
            }
        }
    }
     
    return dist[dest] == numeric_limits<int>::max() ? -1 : dist[dest];
}

int main(){

    int t = 0;
    cin.sync_with_stdio(false);
     
    cin >> t;

    fill(&prime[0], &prime[10000],true);
    erato();


    for(int tc = 0; tc<t; tc++){
         
        string start;
        int dest = 0;

        cin >> start >> dest;

        cout << bfs(start, dest) << "\n";
    }

    return 0;
}
