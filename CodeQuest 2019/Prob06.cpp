#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main() {
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	int T; cin >> T;
	cout << setprecision(1) << fixed;
	for (int t = 0; t < T; t++) {
		float a; cin >> a;
		cout << 3.14159 * 2 * (40075 + a) << endl;
	}
	return 0;
}