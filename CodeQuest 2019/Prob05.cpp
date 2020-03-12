#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		vector<bool> ans(100000);
		for (int i = 1; i <= b; i++) {
			for (int q = 1; q <= a; q++) {
				ans[i * 5 + q] = true;
			}
		}
		if (ans[c] == true) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}