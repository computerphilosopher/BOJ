#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector <int> > board;

int check_all(int left, int right, int top, int bot){
     
    int sum = 0;

    for(int i=top; i<=bot; i++){
        for(int j=left; j<=right; j++){
            sum += board[i][j];
        }
    }


    if(!sum){
        return 0;
    }
    else if(sum == (right-left+1)*(bot-top+1)){
        return 1;
    }
    else{
        return -1;
    }
}

string solve(int left, int right,int top, int bot){

    int check = check_all(left, right, top, bot);


    if(!check){
        return "0";
    }

    if(check == 1){
        return "1";
    }

    string ret = "(";

    int x_mid = (left+right)/2;
    int y_mid = (top+bot)/2;

    ret += solve(left, x_mid, top, y_mid);
    ret += solve(x_mid+1, right, top, y_mid);

    ret += solve(left, x_mid, y_mid+1, bot);
    ret += solve(x_mid+1, right, y_mid+1, bot);

    ret += ")";

    return ret;

}

int main(){

    int n = 0;
    cin >> n;

    board = vector<vector <int> > (n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;

        for(int j=0; j<temp.length(); j++){
            board[i][j] = temp[j] - '0';
        }
    }

    cout << solve(0, n-1, 0, n-1);

    return 0;
}
