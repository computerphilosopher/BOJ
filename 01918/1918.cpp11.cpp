#include <iostream>
#include <string>
#include <stack>


using namespace std;

enum tokens{
    operators=51,
    operand,
    left_paren,
    right_paren,
};

enum prio{
    add = 0,
    sub = 0,
    mul = 1,
    divider = 1
};
 
int token_num(char c){

    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return operators;
    
    }
    if('A' <= c && c <= 'Z'){
        return operand;
    }


    if(c == '('){
        return left_paren;
    }
    
    if(c == ')'){
        return right_paren;
    }

    return -1;
}

int priority(char op){
    switch(op){
        case '+':
            return add;
            break;
        case '-':
            return sub;
            break;
        case '*':
            return mul;
            break;
        case '/':
            return divider;
            break;
    }

    return 0;
}

string toPostfix(const string input){
    
    string ret;
    stack<char> s;

    for(int i=0; i<input.length(); i++){

        const char token = input[i];
        const int tn = token_num(token);
         
        switch(tn){

            case operators:
                if(s.empty()){
                    s.push(token);
                }

                else{
                    while(!s.empty() && priority(s.top()) >= priority(token)){
                        if(s.top() == '('){
                            break;
                        }
                        ret += s.top();
                        s.pop();
                    }  
                    s.push(token);

                }
                break;
                 
            case operand:
                ret += token;
                break;
                 
            case left_paren:
                s.push(token);
                break;
                 
            case right_paren:
                 
                while(!s.empty() && s.top() != '('){
                    ret += s.top();
                    s.pop();
                }

                s.pop();

                break;
        }
    }

    while(!s.empty()){
        ret += s.top();
        s.pop();
    }

    return ret;
}
int main(){

    string input;

    cin >> input;

    cout << toPostfix(input) << endl;

    return 0;
}
