/*
ID: mckibbe1
TASK: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
int hills[MAXN];
int N;
int cost(int n) {
	int tot = 0;
	for (int i = 0; i < N; i++) {
		if (hills[i] > n) tot += (hills[i] - n) * (hills[i] - n);
		if (hills[i] + 17 < n) tot += (n - (hills[i] + 17)) * (n - (hills[i] + 17));
	} return tot;
}
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> hills[i];
	int k = -1;
	for (int n = MAXN / 2; n >= 1; n /= 2) while (cost(k + n) > cost(k + n + 1)) k += n;
	cout << cost(k + 1) << endl;
	return 0;
}