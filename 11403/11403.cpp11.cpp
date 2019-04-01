#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector < vector<bool> > adj;
vector <bool> visited;


void dfs(const int here, const int count) {

	if (count != 0) {
		visited[here] = true;
	}

	for (int i = 0; i < n; i++) {
		if (adj[here][i] && !visited[i]) {
			dfs(i, count+1);
		}
	}
}

void print_dfs() {

	vector < vector <bool> > result(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {

		fill(visited.begin(), visited.end(), false);

		dfs(i, 0);

		for (int j = 0; j < n; j++) {
			result[i][j] = visited[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {


	cin.sync_with_stdio(false);
	cin >> n;

	adj = vector < vector<bool> >(n, vector<bool>(n, false));
	visited = vector<bool>(n, false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool temp = false;
			cin >> temp;
			adj[i][j] = temp;
		}
	}

	print_dfs();

}