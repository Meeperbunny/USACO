/*
ID: meeperbunny
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int board[100][100];
int checked[100][100];
int N, K;
struct Point {
	int x, y;
};
struct Chunk {
	int id;
	vector<Point> mem;
};
bool clearMems() {
	bool r = false;
	for (int i = 0; i < N; i++) {
		for (int q = 0; q < 10; q++) {
			checked[i][q] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int q = 0; q < 10; q++) {
			if (checked[i][q]) continue;
			if (board[i][q] == 0) continue;
			Chunk n;
			n.id = board[i][q];
			Point start;
			start.y = i;
			start.x = q;
			queue<Point> Q;
			Q.push(start);
			while (!Q.empty()) {
				Point curr(Q.front()); Q.pop();
				if (curr.x < 0 || curr.x >= 10) continue;
				if (curr.y < 0 || curr.y >= N) continue;
				if (checked[curr.y][curr.x]) continue;
				if (board[curr.y][curr.x] != n.id) continue;
				checked[curr.y][curr.x] = true;
				n.mem.push_back(curr);
				Point a(curr), b(curr), c(curr), d(curr);
				a.x--;
				b.x++;
				c.y--;
				d.y++;
				Q.push(a);
				Q.push(b);
				Q.push(c);
				Q.push(d);
			}
			if (n.mem.size() >= K) {
				r = true;
				for (auto i : n.mem) {
					board[i.y][i.x] = 0;
				}
			}
		}
	}
	return r;
}
void moveDown() {
	int replace[100][100];
	for (int i = 0; i < N; i++) {
		for (int q = 0; q < 10; q++) {
			replace[i][q] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		int c = N - 1;
		for (int q = N - 1; q >= 0; q--) {
			if (board[q][i] != 0) {
				replace[c][i] = board[q][i];
				c--;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int q = 0; q < 10; q++) {
			board[i][q] = replace[i][q];
		}
	}
}
int main() {
	//freopen("task.in", "r", stdin);
	//freopen("task.out", "w", stdout);
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int q = 0; q < 10; q++) {
			board[i][q] = s[q] - '0';
		}
	}
	moveDown();
	while (clearMems()) {
		moveDown();

	}


	for (int i = 0; i < N; i++) {
		for (int q = 0; q < 10; q++) {
			cout << board[i][q];
		} cout << endl;
	}
}