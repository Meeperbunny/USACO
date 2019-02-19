/*
ID: mckibbe1
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;
int dp[MAXN][MAXN][2];
pair<int, int> H[MAXN], G[MAXN];
int dist(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	int HH, GG; cin >> HH >> GG;
	for (int i = 0; i < HH; i++) {
		cin >> H[i].first >> H[i].second;
	}
	for (int i = 0; i < GG; i++) {
		cin >> G[i].first >> G[i].second;
	}
	for (int i = 0; i < MAXN; i++) for (int q = 0; q < MAXN; q++) {
		dp[i][q][0] = 2000000000; dp[i][q][1] = 2000000000;
	}
	dp[1][0][0] = 0;
	for (int h = 1; h <= HH; h++) {
		for (int g = 0; g <= GG; g++) {
			for (int n = 0; n < 2; n++) {
				if (g == 0 && n == 1) continue;
				if (h == 1 && n == 0) continue;
				if (n == 0) {
					dp[h][g][n] = min(dp[h - 1][g][0] + dist(H[h - 1], H[h - 2]), dp[h - 1][g][1] + dist(H[h - 1], G[g - 1]));
				}
				else {
					dp[h][g][n] = min(dp[h][g - 1][1] + dist(G[g - 1], G[g - 2]), dp[h][g - 1][0] + dist(G[g - 1], H[h - 1]));
				}
			}
		}
	}
	cout << dp[HH][GG][0] << endl;
	return 0;
}