#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define MAXN 100000
long N;
int wantToBe[1000];
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < 1000; i++) wantToBe[i] = -1;
	string a, b;
	cin >> a >> b;
	int c = 0;
	for (int i = 0; i < N; i++) {
		//cout << a[i] << "   " << b[i] << endl;
		/*if (a[i] != b[i])*/ {
			if (a[i] == b[i]) { //changing to same letter
				if (wantToBe[a[i]] == -1) { //new
					wantToBe[a[i]] = b[i];
					//cout << "**";
				}
				else if (wantToBe[a[i]] != b[i]) { //changing to diff, con
												   //cout << "AAA" << endl;
					cout << -1 << endl;
					return 0;
				}
			}
			else { //changing to diff
				   //cout << a[i] << ' ' << b[i] << endl;
				if (wantToBe[a[i]] == -1) { //new
					wantToBe[a[i]] = b[i];
					//cout << "**";
					c++;
				}
				else if (wantToBe[a[i]] != b[i]) { //changing to diff, con
												   //cout << "AAA" << endl;
					cout << -1 << endl;
					return 0;
				}
			}
			//cout << char(a[i]) <<' ' << char(wantToBe[a[i]]) << endl;
		}
	}
	cout << c << endl;
	return 0;
}