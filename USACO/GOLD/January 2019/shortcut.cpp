/*
ID: mckibbe1
TASK: rect1
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 20000
using namespace std;
struct Node {
	long long id;
	list<pair<long long, long long>> adj;
};
struct Cmp {
	bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};
Node arr[MAXN];
long long N, M, T, done[MAXN], base[MAXN], dist[MAXN], parent[MAXN], visited[MAXN];
list<long long> goTo[MAXN];
void djikstra(long long start) {
	for (long long i = 0; i < N; i++) {
		dist[i] = 100000000000;
		visited[i] = false;
		done[i] = false;
		parent[i] = -1;
	}
	dist[start] = 0;
	long long nodesVisited = 1;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, Cmp> q;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		pair<long long, long long> curr = q.top();
		//cout << curr.second << endl;
		q.pop();
		nodesVisited++;
		visited[curr.second] = true;
		for (auto i : arr[curr.second].adj) {
			//cout << "checking " << i.second << endl;
			if (dist[curr.second] + i.first < dist[i.second] ||
				(dist[curr.second] + i.first == dist[i.second] && parent[i.second] > curr.second)) {
				//cout << "UPDATING " << i.second << ' ' << curr.second << endl;
				dist[i.second] = dist[curr.second] + i.first;
				parent[i.second] = curr.second;
				q.push(make_pair(dist[i.second], i.second));
			}
		}
	}
}
int addSum(int c) {
	if (done[c]) return 0;
	done[c] = true;
	//cout << c << ' ' << base[c] << endl;
	if (goTo[c].size() == 0) {
		//cout << "ISEND" << endl;
		return base[c];
	}
	else {
		int total = 0;
		for (auto i : goTo[c]) {
			total += addSum(i);
		}
		//cout << "FINAL " << c << ' ' << base[c] + total << endl;
		base[c] += total;
		return base[c];
	}
	return 0;
}
int main() {
	freopen("shortcut.in", "r", stdin);
	freopen("shortcut.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	cin >> N >> M >> T;
	for (long long i = 0; i < N; i++) cin >> base[i];
	for (long long i = 0; i < M; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a].adj.push_back(make_pair(c, b));
		arr[b].adj.push_back(make_pair(c, a));
	}
	djikstra(0);
	for (long long i = 0; i < N; i++) {
		if (parent[i] != -1) {
			goTo[parent[i]].push_back(i);
		}
	}
	queue<long long> q;
	for (long long i = 0; i < N; i++) {
		if (goTo[i].size() == 0) {
			q.push(i);
			//cout << "QUEUE: " << i << endl;
		}
	}
	/*while (!q.empty()) {
	long long curr = q.front(); q.pop();
	if (done[curr]) continue;
	cout << curr << endl;
	done[curr] = true;
	if (parent[curr] == -1) continue;
	base[parent[curr]] += base[curr];
	cout << "ADDING " << base[curr] << " TO " << parent[curr] << endl;
	q.push(parent[curr]);
	}*/
	addSum(0);
	for (long long i = 0; i < N; i++) {
		//cout << "B " << base[i] << endl;
	}
	long long mostSaved = 0;
	for (long long i = 0; i < N; i++) {
		//cout << i << ' ' << (base[i] * dist[i]) << ' ' << (base[i] * T) << endl;
		long long saved = (base[i] * dist[i]) - (base[i] * T);
		if (mostSaved < saved) {
			//cout << i << endl;
			mostSaved = saved;
		}
	}
	cout << mostSaved << endl;
	return 0;
}