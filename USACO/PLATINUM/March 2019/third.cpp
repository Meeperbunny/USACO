#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define MAXN 750
using namespace std;
int N, M;
int sizeArr[MAXN * MAXN];
int arr[MAXN * MAXN];
int surr[MAXN * MAXN], opNum[MAXN], sumInstance[MAXN * MAXN];
bool isOut[MAXN][MAXN], inGroup[MAXN][MAXN], checked[MAXN][MAXN], finished[MAXN][MAXN], buildInside[MAXN * MAXN], inRev[MAXN][MAXN];

bool print = true;

pair<int, int> sizes[MAXN * MAXN];
unordered_set<int> inSet;

int toNum(int y, int x) {
	return y * N + x;
}

void remRev(int takeY, int takeX) {
	if (inRev[takeY][takeX]) {
		for (int y = takeY - 1; y <= takeY + 1; y++) {
			for (int x = takeX - 1; x <= takeX + 1; x++) {
				if (x < 0 || x >= N || y < 0 || y >= N) {
					continue;
				}
				if (y == takeY && x == takeX) inRev[y][x] = false, isOut[y][x] = false, finished[y][x] = true;
				else {
					remRev(y, x);
				}
			}
		}
	}
	else {
		isOut[takeY][takeX] = true;
	}
}

template<int SZ> struct DSU {
	int par[SZ], sz[SZ], rc[SZ];
	vector<pair<int, int>> stor;

	DSU() {
		for (int i = 0; i < SZ; i++) par[i] = i, sz[i] = 1;
	}

	int get(int x) { // no path compression
		if (x == par[x]) return x;
		return get(par[x]);
	}

	void unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y);
		if (x == y) { stor.push_back({ -1,-1 }); return; }
		if (sz[x] < sz[y]) swap(x, y);
		stor.push_back({ x,y });	sz[x] += sz[y], par[y] = x, rc[x] += rc[y];
	}

	void rollback(int& take) { // delete last edge added
		auto a = stor.back(); stor.pop_back();
		int x = a.first, y = a.second;
		if (take == -1) take = y;
		if (x == -1) return;
		sz[x] -= sz[y]; par[y] = y;
	}
};

DSU<MAXN * MAXN> D, R;

