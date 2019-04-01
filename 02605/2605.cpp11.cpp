#include <iostream>
#include <vector>
using namespace std;


class WaitingManager{

	private:

	struct student {
		int order;
		int ticket; 
	};

	vector<student> waiting;
	vector<int> inputVector;
	int size;

	void GetInput(){

		for(int i=0; i<size; i++){
			student s;
			s.order=i+1;

			cin >> s.ticket;

			waiting.insert((waiting.begin()+i)-s.ticket,s);

		}
	}

	public:

	WaitingManager(int size){
		this->size= size;

	}

	void solve(){
		GetInput();

		for(int i=0; i<size; i++){
			cout << waiting.at(i).order << " ";
		}
	}



};

int main(){

	int size;

	cin >> size;

	WaitingManager w(size);

	w.solve();

}


