/*
ID: mckibbe1
TASK: fence8
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define SORTED 0
#define EDGE 1
#define ANALYSIS 2
typedef long long ll;
using namespace std;
int state[100000], arr[100000];
bool checked[100000];
pair<int, int> lArr[100000], rArr[100000];
struct Cmp {
	bool operator()(int a, int b) {
		return arr[a] > arr[b];
	}
};
void print() {
	for (int i = 0; i < 5; i++) cout << rArr[i].first << ' ' << rArr[i].second << "   ";
	cout << endl;
	for (int i = 0; i < 5; i++) cout << lArr[i].first << ' ' << lArr[i].second << "   ";
	cout << endl;
}
int main() {
	//freopen("itout.in", "r", stdin);
	//freopen("itout.out", "w", stdout);
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		lArr[i] = make_pair(arr[i], i);
		rArr[i] = make_pair(arr[i], i);
	}
	memset(state, -1, sizeof(state));
	priority_queue<int, vector<int>, Cmp> Q;
	if (N >= 2 && arr[0] > arr[1]) Q.push(0);
	if (N >= 2 && arr[N - 1] < arr[N - 2]) Q.push(N - 1);
	for (int i = 0; i < N; i++) {
		if (i != 0 && i != 1) {
			if (arr[i - 2] < arr[i] && (arr[i - 2] > arr[i - 1] || arr[i - 1] > arr[i])) {
				state[i - 1] = ANALYSIS;
				Q.push(i - 1);
				cout << i - 1 << endl;
			}
		}
	}
	vector<int> ans;
	rArr[N] = make_pair(10000000, 10000000);
	while (!Q.empty()) {
		int curr = Q.top(); Q.pop();
		if (checked[curr]) continue;
		checked[curr] = true;
		cout << curr << endl;
		print();
		ans.push_back(curr);
		if (lArr[curr].second == 0) {
			//if left edge
			Q.push(rArr[rArr[curr].second + 1].second);
			cout << "LEDGE" << endl;
		}
		if (rArr[rArr[curr].second + 1].second >= N) {
			//if right edge
			Q.push(lArr[lArr[curr].second - 1].second);
			rArr[curr] = make_pair(rArr[curr].first, 99);
			cout << "REDGE" << endl;

		}
		else {
			lArr[curr] = lArr[curr - 1];
			rArr[curr] = rArr[curr + 1];
		}
	
		//if()

	}
	for (int i = 0; i < N; i++) {
		cout << state[i] << ' ';
	}
	return 0;
}