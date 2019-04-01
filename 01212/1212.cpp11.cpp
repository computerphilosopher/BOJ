#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const string otob(const string octal){
     
    string binary;

    const int len = octal.length();
     
    for(int i = 0; i<len; i++){
         
        int temp = octal[i] - '0';
        string cur;

        for(int i=0; i<3; i++){
            cur += (temp % 2) + '0';
            temp /= 2;
        }
         
        reverse(cur.begin(), cur.end());

        binary += cur;
    }

    return binary;
}

int main(){

    string octal;
    cin >> octal;

    string binary = otob(octal);

    bool started = false;
     
    for(int i=0; i<binary.length(); i++){
        if(!started){
            if(binary[i] == '0'){
                continue;
            }
            else{
                started = true;
            }
        }
        cout << binary[i];
    }

    if(!started){
        cout << "0";
    }

    return 0;
}

