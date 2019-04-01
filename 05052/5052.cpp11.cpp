#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool scmp(const string &s1, const string &s2){
    return s1.length() < s2.length();
}


bool solution(vector<string> &phone_book) {

    set <string> hash;

    sort(phone_book.begin(), phone_book.end(), scmp);

    for(auto number : phone_book){

        string temp;

        for(auto ch : number){

            temp += ch;

            if(hash.count(temp)){
                return false;
            }
        }
        hash.insert(number);
    }

    return true;
}

int main(){
    int t = 0;
    cin.sync_with_stdio(false);
    cin >> t;

    for(int test=0; test<t; test++){
        int n = 0;
        cin >> n;

        vector <string> phone_book;

        for(int i=0; i<n; i++){
            string temp;
            cin >> temp;

            phone_book.push_back(temp);
        }

        if(solution(phone_book)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;
}
