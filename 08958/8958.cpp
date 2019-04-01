#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){

	int n=0;
	int Ostack=0;
	int sum=0;

	cin >> n;

	queue<string> Q;
	string buf="";

	for(int i=0; i<n; i++){
		cin >> buf;
		Q.push(buf);
	}



	while(!Q.empty()){
		sum=0;
		Ostack=0;
		buf=Q.front();
		for(int i=0; i<buf.length(); i++){
			if(buf[i]=='O'){
				Ostack++;
				sum+=Ostack;
			}

			else{
				Ostack=0;
			}
		}
		Q.pop();
		cout << sum << endl;
	}



}


