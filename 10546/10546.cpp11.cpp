#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> &participant, vector<string> &completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<completion.size(); i++){
            if(participant[i] != completion[i]){
                        return participant[i];
                    }
        }
    
    return participant[completion.size()];
}

int main(){

    int n = 0;

    cin.sync_with_stdio(false);
    cin >> n;

    vector<string> participant;

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        participant.push_back(temp);
    }
    
    vector<string> completion;

    for(int i=0; i<n-1; i++){
        string temp;
        cin >> temp;
        completion.push_back(temp);
    }

    cout << solution(participant, completion);

    return 0;
}
