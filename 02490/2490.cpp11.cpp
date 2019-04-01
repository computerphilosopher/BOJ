#include <iostream>
#include <string>

using namespace std;

int main(){

	enum {DO=3, GAE=2, GIRL=1, YUT=0, MO=4};

	int dice[3][4];
	int sum=0;

	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			cin >> dice[i][j];
		}
	}

	for(int i=0; i<3; i++){
		sum=0;
		for(int j=0; j<4; j++){
			sum+=dice[i][j];
		}
		switch(sum){
			case DO:
				cout << 'A' << endl;
				break;
			case GAE:
				cout << 'B' << endl;
				break;
			case GIRL:
				cout << 'C' << endl;
				break;
			case YUT:
				cout << 'D' << endl;
				break;
			case MO:
				cout << 'E' << endl;
				break;
		}
	}
	
}

