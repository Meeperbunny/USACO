/*
ID: mckibbe1
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 200000
using namespace std;

int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		int bCount = 0, eCount = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') eCount++;
			if (s[i] == 'B') bCount++;
		}
		cout << "Case #" << i + 1 << ": ";
		if (bCount >= eCount && eCount != 0) {
			cout << "Y";
		}
		else {
			cout << "N";
		}
		cout << '\n';
	}
	return 0;
}