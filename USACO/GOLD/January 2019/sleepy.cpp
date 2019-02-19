/*
ID: mckibbe1
TASK: rect1
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 100000
using namespace std;
void update(int i, int add, vector<int>& BIT)
{
	while (i > 0 && i < BIT.size())
	{
		BIT[i] += add;
		i = i + (i & (-i));
	}
}

/* Returns cumulative sum of all elements of
fenwick tree/BIT from start upto and
including element at index 'i'. */
int sum(int i, vector<int>& BIT)
{
	int ans = 0;
	while (i > 0)
	{
		ans += BIT[i];
		i = i - (i & (-i));
	}

	return ans;
}

// Returns lower bound for k in BIT. 
int findKthSmallest(int k, vector<int> &BIT)
{
	// Do binary search in BIT[] for given 
	// value k. 
	int l = 0;
	int h = BIT.size();
	while (l < h)
	{
		int mid = (l + h) / 2;
		if (k <= sum(mid, BIT))
			h = mid;
		else
			l = mid + 1;
	}

	return l;
}

// Insert x into BIT. We masically increment 
// rank of all elements greater than x. 
void insertElement(int x, vector<int> &BIT)
{
	update(x, 1, BIT);
}

// Delete x from BIT. We masically decreases 
// rank of all elements greater than x. 
void deleteElement(int x, vector<int> &BIT)
{
	update(x, -1, BIT);
}
int findRank(int x, vector<int> &BIT)
{
	return sum(x, BIT);
}
int arr[MAXN];
set<int> l;
int insertIndex;
vector<int> BIT(MAXN * 3);
int main() {
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	if (is_sorted(arr, arr + N)) {
		cout << 0 << endl;
		return 0;
	}
	int lastMax = -1;
	for (int i = N - 1; i > 0; i--) {
		if (arr[i - 1] > arr[i]) {
			//cout << "INSERTED " << arr[i] << endl;
			insertElement(arr[i], BIT);
			lastMax = i;
			break;
		}
		else {
			//cout << "INSERTED " << arr[i] << endl;
			insertElement(arr[i], BIT);
		}
	}
	cout << lastMax << endl;
	for (int i = 0; i < lastMax; i++) {
		//cout << "INSERTED " << arr[i] << endl;
		insertElement(arr[i], BIT);
		//cout << findRank(arr[i], BIT) << ' ';
		cout << lastMax - (i + 1) + findRank(arr[i], BIT) - 1;
		if (i != lastMax - 1) cout << ' ';
		else cout << endl;
	}
	return 0;
}