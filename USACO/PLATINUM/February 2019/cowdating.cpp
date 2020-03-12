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
long double arr[MAXN], frac[MAXN], d[MAXN], ff[MAXN];
long double getProb(int a, int b) {
	if (a == 0) {
		return (ff[b]) * (d[b]);
	}
	else {
		return (ff[b] - ff[a - 1]) * (d[b] / d[a - 1]);
	}
}
int main() {
	freopen("cowdate.in", "r", stdin);
	freopen("cowdate.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	long double N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] /= 1000000;
		if (arr[i] == 1) {
			cout << 1000000 << endl;
			return 0;
		}
		frac[i] = arr[i] / (1 - arr[i]);
		if (i == 0) ff[i] = (frac[i]);
		else ff[i] = ff[i - 1] + frac[i];
		if (i == 0) d[i] = (1 - arr[i]);
		else d[i] = d[i - 1] * (1 - arr[i]);
	}
	if (N == 1) {
		cout << 1000000 * arr[0] << endl;
		return 0;
	}
	long double maxProb = getProb(0, 0);
	long double lower = 0, upper = 0;
	long double currProb = getProb(0, 0);
	while (lower < N) {
		long double moveLower = -1;
		long double moveUpper = -1;
		if (lower < upper) {
			moveLower = getProb(lower + 1, upper);
		}
		if (upper < N - 1) {
			moveUpper = getProb(lower, upper + 1);
		}
		if (moveUpper == -1 || moveLower >= moveUpper) {
			lower++;
			currProb = moveLower;
		}
		else if (moveLower == -1 || moveUpper >= moveLower) {
			upper++;
			currProb = moveUpper;
		}
		else {
			break;
		}
		maxProb = max(currProb, maxProb);
	}
	cout << maxProb * 1000000 << endl;
	return 0;

}