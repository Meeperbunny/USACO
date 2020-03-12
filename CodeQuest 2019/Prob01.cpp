#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
double timeStamp[10];
string name[10];
int getVal(string name) {
	int tot = 0;
	for (int i = 0; i < name.size(); i++) {
		tot += name[i] - 'a' + 1;
	}
	return tot;
}
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		double lastHash = 0;
		for (int i = 0; i < 10; i++) cin >> name[i];
		for (int i = 0; i < 10; i++) cin >> timeStamp[i];
		for (int i = 0; i < 10; i++) {
			double upper = (timeStamp[i] + getVal(name[i]) + (i + 1) + lastHash) * 50 / 147;
			if (i == 9) cout << long(round(upper)) << endl;
			lastHash = upper;
		}

	}
	return 0;
}