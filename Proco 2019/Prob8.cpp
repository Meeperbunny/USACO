/*
ID: mckibbe1
LANG: C++11
TASK: slingshots
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define MAXN 100000
#define MOD 1000000007
using namespace std;
int N;
/*
ID: mckibbe1
TASK: money
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 30
using namespace std;
struct Segtree {
private:
	int minTree[MAXN * 2];
	int size;
	void constructRecur(int arr[], int c, int s, int e) {
		if (s > e) return;
		if (s == e) {
			minTree[c] = arr[s];
			return;
		}
		int mid = (s + e) / 2;
		constructRecur(arr, c * 2 + 1, s, mid);
		constructRecur(arr, c * 2 + 2, mid + 1, e);
		minTree[c] = (minTree[c * 2 + 1] + minTree[c * 2 + 2]);
		return;
	}
	int sumQueryRecur(int c, int s, int e, int qs, int qe) {
		if (s > e || s > qe || e < qs) {
			return 0;
		}
		if (s >= qs && e <= qe) {
			return minTree[c];
		}
		int mid = (s + e) / 2;
		int left = sumQueryRecur(c * 2 + 1, s, mid, qs, qe);
		int right = sumQueryRecur(c * 2 + 2, mid + 1, e, qs, qe);
		return (left + right);
	}
public:
	void Init(int arr[], int _size) {
		size = _size;
		for (int i = 0; i < size * 2; i++) minTree[i] = INT_MAX;
		constructRecur(arr, 0, 0, size - 1);
	}
	int GetSum(int s, int e) {
		return sumQueryRecur(0, 0, size - 1, s, e);
	}
};
int arr[100000];
int dp[100000][101];
int main() {
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	int N, K; cin >> N >> K;
	Segtree S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	S.Init(arr, N);
	cout << S.GetSum(0, 2) << endl;
	for (int i = 0; i < 100000; i++) {
		for (int k = 0; k <= K; k++) {
			if (k > 0) {
				dp[i][k] = min(, ());
			}
		}
	}




	return 0;
}
