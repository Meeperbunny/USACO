/*
ID: meeperbunny
LANG: C++11
TASK: vans
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct big_num {
	vector<int> num;
	void init_val(int startVal) {
		if (startVal == 0) {
			num.push_back(0);
			return;
		}
		else if (startVal == 1) {
			num.push_back(1);
			return;
		}
		int multi = 10;
		while (startVal % multi != startVal) {
			num.push_back(floor((startVal % multi) / (multi / 10)));
			multi *= 10;
		}
		num.push_back(floor((startVal % multi) / (multi / 10)));
	}
	void add(big_num n) {
		int i = 0;
		while (i != n.num.size()) {
			if (i >= num.size()) {
				num.push_back(n.num[i]);
				i++;
				continue;
			}
			int total = n.num[i] + num[i];
			num[i] = total % 10;
			if (total >= 10) {
				if (i == num.size() - 1) {
					num.push_back(1);
				}
				else {
					num[i + 1] += 1;
				}
			}
			i++;
		}
	}
	void print() {
		if (num.size() == 1) {
			cout << num[0] << endl;
			return;
		}
		string printString;
		bool numFound = false;
		for (int i = num.size() - 1; i >= 0; i--) {
			if (num[i] != 0) numFound = true;
			if (numFound) {
				printString.append(to_string(num[i]));
			}
		}
		cout << printString << endl;//59_532224
	}
};
big_num dp[1001][7];
int main() {
	freopen("vans.in", "r", stdin);
	freopen("vans.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int N; cin >> N;
	for (int i = 0; i < 1001; i++)
		for (int q = 0; q < 7; q++) {
			big_num b;
			b.init_val(0);
			dp[i][q] = b;
		}
	big_num one;
	one.init_val(1);
	dp[1][0].add(one);
	dp[1][3].add(one);
	for (int i = 1; i < N; i++) {
		dp[i + 1][0].add(dp[i][0]);
		dp[i + 1][1].add(dp[i][1]); dp[i + 1][1].add(dp[i][4]); dp[i + 1][1].add(dp[i][6]);
		dp[i + 1][2].add(dp[i][2]); dp[i + 1][2].add(dp[i][3]);
		dp[i + 1][3].add(dp[i][0]); dp[i + 1][3].add(dp[i][1]); dp[i + 1][3].add(dp[i][4]); dp[i + 1][3].add(dp[i][5]); dp[i + 1][3].add(dp[i][6]);
		dp[i + 1][4].add(dp[i][2]); dp[i + 1][4].add(dp[i][3]);
		dp[i + 1][5].add(dp[i][3]);
		dp[i + 1][6].add(dp[i][2]); dp[i + 1][6].add(dp[i][3]);
	}
	big_num ans;
	ans.init_val(0);
	ans.add(dp[N - 1][2]);
	ans.add(dp[N - 1][3]);
	ans.add(ans);
	ans.print();
	return 0;
}