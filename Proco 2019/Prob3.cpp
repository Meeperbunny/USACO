#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define MAXN 100000
long N;
int arr[1000], second[1000];
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long q; cin >> q;
		cout << q * long(4) << ' ' << q * long(8) << endl;
	}
	return 0;
}