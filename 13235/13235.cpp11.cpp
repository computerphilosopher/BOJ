#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string &s,const int start, const int end) {
	
	int mid = (start + end) / 2;
	int i = 0;

	if (start == end) {
		return true;
	}
	while (i <= mid && end - i > mid) {
		if (s[i] != s[end-i]) {
			return false;
		}
		i++;
	}
	return true;
	
}
int main() {

	string s;
	cin >> s;

	if( is_palindrome(s, 0, s.length() - 1) ){
        cout << "true";
    }
    else{
        cout << "false";
    }
}