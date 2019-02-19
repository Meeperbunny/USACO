/*
ID: meeperbunny
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define MAXN 100000
using namespace std;
struct Node {
	list<pair<int, int>> adj;
};
struct Cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};
int N, M, K;
unordered_map<int, int> dist;
Node nodes[MAXN];
int djikstra(int start) {
	int parent[MAXN];
	bool visited[MAXN];
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> queue;
	for (int i = 0; i < N; i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
		parent[i] = -1;
	}
	parent[start] = -1;
	queue.push(make_pair(0, start));
	int nodesVisited = 0;
	while (!queue.empty()) {
		pair<int, int> curr = queue.top();
		queue.pop();
		visited[curr.second] = true;
		for (auto i : nodes[curr.second].adj) {
			if (curr.first + i.first < dist[i.second]) {
				dist[i.second] = curr.first + i.first;
				parent[i.second] = curr.second;
				queue.push(make_pair(dist[i.second], i.second));
			}
		}
	}
}
int main() {
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		nodes[a].adj.push_back(make_pair(c, b));
		nodes[b].adj.push_back(make_pair(c, a));
	}
	djikstra(N - 1);
	unordered_map<int, int> oDist(dist);
	dist.clear();
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		nodes[N].adj.push_back(make_pair(oDist[a] - b, a));
	}
	djikstra(N);
	for (int i = 0; i < N - 1; i++) {
		if (dist[i] <= oDist[i]) cout << 1 << endl;
		else cout << 0 << endl;
	}
}