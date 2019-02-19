/*
ID: mckibbe1
TASK: money
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 400001
using namespace std;
long long lazy[MAXN * 2];
long long minTree[MAXN * 2];
long long sumTree[MAXN * 2];
long long arr[MAXN];
long long N, Q;
void construct(long long c, long long s, long long e) {
	if (s > e) return;
	if (s == e) {
		minTree[c] = arr[s];
		sumTree[c] = arr[s];
		return;
	}
	long long mid = (s + e) / 2;
	construct(c * 2 + 1, s, mid);
	construct(c * 2 + 2, mid + 1, e);
	minTree[c] = min(minTree[c * 2 + 1], minTree[c * 2 + 2]);
	sumTree[c] = sumTree[c * 2 + 1] + sumTree[c * 2 + 2];
	return;
}
void updateLazy(long long c, long long s, long long e) {
	//cout << "UPDATING " << s << ' ' << e << ' ' << lazy[c] << endl;
	sumTree[c] += lazy[c] * (e - s + 1);
	minTree[c] += lazy[c];
	if (s != e) {
		lazy[c * 2 + 1] += lazy[c];
		lazy[c * 2 + 2] += lazy[c];
	}
	lazy[c] = 0;
}
void updateRange(long long c, long long s, long long e, long long qs, long long qe, long long val) {
	if (lazy[c] != 0) {
		updateLazy(c, s, e);
	}
	if (s >= qs && e <= qe) {
		//cout << "Changing " << s << ' ' << e << " by " << val  << endl;
		sumTree[c] += val * (e - s + 1);
		minTree[c] += val;
		if (s != e) {
			lazy[c * 2 + 1] += val;
			lazy[c * 2 + 2] += val;
		}
		return;
	}
	if (s > e || s > qe || e < qs) {
		return;
	}
	long long mid = (s + e) / 2;
	updateRange(c * 2 + 1, s, mid, qs, qe, val);
	updateRange(c * 2 + 2, mid + 1, e, qs, qe, val);
	sumTree[c] = sumTree[c * 2 + 1] + sumTree[c * 2 + 2];
	minTree[c] = min(minTree[c * 2 + 1], minTree[c * 2 + 2]);
	return;
}
long long getMin(long long c, long long s, long long e, long long qs, long long qe) {
	if (lazy[c] != 0) {
		updateLazy(c, s, e);
	}
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
long long getSum(long long c, long long s, long long e, long long qs, long long qe) {
	if (lazy[c] != 0) {
		updateLazy(c, s, e);
	}
	if (s > e || s > qe || e < qs) {
		return 0;
	}
	if (s >= qs && e <= qe) {
		//cout << "RETURNING " << s << ' ' << e << ' ' << sumTree[c] << endl;
		return sumTree[c];
	}
	long long mid = (s + e) / 2;
	long long left = getSum(c * 2 + 1, s, mid, qs, qe);
	long long right = getSum(c * 2 + 2, mid + 1, e, qs, qe);
	return left + right;
}
int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> N >> Q;
	for (long long i = 0; i < N * 2; i++) {
		lazy[i] = 0;
		minTree[i] = LLONG_MAX;
		sumTree[i] = 0;
	}
	for (long long i = 0; i < N; i++) {
		cin >> arr[i];
	}
	construct(0, 0, N - 1);
	//for (long long i = 0; i < N * 2; i++) cout << sumTree[i] << ' ';
	//cout << endl;
	for (long long i = 0; i < Q; i++) {
		char c; long long a, b;
		cin >> c >> a >> b;
		a--, b--;
		if (c == 'S') {
			cout << getSum(0, 0, N - 1, a, b) << endl;
		}
		else if (c == 'M') {
			cout << getMin(0, 0, N - 1, a, b) << endl;
		}
		else {
			long long n; cin >> n;
			updateRange(0, 0, N - 1, a, b, n);
			//cout << "DONE " << endl;
			//for (long long i = 0; i < N * 2; i++) cout << sumTree[i] << ' ';
			//cout << endl;
		}
	}

	return 0;
}