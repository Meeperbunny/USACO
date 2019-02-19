/*
ID: meeperbunny
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int dp[10001][1001];
int maxSum[10001];
int arr[10001];
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i <= N; i++) {
		maxSum[i] = 0;
		for (int q = 0; q <= K; q++) {
			dp[i][q] = 0;
		}
	}
	dp[1][1] = arr[0];
	for (int i = 1; i <= N; i++) {
		int maxi = arr[i - 1];
		for (int q = i; q > 0 && q > i - K; q--) {
			maxi = max(maxi, arr[q - 1]);
			int gSum = maxi * (i - q + 1);
			
			dp[i][i - q + 1] = gSum + maxSum[i - (i - q + 1)];

			maxSum[i] = max(maxSum[i], dp[i][i - q + 1]);
			//cout << q << ' ' << maxi << "    ";
		} //cout << endl;
	}
	int maxer = 0;
	for (int i = 1; i <= K; i++) {
		maxer = max(maxer, dp[N][i]);
	}
	cout << maxer << endl;
}