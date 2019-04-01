#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

typedef vector<vector <int> > box;

int rows = 0, cols = 0, height = 0;

// 위 아래 왼 오 앞 뒤
const int dheight[6] = { 1, -1, 0, 0, 0, 0 };
const int drow[6] = { 0, 0, 0, 0, 1, -1 };
const int dcol[6] = { 0, 0, -1, 1, 0, 0 };

enum state {
	empty = -1, 
	notYet = 0, //  안 익음
	ripe = 1, //익었음
};

typedef struct Point {
	int floor, row, col;
	Point(const int f, const int r, const int c) :floor(f), row(r), col(c) {

	}

};

/* 디버깅용*/
void print_boxes(const vector<box> &boxes) {
	cout << endl;
	for (int h = 0; h < height; h++) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				cout << boxes[h][r][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

bool in_box(const int floor, const int row, const int col) {
	if (floor < 0 || row < 0 || col < 0) return false;
	if (floor >= height || row >= rows || col >= cols) return false;
	return true;
}

int bfs(const vector<box> &boxes) {

	queue<Point> q;

	vector<box> distance(height,
		box(rows, vector<int>(cols, -1)));

	for (int h = 0; h < height; h++) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				const int tomato = boxes[h][r][c];

				if (tomato == ripe){
					q.push(Point(h, r, c));
					distance[h][r][c] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		const Point here = q.front();
		q.pop();

		const int r = here.row, c = here.col, f = here.floor;

		for (int i = 0; i < 6; i++) {
			const Point next(f + dheight[i], r + drow[i], c + dcol[i]);

			const int nf = next.floor, nr = next.row, nc = next.col;

			if (in_box(nf, nr, nc)) {
				//printf("%d %d %d inbox ripe:%d, distance:%d\n", nf, nr, nc, boxes[nf][nr][nc]==ripe, distance[nf][nr][nc] == -1);
				if (boxes[nf][nr][nc] == notYet && distance[nf][nr][nc] == -1) {
					q.push(next);
					distance[nf][nr][nc] = distance[f][r][c] + 1;
				}
			}
		}
	}

	int ret = -1;

	//print_boxes(distance);

	for (int h = 0; h < height; h++) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				if (distance[h][r][c] == -1 && boxes[h][r][c] == notYet) {
					return -1;
				}
				ret = max(ret, distance[h][r][c]);
			}
		}
	}
	return ret;
}
int main() {


	cin >> cols >> rows >> height;

	vector<box> boxes(height,
		box(rows, vector<int>(cols, 0)));

	for (int h = 0; h < height; h++) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				int temp = 0;
				cin >> temp;
				boxes[h][r][c] = temp;
			}
		}
	}

	cout << bfs(boxes);
	return 0;
}
