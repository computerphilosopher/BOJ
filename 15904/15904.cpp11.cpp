#include <iostream>
#include <string>

using namespace std;

bool solve(string input){

    string match =  "UCPC";

    int j = 0;

    for(int i=0; i<input.size(); i++){
        if(input[i] == match[j] && j <= 3){
            j++;
        }
    }

    return j > 3;
}
int main(){

    string str;
    getline(cin, str);

    if(solve(str)){
        cout << "I love UCPC";
    }
    else{
        cout << "I hate UCPC";
    }

}
