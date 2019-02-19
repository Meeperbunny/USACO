/*
ID: meeperbunny
LANG: C++11
TASK: task
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int N;
struct Cow {
	bool gone = false;
	int seniority;
	int start, duration, endTime;
};
bool comp(Cow a, Cow b) {
	return a.start < b.start;
}
struct Cmp {
	bool operator()(Cow a, Cow b) {
		return a.seniority > b.seniority;
	}
};
int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	cin >> N;
	vector<Cow> arr(N);
	for (int i = 0; i < N; i++) {
		arr[i].seniority = i;
		cin >> arr[i].start >> arr[i].duration;
		arr[i].endTime = arr[i].start + arr[i].duration;
	}
	sort(arr.begin(), arr.end(), comp);
	priority_queue<Cow, vector<Cow>, Cmp> waiting;

	vector<bool> checked(N, false);
	int currTime = 0;
	int wait = 0;
	int i = 0;
	while (true) {
		while (i < N && arr[i].start <= currTime) {
			//cout << "i " << i << endl;
			waiting.push(arr[i]);
			i++;
		}
		//cout << currTime << endl;
		if (i >= N && waiting.size() == 0) break;
		Cow curr;
		if (waiting.size() == 0) {
			curr = arr[i];
			i++;
		}
		else {
			curr = waiting.top();
			waiting.pop();
		}
		//cout << curr.start << ' ' << curr.endTime << endl;
		if (currTime > curr.start) {
			int diff = currTime - curr.start;
			wait = max(wait, diff);
			currTime = curr.endTime + diff;
		}
		else {
			currTime = curr.endTime;
		}
	}
	cout << wait << endl;
}