void printInfo() {
	if (!print) return;
	//for (int q = 0; q < N; q++) {
	//	for (int n = 0; n < N; n++) {
	//		cout << inGroup[q][n] << ' ';
	//	}
	//	cout << endl;
	//}	
	for (int q = 0; q < N; q++) {
		for (int n = 0; n < N; n++) {
			cout << isOut[q][n] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int q = 0; q < N; q++) {
		for (int n = 0; n < N; n++) {
			cout << inRev[q][n] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	//for (int q = 0; q < N; q++) {
	//	for (int n = 0; n < N; n++) {
	//		cout << surr[q * N + n] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//for (int q = 0; q < N; q++) {
	//	for (int n = 0; n < N; n++) {
	//		cout << D.get(q * N + n) << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	for (int i = 0; i < N * N; i++) cout << D.sz[i] << ' ';
	cout << endl << endl;
}

int isHole(int baseId, int start) {
	int currY = start / N;
	int currX = start % N;
	if (checked[currY][currX]) return 0;
	checked[currY][currX] = true;
	int retCount = 1;
	for (int y = currY - 1; y <= currY + 1; y++) {
		for (int x = currX - 1; x <= currX + 1; x++) {
			if (y == currY && x == currX) continue;
			if (x < 0 || x >= N) continue;
			if (y < 0 || y >= N) continue;
			if (D.get(toNum(y, x)) == baseId) continue;
			retCount += isHole(baseId, toNum(y, x));
		}
	}
	return retCount;
}

bool checkIfSurrounded(int addY, int addX) {
	int firstId = -1;
	for (int y = addY - 1; y <= addY + 1; y++) {
		for (int x = addX - 1; x <= addX + 1; x++) {
			if (y == addY && x == addX) continue;
			if (x < 0 || x >= N || y < 0 || y >= N) {
				return false;
			}
			int base = D.get(toNum(y, x));
			if (firstId == -1) firstId = base;
			if (firstId != base) return false;
			if (!inGroup[y][x]) return false;
		}
	}
	return true;
}

int main() {
	if (fopen("file.in", "r")) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	else {
		freopen("valleys.in", "r", stdin);
		freopen("valleys.out", "w", stdout);
	}

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> arr[i];
		sizes[i] = make_pair(arr[i], i);
	}
	memset(inGroup, 0, sizeof(inGroup));
	sort(sizes, sizes + N * N);
	int sum = 0;
	vector<int> surrSet;
	for (int i = 0; i < N * N; i++) {
		int addY = sizes[i].second / N;
		int addX = sizes[i].second % N;
		inGroup[addY][addX] = true;

		//check if two are adjacent, if they are, merge:

		opNum[i] = 0;

		//up
		if (addY > 0 && inGroup[addY - 1][addX]) {
			D.unite(toNum(addY, addX), toNum(addY - 1, addX));
			opNum[i]++;
		}
		//right
		if (addX < N - 1 && inGroup[addY][addX + 1]) {
			D.unite(toNum(addY, addX), toNum(addY, addX + 1));
			opNum[i]++;
		}
		//left
		if (addX > 0 && inGroup[addY][addX - 1]) {
			D.unite(toNum(addY, addX), toNum(addY, addX - 1));
			opNum[i]++;
		}
		//down
		if (addY < N - 1 && inGroup[addY + 1][addX]) {
			D.unite(toNum(addY, addX), toNum(addY + 1, addX));
			opNum[i]++;
		}
		int id = D.get(toNum(addY, addX));

		//add to closureSet if surrounded
		bool isSurrouded = checkIfSurrounded(addY, addX);
		surr[toNum(addY, addX)] = isSurrouded;

		if (isSurrouded) {
			surrSet.push_back(i);
			buildInside[i] = true;
			if (print) cout << "ADDDDDDDDDDDDDDDDDING" << i << endl;
		}
		if (print) cout << "CHECKING " << isSurrouded << endl;

		printInfo();

		sumInstance[i] = D.sz[id];

		if (D.sz[id] == N * N) {
			if (print) cout << "REACHED END $$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
			if (print) cout << sum + N * N << endl;
			if (print) cout << "SUR SET ";
			if (print) for (int q = 0; q < surrSet.size(); q++) cout << surrSet[q] << ' ';
			if (print) cout << endl;

			printInfo();

			//Set the outside blocks

			for (int q = 0; q < N; q++) {
				isOut[0][q] = true;
				isOut[q][0] = true;
				isOut[N - q - 1][N - 1] = true;
				isOut[N - 1][N - q - 1] = true;
			}
			int rollingCounter = 0;
			for (int counter = N * N - 1; counter >= 0; counter--) {
				if (print) cout << "ROLLING " << counter << ' ' << opNum[counter] << ' ' << rollingCounter << endl;
				int takeAway = sizes[counter].second;
				for (int q = 0; q < opNum[counter]; q++)
					D.rollback(takeAway);

				int takeY = takeAway / N;
				int takeX = takeAway % N;


				if (buildInside[counter]) {
					inRev[takeY][takeX] = true;
					rollingCounter++;
					printInfo();
					D.rc[D.get(takeAway)]++;
					continue;
				}

				//have order, now just need to get:
				//	* outside propogation,
				//	inside merge
				//	outside-inside collision
				if (isOut[takeY][takeX]) {
					for (int y = takeY - 1; y <= takeY + 1; y++) {
						for (int x = takeX - 1; x <= takeX + 1; x++) {
							if (x < 0 || x >= N || y < 0 || y >= N) {
								continue;
							}
							if (y == takeY && x == takeX) isOut[y][x] = false, finished[y][x] = true;
							else if (!finished[y][x]) {
								//edge propogation
								isOut[y][x] = true;
							}
							//check if is in union, if it is, clear all members and take away size from rollingCounter
							if (inRev[y][x]) {
								int removeSize = R.sz[R.get(y * N + x)];
								remRev(y, x);
								if (print) cout << "REMOVING SIZE " << removeSize << endl;
								D.rc[D.get(takeAway)] = 0;
							}
						}
					}
				}
				else {
					//check if neighbors are in union, if they are, merge and add to rollingSum
					bool added = false;
					if (takeY > 0 && inRev[takeY - 1][takeX])
						R.unite(toNum(takeY, takeX), toNum(takeY - 1, takeX)), inRev[takeY][takeX] = true, added = true;
					//right
					if (takeX < N - 1 && inRev[takeY][takeX + 1])
						R.unite(toNum(takeY, takeX), toNum(takeY, takeX + 1)), inRev[takeY][takeX] = true, added = true;
					//left
					if (takeX > 0 && inRev[takeY][takeX - 1])
						R.unite(toNum(takeY, takeX), toNum(takeY, takeX - 1)), inRev[takeY][takeX] = true, added = true;
					//down
					if (takeY < N - 1 && inRev[takeY + 1][takeX])
						R.unite(toNum(takeY, takeX), toNum(takeY + 1, takeX)), inRev[takeY][takeX] = true, added = true;
					if (added) D.rc[D.get(takeAway)]++;
				}

				if (D.rc[D.get(takeAway)] <= 0) sum += sumInstance[counter];// , cout << "ADDING " << sumInstance[counter] << endl;;


				printInfo();


			}
			cout << sum << endl;

			return 0;
		}

		//## Print ##


	}
	return 0;
}