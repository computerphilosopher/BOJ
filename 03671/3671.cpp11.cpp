#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<long long> check;

const int maxLen = 10000000;

bool is_prime[maxLen];

void erato(const long long n){

    is_prime[0] = false;
    is_prime[1] = false;

    for(int i=2; i<maxLen; i++){
        if(is_prime[i]){
            for(int j=2; i*j<maxLen; j++){
                is_prime[i*j] = false; 
            }
        }
    }
}


int count_prime(const string &number){

    string temp;
    int ret = 0;

    for(auto ch : number){
        temp += ch;

        const int d = stoi(temp);
        
        if(is_prime[d] && !check.count(d)){
            //cout << d << "  ";
            ret++;
            check.insert(d);
        }
    }

    return ret;
}
int solution(const string &numbers) {

    string num = numbers;

    sort(num.begin(), num.end());

    int ret = 0;

    do{
        ret += count_prime(num);
    }while(next_permutation(num.begin(), num.end()));

    return ret;
}

int main(){

    int t = 0;
    cin >> t;

    fill(&is_prime[0], &is_prime[maxLen], true);
    erato(maxLen);
    
    for(int i=0; i<t; i++){
        string num;
        cin >> num;

        check.clear();
        const int res = solution(num);

        cout << res << "\n";

    }
    return 0;
}
