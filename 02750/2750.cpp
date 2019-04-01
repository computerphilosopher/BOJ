#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	
	int n = 0;
	cin >> n;
	
	int *arr = new int [n];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	sort(arr, arr+n);

	for(int i=0; i<n; i++){
		cout << arr[i] <<endl;
		 
	}

	delete arr;

	return 0;
	 
}
