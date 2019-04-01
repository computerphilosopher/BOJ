#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> &clothes) {
    int answer = 0;
    
    map<string, int> hash;
    
    for(auto v : clothes){
            hash[v[1]] += 1;
        }
    
    answer = 1;
    
    for(auto m : hash){
            answer *= (m.second+1);
        }
    
        answer--;
    
    return answer;
}

int main(){
    int t = 0;

    cin.sync_with_stdio(false);
    cin >> t;


    for(int tc = 0; tc<t; tc++){
        int n = 0;
        cin >> n;

        vector<vector <string> > clothes(n);

        for(int i=0; i<n; i++){
            string cloth;
            string category;

            cin >> cloth >> category;

            clothes[i].push_back(cloth);
            clothes[i].push_back(category);
        }

        const int s = solution(clothes);

        cout << s << "\n";
    }

    return 0;
}
