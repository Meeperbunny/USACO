#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int arr[1000][1000];
int cameFrom[1000][1000];
int rr, cc;
void bfs(int r, int c) {
	//up
	int ceX = -1;
	int ceY = -1;
	bool found = false;
	if (c + 1 < c) {
		if (arr[r][c + 1]) {

		}
	}
	if (c - 1 >= 0) {
		if (arr[r][c - 1]) {

		}
	}

	if (c + 1 < c) {
		if (arr[r][c + 1]) {

		}
	}
	if (c - 1 >= 0) {
		if (arr[r][c - 1]) {

		}
	}

}
int main() {
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	int T; cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++) {
		cin >> rr >> cc;
		cin.ignore();
		int y, x;
		for (int i = 0; i < rr; i++) {
			string s;
			getline(cin, s);
			for (int q = 0; q < cc; q++) {
				if (s[q] == '#') arr[i][q] = 0;
				if (s[q] == ' ') arr[i][q] = 1;
				if (s[q] == 'X') arr[i][q] = 2;
				if (s[q] == 'o') {
					y = i;
					x = q;
					arr[i][q] = 3;
				}
			}
		}
		bfs(y, x);
	}
	return 0;
}