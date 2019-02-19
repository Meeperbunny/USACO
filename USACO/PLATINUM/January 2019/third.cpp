/*
ID: mckibbe1
TASK: rect1
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 100000
#define MAXNUM 1000000000
#define MOD 1000000007
using namespace std;
long long power(long long x, long long y) {
	long long temp;
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	temp = power(x, y / 2);
	if (temp * temp < 0) assert(false);
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
long long combinations(long long u, long long d) {
	//cout << u << ' ' << d << endl;
	long long ret = power(u, d) - power(u - 1, d);
	if (ret < 0) {
		ret += MOD;
	}
	//cout << u << ' ' << d << ' ' << ret << endl;
	return ret;
}
long long N, K, S;
long long mins[MAXN];
long long g[MAXN];
long long tot[MAXN];
set<long> idDiff;
int main() {
	freopen("tracking2.in", "r", stdin);
	freopen("tracking2.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	cin >> N >> K;
	S = N - K + 1;
	if (K == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (long long i = 0; i < S; i++) {
		cin >> mins[i];
		idDiff.insert(mins[i]);
		g[i] = false;
		tot[i] = 0;
	}
	if (idDiff.size() == 1) {
		cout << combinations(MAXNUM - mins[0] + 1, N) << endl;
		return 0;
	}
	for (long long i = S - 1; i >= 0; i--) {
		long long curr = mins[i];
		for (long long q = 0; q < K; q++) {
			//cout << i << ' ' << q << endl;
			if (g[i + q] && tot[i + q] != curr) {
				if (q == 1) {
					//cout << "LOCKED " << i << endl;
					g[i] = true;
				}
				break;
			}
			if (curr > tot[i + q]) {
				if (q == K - 1 && curr != tot[i + q + 1]) {
					//cout << "LOCKED " << i + q + 1 << endl;
					g[i + q + 1] = true;
				}
				tot[i + q] = curr;
			}
			else if (q == 1 && curr != tot[i + q]) {
				//cout << "LOCKED " << i << endl;
				g[i] = true;
				break;
			}
			else break;
		}
	}
	//for (long long i = 0; i < N; i++) {
	//	cout << tot[i] << endl;
	//}
	long long ans = 1;
	long long chained = 1;
	long long last = tot[0];
	bool deadLocked = g[0];
	//cout << "C " << 0 << ' ' << deadLocked << endl;
	for (long long i = 1; i < N; i++) {
		//cout << last << ' ' << tot[i] << endl;
		if (last != tot[i]) {
			//cout << "CHANGED" << endl;
			//cout << ans << endl;
			if (deadLocked) {
				ans *= power(MAXNUM - last + 1, chained - 1);
				//cout << ans << endl;
			}
			else {
				//cout << "CHAIN :" << chained << endl;
				ans *= combinations(MAXNUM - last + 1, chained);
				//cout << ans << endl;
			}
			if (ans < 0) assert(false);
			ans %= MOD;
			last = tot[i];
			chained = 1;
			deadLocked = false;
		}
		else {
			if (g[i]) deadLocked = true;
			chained++;
		}
		//cout << "C " << i << ' ' << deadLocked << endl;
	}
	//for (long long i = 0; i < N; i++) {
	//	cout << "ID " << tot[i] << ' ' << g[i] << endl;
	//}
	//cout << ans << endl;
	if (deadLocked) {
		ans *= power(MAXNUM - last + 1, chained - 1);
		//cout << ans << endl;
	}
	else {
		//cout << "CHAIN :" << chained << endl;
		ans *= combinations(MAXNUM - last + 1, chained);
		//cout << ans << endl;
	}
	ans %= MOD;
	if (ans < 0) assert(false);
	cout << ans << endl;
	return 0;
}