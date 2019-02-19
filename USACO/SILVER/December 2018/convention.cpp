/*
ID: meeperbunny
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define MAXN 100001
using namespace std;
struct Node {
	list<pair<int, int>> adj;
};
int N;
vector<Node> nodes;
int distanceTo(int start, int end) {
	int dist[MAXN], parent[MAXN];
	bool visited[MAXN];
	priority_queue<pair<int, int>> queue;
	for (int i = 0; i < N; i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
		parent[i] = -1;
	}
	distance[start] = 0;
	parent[start] = -1;
	queue.push(make_pair(0, start));
	int nodesVisited = 0;
	while (nodesVisited < N) {
		pair<int, int> curr = queue.top();
		queue.pop();
		visited[curr.second] = true;
		for (auto i : nodes[curr.second].adj) {
			if (curr.first + i.first) {
				;; zcx
			}
		}
	}
}
int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		for (int q = 0; q <= K; q++) {
			dp[i][q] = 0;
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int q = 0; q <= K; q++) {

		}
	}

}