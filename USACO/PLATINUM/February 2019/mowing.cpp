/*
ID: mckibbe1
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define MAXN 1000000
#define MOD 1000000007
using namespace std;
struct Point {
	long long x, y, id;
	long long area(Point other) {
		return abs(x - other.x) * abs(y - other.y);
	}
};
bool xSort(Point a, Point b) {
	return a.x < b.x;
}
long long minTree[MAXN * 2];
long long maxTree[MAXN * 2];
long long arr[MAXN];
Point flowers[MAXN];
pair<long long, long long> dp[MAXN];
void construct(long long c, long long s, long long e) {
	if (s > e) return;
	if (s == e) {
		minTree[c] = dp[s].first;
		maxTree[c] = dp[s].second;
		return;
	}
	long long mid = (s + e) / 2;
	construct(c * 2 + 1, s, mid);
	construct(c * 2 + 2, mid + 1, e);
	minTree[c] = min(minTree[c * 2 + 1], minTree[c * 2 + 2]);
	maxTree[c] = max(maxTree[c * 2 + 1], maxTree[c * 2 + 2]);
	return;
}
long long getMin(long long c, long long s, long long e, long long qs, long long qe) {

	if (s > e || s > qe || e < qs) {
		return LLONG_MAX;
	}
	if (s >= qs && e <= qe) {
		return minTree[c];
	}
	long long mid = (s + e) / 2;
	long long left = getMin(c * 2 + 1, s, mid, qs, qe);
	long long right = getMin(c * 2 + 2, mid + 1, e, qs, qe);
	return min(left, right);
}
long long getMax(long long c, long long s, long long e, long long qs, long long qe) {

	if (s > e || s > qe || e < qs) {
		return 0;
	}
	if (s >= qs && e <= qe) {
		return maxTree[c];
	}
	long long mid = (s + e) / 2;
	long long left = getMax(c * 2 + 1, s, mid, qs, qe);
	long long right = getMax(c * 2 + 2, mid + 1, e, qs, qe);
	return max(left, right);
}


int main() {
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	long long N, T; cin >> N >> T;
	N += 2;
	for (long long i = 0; i < N + 2; i++) {
		dp[i] = make_pair(999000000000000, -1);
		flowers[i].id = i;
		if (i == N - 2) {
			flowers[i].x = 0;
			flowers[i].y = 0;
			dp[i] = make_pair(0, 1);
		}
		else if (i == N - 1) {
			flowers[i].x = T;
			flowers[i].y = T;
		}
		else {
			cin >> flowers[i].x >> flowers[i].y;
		}
	}
	sort(flowers, flowers + N, xSort);
	for (long long i = 0; i < N; i++) {
		//cout << "CURRID " << flowers[i].x << ' ' << flowers[i].y << ' ' << dp[flowers[i].id] << endl;
		long long maxFrom = 0;
		for (long long q = i - 1; q >= 0; q--) {
			if (flowers[q].y >= flowers[i].y) continue;
			maxFrom = max(maxFrom, dp[flowers[q].id].second);
		}
		for (long long q = i - 1; q >= 0; q--) {
			if (flowers[q].y >= flowers[i].y) continue;
			if (dp[flowers[q].id].second != maxFrom) continue;
			long long baseId = flowers[i].id;
			dp[baseId] = make_pair(min(dp[baseId].first, dp[flowers[q].id].first + flowers[i].area(flowers[q])), maxFrom + 1);
			//cout << '\t' << flowers[q].x << ' ' << flowers[q].y << ' ' << dp[baseId] << endl;
		}
	}
	cout << dp[flowers[N - 1].id].first << endl;
	return 0;
}