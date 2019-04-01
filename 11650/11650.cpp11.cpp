#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main(){

    int n = 0;
    scanf("%d", &n);

    pair<int, int> points[n];

    for(int i=0; i<n; i++){
        scanf("%d %d", &points[i].first, &points[i].second);
    }

    sort(&points[0], &points[n]);

    for(int i=0; i<n; i++){
        printf("%d %d\n",points[i].first, points[i].second);
    }
    
    return 0;
}

