#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int greedy(vector<pair<int, int> >& meeting){
    
    sort(meeting.begin(), meeting.end());

    int next_start= 0;

    int ret = 0;

    for(auto meet : meeting){
        int meetinBegin = meet.second;
        int meetingEnd = meet.first;

        if(meetinBegin >= next_start){
            next_start = meetingEnd;
            ret++;
        }
    }
    return ret;
}

int main(){

    int n = 0;
    scanf("%d", &n);

    vector<pair<int, int> > meeting;
     
    for(int i=0; i<n; i++){
        int s = 0, e = 0;
        scanf("%d %d", &s, &e);

        meeting.push_back(make_pair(e, s));
    }

    printf("%d", greedy(meeting));

    return 0;
}
