/*
ID: mckibbe1
TASK: rect1
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 100000
using namespace std;
int N, M;
pair<int, int> s[MAXN];
int main() {
	//freopen("exercise.in", "r", stdin);
	//freopen("exercise.out", "w", stdout);
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> s[i].first >> s[i].second;
	}
	int m = 0;
	for (int i = 0; i < N; i++) {
		m = max(s[i].second - 1, m);
	}
	cout << M - N + 1 << endl;
	return 0;
}