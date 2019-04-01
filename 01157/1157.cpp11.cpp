#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CharCounter {
	
	private:
		const static int ALPHABET_LENGTH=26;
		enum ALPHABET {A=0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };
		int *arr;
		string str;

	public: 
		CharCounter(string a_str){
			arr=new int[ALPHABET_LENGTH]();
			str=a_str;
		}

		void CountingPrint(){
			for(int i=0; i<ALPHABET_LENGTH; i++){
				cout << arr[i] << endl;
			}
		}

		void Counting(){
			for(int i=0; i<str.size(); i++){
				switch(str[i]){
				case 'a':
				case 'A':
					arr[A]+=1;
					break;

				case 'b':
				case 'B':
					arr[B]+=1;
					break;

				case 'c':
				case 'C':
					arr[C]+=1;
					break;

				case 'd':
				case 'D':
					arr[D]+=1;
					break;

				case 'e':
				case 'E':
					arr[E]+=1;
					break;

				case 'f':
				case 'F':
					arr[F]+=1;
					break;

				case 'g':
				case 'G':
					arr[G]+=1;
					break;

				case 'h':
				case 'H':
					arr[H]+=1;
					break;

				case 'i':
				case 'I':
					arr[I]+=1;
					break;

				case 'j':
				case 'J':
					arr[J]+=1;
					break;

				case 'k':
				case 'K':
					arr[K]+=1;
					break;
				
				case 'l':
				case 'L':
					arr[L]+=1;
					break; 
				
				case 'm':
				case 'M':
					arr[M]+=1;
					break; 
				
				case 'n':
				case 'N':
					arr[N]+=1;
					break; 
				
				case 'o':
				case 'O':
					arr[O]+=1;
					break; 
				
				case 'p':
				case 'P':
					arr[P]+=1;
					break; 
				
				case 'q':
				case 'Q':
					arr[Q]+=1;
					break; 
				
				case 'r':
				case 'R':
					arr[R]+=1;
					break; 
				
				case 's':
				case 'S':
					arr[S]+=1;
					break; 
				
				case 't':
				case 'T':
					arr[T]+=1;
					break; 
				
				case 'u':
				case 'U':
					arr[U]+=1;
					break; 
				
				case 'v':
				case 'V':
					arr[V]+=1;
					break; 
				
				case 'w':
				case 'W':
					arr[W]+=1;
					break; 
				
				case 'x':
				case 'X':
					arr[X]+=1;
					break; 
				
				case 'y':
				case 'Y':
					arr[Y]+=1;
					break; 
				
				case 'z':
				case 'Z':
					arr[Z]+=1;
					break; 
				}
			}
		}

		char MostChar(){

			int max=0; 
			int max_count=0;
			int max_index=0;

			for(int i=0; i<ALPHABET_LENGTH; i++){
				if(arr[i] > max){
					max_index=i;
					max = arr[i];
					max_count = 1;
				}

				else if(arr[i]==max){
					max_count++;
				}
				else{
					//nothing
				}
			}

			if(max_count != 1){
				return '?';
			}

			else{
				switch(max_index){
					case A:
						return 'A';
						break;
					case B:
						return 'B';
						break;
					case C:
						return 'C';
						break;
					case D:
						return 'D';
						break;
					case E:
						return 'E';
						break;
					case F:
						return 'F';
						break;
					case G:
						return 'G';
						break;
					case H:
						return 'H';
						break;
					case I:
						return 'I';
						break;
					case J:
						return 'J';
						break;
					case K:
						return 'K';
						break;
					case L:
						return 'L';
						break;
					case M:
						return 'M';
						break;
					case N:
						return 'N';
						break;
					case O:
						return 'O';
						break;
					case P:
						return 'P';
						break;
					case Q:
						return 'Q';
						break;
					case R:
						return 'R';
						break;
					case S:
						return 'S';
						break;
					case T:
						return 'T';
						break;
					case U:
						return 'U';
						break;
					case V:
						return 'V';
						break;
					case W:
						return 'W';
						break;
					case X:
						return 'X';
						break;
					case Y:
						return 'Y';
						break;
					case Z:
						return 'Z';
						break;
				}
			}

		} 

		~CharCounter(){
			delete arr; 
		}
};


int main(){

	string input;
	cin >> input;
	CharCounter c(input);
	c.Counting();
	cout << c.MostChar() << endl;


	return 0;
}

