/*
ID: mckibbe1
TASK: fence8
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
typedef long long ll;
using namespace std;
list<int> adj[100000], friends[100000];
struct Cmp {
	bool operator()(pair<int, bool> a, pair<int, bool> b) {
		return a.second < b.second;
	}
};
bool isGood(int start) {
	unordered_set<int> seen;
	priority_queue<pair<int, bool>, vector<pair<int, bool>>, Cmp> Q;
	Q.push(make_pair(start, (int)friends[start].size() > 0));
	seen.insert(start);
	while (!Q.empty()) {
		int curr = Q.top().first; Q.pop();
		//cout << curr << endl;
		for (auto q : friends[curr]) {
			//cout << "AA " << q << endl;
			if (seen.find(q) == seen.end()) return false;
		}
		for (auto q : adj[curr]) {
			if (seen.find(q) != seen.end()) continue;
			seen.insert(q);
			Q.push(make_pair(q, (int)friends[q].size() > 0));
		}
	}
	return true;
}
int main() {
	freopen("gathering.in", "r", stdin);
	freopen("gathering.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int N, K; cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		friends[a].push_back(b);
	}
	for (int i = 0; i < N; i++) {
		cout << isGood(i) << endl;
	}
	return 0;
}