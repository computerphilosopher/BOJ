#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Document{
    public:
    int order, prio;

    Document(int order, int prio){
        this->order = order;
        this->prio = prio;
    }

    bool operator < (const Document &op) const {
       return (this->prio < op.prio);
    }

};

int main(){

    int c = 0;
    scanf("%d", &c);

    for(int t=0; t<c; t++){

        int n = 0;
        int order = 0;

        scanf("%d %d", &n, &order);

        queue <Document> q;
        priority_queue<int> pq;

        for(int i=0; i<n; i++){
            int p = 0;

            scanf("%d", &p);

            Document d(i, p);

            q.push(d);
            pq.push(p);

        }

        int i = 1;

        while(!q.empty()){

            Document d = q.front();
            int top = pq.top();

            q.pop();


            if(d.prio < top){
                q.push(d);
            }

            else if(order == d.order){
                printf("%d\n", i);
                break;
            }

            else{
                pq.pop();
                ++i;
            }

        }
    }

    return 0;
}

