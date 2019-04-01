#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;
string inequals;

pair<long long, long long> solution(0, 9999999999);

bool proper_with_inequal(const char inequal, const int first, const int second){

    if(inequal == '<'){
        return first < second;
    }
    if(inequal == '>'){
        return first > second;
    }
}

bool is_legal_sequence(const string &seq){

    for(int i=0; i<inequals.size(); i++){
        if(!proper_with_inequal(inequals[i], seq[i]-'0', seq[i+1]-'0')){
            return false;
        }
    }

    return true;
}

vector<bool> visited(10, false);
int start;

void dfs(const int k, const string &seq, string &picked, const int here){

    visited[here] = true;
     
    if(start == here){
        picked.push_back(seq[start]);
    }

    if(picked.length() == k){

        if(is_legal_sequence(picked)){
            long long num = stoll(picked);
            solution.first = max(solution.first, num);
            solution.second = min(solution.second, num);
        }

        return;
    }

    for(int i = 0; i<seq.length(); i++){

        if( !visited[i] && i != here){
            picked.push_back(seq[i]);

            visited[start] = true;
             
            dfs(k, seq, picked, i);

            picked.pop_back();

            visited[i] = false;
        }
    }

}

int main(){
    int k = 0;
    cin >> k;

    for(int i=0; i<k; i++){
        char temp;
        cin >> temp;
        inequals.push_back(temp);
    }

    const string seq = "0123456789";

    for(int i=0; i<10; i++){
        string picked;
        start = i;
        dfs(k+1, seq, picked, i);
        visited = vector<bool>(10, false);
    }
     

    cout << setw(k+1) << setfill('0') <<  solution.first <<"\n"; 
    cout << setw(k+1) << setfill('0') <<  solution.second; 

    return 0;
}

