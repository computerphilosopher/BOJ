#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CharCounter {

	private:
		const static int ALPHABET_LENGTH=26;
		enum ALPHABET {A=0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };
		int arr[ALPHABET_LENGTH]={0};
		string str;

	public: 
		CharCounter(string a_str){

			str=a_str;
			fill_n(arr, ALPHABET_LENGTH, -1);
		}

		void CountingPrint(){
			for(int i=0; i<ALPHABET_LENGTH; i++){
				cout << arr[i] << " ";
			}

		}

		void writeStartingPoint(){
			for(int i=0; i<str.size(); i++){
				switch(str[i]){
					case 'a':
						if(arr[A]==-1)
							arr[A]=i;
						break;

					case 'b':
						if(arr[B]==-1)
							arr[B]=i;
						break;

					case 'c':
						if(arr[C]==-1)
							arr[C]=i;
						break;

					case 'd':
						if(arr[D]==-1)
							arr[D]=i;
						break;

					case 'e':
						if(arr[E]==-1)
							arr[E]=i;
						break;

					case 'f':
						if(arr[F]==-1)
							arr[F]=i;
						break;

					case 'g':
						if(arr[G]==-1)
							arr[G]=i;
						break;

					case 'h':
						if(arr[H]==-1)
							arr[H]=i;
						break;

					case 'i':
						if(arr[I]==-1)
							arr[I]=i;
						break;

					case 'j':
						if(arr[J]==-1)
							arr[J]=i;
						break;

					case 'k':
						if(arr[K]==-1)
							arr[K]=i;
						break;

					case 'l':
						if(arr[L]==-1)
							arr[L]=i;
						break; 

					case 'm':
						if(arr[M]==-1)
							arr[M]=i;
						break; 

					case 'n':
						if(arr[N]==-1)
							arr[N]=i;
						break; 

					case 'o':
						if(arr[O]==-1)
							arr[O]=i;
						break; 

					case 'p':
						if(arr[P]==-1)
							arr[P]=i;
						break; 

					case 'q':
						if(arr[Q]==-1)
							arr[Q]=i;
						break; 

					case 'r':
						if(arr[R]==-1)
							arr[R]=i;
						break; 

					case 's':
						if(arr[S]==-1)
							arr[S]=i;
						break; 

					case 't':
						if(arr[T]==-1)
							arr[T]=i;
						break; 

					case 'u':
						if(arr[U]==-1)
							arr[U]=i;
						break; 

					case 'v':
						if(arr[V]==-1)
							arr[V]=i;
						break; 

					case 'w':
						if(arr[W]==-1)
							arr[W]=i;
						break; 

					case 'x':
						if(arr[X]==-1)
							arr[X]=i;
						break; 

					case 'y':
						if(arr[Y]==-1)
							arr[Y]=i;
						break; 

					case 'z':
						if(arr[Z]==-1)
							arr[Z]=i;
						break; 
				}
			}
		}
};



int main(){

	string input;
	cin >> input;
	CharCounter c(input);

	c.writeStartingPoint();
	c.CountingPrint();


	return 0;
}


