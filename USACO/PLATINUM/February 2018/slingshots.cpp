/*
ID: mckibbe1
LANG: C++11
TASK: slingshots
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define MAXN 1000000
#define MOD 1000000007
using namespace std;
struct Pile {
	int start, end, baseTime;
	void getTime() {
		baseTime = abs(end - start);
	}
};
struct Shot {
	int start, end, time;
	int getTime(Pile n) {
		return abs(n.start - start) + time + abs(n.end - end);
	}
};
Shot arr[MAXN];
Pile piles[MAXN];
int main() {
	freopen("slingshot.in", "r", stdin);
	freopen("slingshot.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].start >> arr[i].end >> arr[i].time;
	}
	for (int i = 0; i < M; i++) {
		cin >> piles[i].start >> piles[i].end;
		piles[i].getTime();
	}
	for (int i = 0; i < M; i++) {
		for (int q = 0; q < N; q++) {
			//cout << piles[i].baseTime << endl;
			piles[i].baseTime = min(piles[i].baseTime, arr[q].getTime(piles[i]));
		}
		cout << piles[i].baseTime << endl;
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