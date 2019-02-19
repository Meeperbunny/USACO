/*
ID: mckibbe1
TASK: rect1
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 100000
#define MOD 1000000007
using namespace std;
struct Word {
	long long sy, id;
};
bool comp(long long a, long long b) {
	return a > b;
}
long long power(long long x, long long y)
{
	long long temp;
	if (y == 0)
		return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp) % MOD;
	else
	{
		if (y > 0)
			return (x * ((temp*temp) % MOD)) % MOD;
		else
			return (((temp*temp) % MOD) / x) % MOD;
	}
}
Word arr[5000];
long long combinations[5000];
long long dp[5001][5000];
long long tot[5001];
long long counter[26];
int main() {
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	long long N, M, K;
	cin >> N >> M >> K;
	memset(dp, sizeof(dp), 0);
	memset(tot, sizeof(tot), 0);
	for (long long i = 0; i < 5000; i++) {
		combinations[i] = 0;
	}
	for (long long i = 0; i < N; i++) {
		cin >> arr[i].sy >> arr[i].id;
		arr[i].id--;
		dp[arr[i].sy][arr[i].id]++;
		tot[arr[i].sy]++;
	}
	for (long long i = 0; i < M; i++) {
		char c; cin >> c;
		counter[c - 'A']++;
	}
	for (long long i = 0; i < K; i++) {
		for (long long q = 0; q < N; q++) {
			if (i + arr[q].sy > 5000) continue;
			if (arr[q].id >= 5000) continue;
			dp[i + arr[q].sy][arr[q].id] = (dp[i + arr[q].sy][arr[q].id] + tot[i]) % MOD;
			tot[i + arr[q].sy] = (tot[i + arr[q].sy] + tot[i]) % MOD;
		}
	}
	//for (long long i = 0; i < 5000; i++) {
	//	cout << i << "   ";
	//	for (long long q = 0; q < N; q++) {
	//		cout << dp[i][q] << ' ';
	//	} cout << "   " << tot[i] << endl;
	//}
	sort(counter, counter + 26, comp);
	long long base = 1;
	for (long long c = 0; c < 26 && counter[c] > 0; c++) {
		long long sum = 0;
		for (long long q = 0; q < 5000; q++) {
			for (int n = 0; n < counter[c]; n++) {

			}
			sum += power(dp[K][q], counter[c]);
			sum %= MOD;
			if (sum > MOD || sum < 0) assert(false);
		}
		base = (base * sum) % MOD;
		//if (base > MOD || base < 0) assert(false);
	}
	cout << base << endl;
	return 0;
}