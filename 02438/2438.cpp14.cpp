#include <iostream>
#include <string>

using namespace std;

string solve(const int n, const int depth) {
	
	if (depth > n) {
		return "";
	}

	string ret;

	for (int i = 0; i <depth; i++) {
		ret += '*';
	}

	return ret + "\n" + solve(n, depth+1);
}

int main() {
	int n = 0;
	cin >> n;

	cout << solve(n, 1);

	return 0;
}