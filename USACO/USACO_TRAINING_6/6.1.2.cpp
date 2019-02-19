/*
ID: mckibbe1
TASK: rectbarn
LANG: C++11
*/
#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;
bool blocked[MAXN][MAXN];
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	freopen("rectbarn.in", "r", stdin);
	freopen("rectbarn.out", "w", stdout);

	for (int i = 0; i < MAXN; i++) {
		for (int q = 0; q < MAXN; q++) {
			blocked[i][q] = 0;
		}
	}

	//get input

	int R, C, P;
	cin >> R >> C >> P;

	//Calc Ans
	for (int i = 0; i < P; i++) {
		int y, x;
		cin >> y >> x;
		y--; x--;
		blocked[y][x] = true;
	}

	int maxArea = 0;
	int oldArr[MAXN];

	for (int n = 0; n < R; n++) {
		
		int newArr[MAXN];
		for (int i = 0; i < C; i++) {
			if (blocked[n][i]) newArr[i] = 0;
			else if (n == 0) newArr[i] = 1;
			else newArr[i] = oldArr[i] + 1;
		}

		//cout << "NEWROW\n";
		stack<pair<int, int>> s;
		int lastVal = 0;
		for (int i = 0; i <= C; i++) {
			int curr;
			if (i == C) curr = 0;
			else curr = newArr[i];
			//cout << "\tNEWITEM " << i << '\n';
			//cout << "\tCURR: " << curr << '\n';
			//cout << "\t\tSTACKSIZE " << s.size() << '\n';
			if (curr > lastVal) {
				s.push(make_pair(curr, i));
			}
			else if (curr < lastVal) {
				pair<short, short> sTop = s.top();
				bool broken = false;
				int last = -1;
				while (sTop.first > curr) {
					//cout << "\t\t\tAREACHECK: " << sTop.first * (i - sTop.second) << '\n';
					maxArea = max(maxArea, sTop.first * (i - sTop.second));
					last = sTop.second;
					if (s.size() == 1) {
						s.pop();
						s.push(make_pair(curr, sTop.second));
						broken = true;
						break;
					}
					s.pop();
					sTop = s.top();
				}
				if (!broken) {
					s.push(make_pair(curr, last));
				}
			}
			lastVal = curr;

		}
		for (int i = 0; i < C; i++) oldArr[i] = newArr[i];
	}

	cout << maxArea << '\n';
	return 0;
}