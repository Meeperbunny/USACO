/*
ID: mckibbe1
LANG: C++11
TASK: newbarn
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define MAXN 100000
#define MOD 1000000007
using namespace std;
list<int> nodes[MAXN];
int getDist(int n) {
	bool checked[MAXN];
	memset(checked, 0, sizeof(checked));
	int ret = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		pair<int, int> curr = q.front();  q.pop();
		//cout << '\t' << curr.first << ' ' << curr.second << endl;
		ret = max(ret, curr.second);
		checked[curr.first] = true;
		for (auto i : nodes[curr.first]) {
			if (checked[i]) continue;
			q.push(make_pair(i, curr.second + 1));
		}
	}
	return ret;
}
int main() {
	//freopen("newbarn.in", "r", stdin);
	//freopen("newbarn.out", "w", stdout);
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	int Q; cin >> Q;
	int s = 1;
	for (int i = 0; i < Q; i++) {
		char c;
		int n;
		cin >> c >> n;
		if (c == 'B') {
			if (n == -1) continue;
			n--;
			nodes[n].push_back(s);
			nodes[s].push_back(n);
			s++;
		}
		else {
			cout << getDist(n - 1) << endl;
		}
	}
	return 0;

}
/*
Bad Possible Errors:
Rounding
Array Bounds
Overflow
Unallocated Memory

Things to Try:
Test for rounding cases
Check upper bounds
Check for mod overflow
*/