#include <cstdio>
 
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n = 0;

    scanf("%d", &n);

    vector <int> perm;

    for(int i=0; i<n; i++){
        perm.push_back(i+1);
    }

    do{
        for(int i=0; i<n; i++){
            printf("%d ", perm[i]);
        }

        printf("\n");
         
    }while(next_permutation(perm.begin(), perm.end()));

    return 0;

}

