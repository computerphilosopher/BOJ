#include <stdio.h>
#include <iostream>

using namespace std;

class StairCounter{

	private:
		
		int memo[301];
		int stair[301];
		int size;

		int Max(int a, int b){

			if(a>=b){
				return a;
			}
			else{
				return b;
			}
		}
	public:

		StairCounter(int size){

			this->size = size;

			for(int i=0; i<301; i++){
				memo[i]= -1;
			}

		}

		void InputStair(){

			for(int i=1; i<=size; i++){

				cin >> stair[i];

			}
		}

		int CalculateMaxPoint(int n){

			int solution=0;

			if(memo[n]!=-1){
				return memo[n];
			}

			if(n==0){
				solution = 0;
			}

			else if(n == 1){
				solution = stair[1];
			}

			else if(n==2){

				solution = stair[1] + stair[2]; 
			}

			else{
				solution =  Max(CalculateMaxPoint(n-3) + stair[n-1] + stair[n], CalculateMaxPoint(n-2) + stair[n]);
			}

			memo[n] = solution;
			return solution;
		}
		
};


int main(){

	int size=0;

	cin >> size;

	StairCounter stair(size);

	stair.InputStair();

	int solution = stair.CalculateMaxPoint(size);

	cout<< solution ;

}


