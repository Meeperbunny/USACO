/*
ID: mckibbe1
TASK: rect1
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 600000
using namespace std;
int arr[MAXN];
int dp[MAXN];
char c[MAXN];
int main() {
	freopen("redistricting.in", "r", stdin);
	freopen("redistricting.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int N, K;
	cin >> N >> K >> c;
	for (int i = 0; i < N; i++) {
		dp[i] = MAXN;
		if (c[i] == 'H') arr[i] = true;
		else arr[i] = false;
	}
	if (s[0] == 'H') dp[0] = 0;
	else dp[0] = 1;
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int q = i; q < i + K; q++) {
			if (arr[q] == true) count++;
			else count--;
			//cout << i << ' ' << q << ' ' << count << ' ' << dp[q] << ' ' << dp[i] + int(count <= 0) << endl;
			//
			if (i == 0 && q == 0) continue;
			dp[q] = min(dp[q], dp[i - 1] + int(count <= 0));
			//
		}
		//cout << "DP: ";
		//for (int i = 0; i < N; i++) {
		//	cout << dp[i] << ' ';
		//} cout << endl;
	}
	//cout << "DP: ";
	//for (int i = 0; i < N; i++) {
	//	cout << dp[i] << ' ';
	//} cout << endl;
	cout << dp[N - 1] << endl;
	return 0;
}