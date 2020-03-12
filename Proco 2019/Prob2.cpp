#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define MAXN 100000
long N;
int arr[1001][1001];
int hold[1001];
void swapRow(int a, int b) {
	for (int i = 0; i < N; i++) swap(arr[i][a], arr[i][b]);
}
//void swapCol(int a, int b) {
//	for (int i = 0; i < N; i++) hold[i] = arr[a][i];
//	for (int i = 0; i < N; i++) arr[a][i] = arr[b][i];
//	for (int i = 0; i < N; i++) arr[b][i] = hold[i];
//}
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int q = 0; q < N; q++) {
			cin >> arr[i][q];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int q = 0; q < N - 1; q++) {
			if (arr[i][q] > arr[i][q + 1]) {
				swapRow(q, q + 1);
			}
			if (arr[q][i] > arr[q + 1][i]) {
				swap(arr[q], arr[q + 1]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int q = 0; q < N; q++) {
			if (q < N - 1 && arr[i][q] > arr[i][q + 1]) {
				cout << 'N' << endl;
				return 0;
			}
			if (i < N - 1 && arr[i][q] > arr[i + 1][q]) {
				cout << 'N' << endl;
				return 0;
			}
		}
	}
	cout << 'Y' << endl;
	return 0;
}