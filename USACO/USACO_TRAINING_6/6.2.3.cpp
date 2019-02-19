/*
ID: mckibbe1
TASK: rect1
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
struct Point {
	int x, y, id;
	bool isLower;
};
bool xSort(Point a, Point b) {
	return a.x < b.x;
}
bool ySort(Point a, Point b) {
	if (a.y == b.y) {
		return a.id < b.id;
	}
	else return a.y < b.y;
}
int total[10001];
unordered_map<int, int> idMap;
int main() {
	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	vector<Point> arr;
	int A, B, N;
	for (int i = 0; i < 10001; i++) total[i] = 0;
	cin >> A >> B >> N;
	Point lower, upper;
	lower.x = 0; lower.y = 0;
	lower.id = 0; lower.isLower = true;
	upper.x = A; upper.y = B;
	upper.id = 0; upper.isLower = false;
	arr.push_back(lower);
	arr.push_back(upper);
	for (int i = 0; i < N; i++) {
		Point a, b;
		cin >> a.x >> a.y >> b.x >> b.y >> a.id;
		a.id--;
		idMap[i + 1] = a.id;
		a.id = i + 1;
		b.id = i + 1;
		a.isLower = true;
		b.isLower = false;
		arr.push_back(a);
		arr.push_back(b);
	}
	vector<Point> ySet(arr);
	sort(arr.begin(), arr.end(), xSort);
	sort(ySet.begin(), ySet.end(), ySort);
	vector<bool> inset(100001, false);
	inset[arr[0].id] = true;
	int area = 0;
	for (int i = 1; i < arr.size(); i++) {
		Point curr = arr[i];
		int yDist = 0;
		int startY = 0;
		int count = 0;
		int deltaX = arr[i].x - arr[i - 1].x;
		if (deltaX == 0) {
			//cout << "DX IS 0" << endl;
			if (arr[i].isLower) inset[arr[i].id] = true;
			else inset[arr[i].id] = false;
			continue;
		}
		//cout << "NEW ITERATION: " << deltaX << endl;
		vector<int> totCount(10001, 0);
		vector<int> start(10001, 0);
		list<int> line;
		for (int q = 0; q < ySet.size(); q++) {
			Point c(ySet[q]);
			if (inset[c.id]) {
				//cout << "\tINSET: ";
				//for (auto i : inset) cout << i << ' ';
				//cout << endl;
				//cout << "\tVERTICALSET: ";
				//for (auto i : line) cout << i << ' ';
				//cout << endl;
				//cout << "\tCURRID: " << c.id << endl;
				if (c.isLower) {
					if (line.size() != 0 && c.id > *line.begin()) {
						//cout << "ADDING FROM LAST " << c.y << ' ' << start[*line.begin()] << endl;
						totCount[*line.begin()] += c.y - start[*line.begin()];
					}
					bool inserted = false;
					for (list<int>::iterator it = line.begin(); it != line.end(); it++) {
						if (c.id > *it) {
							line.insert(it, c.id);
							inserted = true;
							break;
						}
					}
					if (!inserted) {
						if (line.size() == 0) line.insert(line.begin(), c.id);
						else line.insert(line.end()--, c.id);
					}
					start[c.id] = c.y;
					//cout << c.id << " START AT " << c.y << endl;
					if (count == 0) {
						//cout << "\tSTARTY AT ID: : " << c.id << endl;
						startY = c.y;
					}
					count++;
				}
				else {
					count--;
					bool wasTop = false;
					//cout << c.id << " ENDY AT " << c.y << endl;
					for (list<int>::iterator it = line.begin(); it != line.end(); it++) {
						if (*it == c.id) {
							if (*line.begin() == c.id) {
								//cout << "ADDING END " << c.y << ' ' << start[c.id] << endl;
								totCount[c.id] += c.y - start[c.id];
								wasTop = true;
							}
							line.erase(it);
							break;
						}
					}
					if (wasTop && line.size() != 0) start[*line.begin()] = c.y;
					if (count == 0) {
						yDist += c.y - startY;
					}
				}
			}

		}
		//cout << "##### COUNT #####" << endl;
		for (int i = 0; i < 10001; i++) {
			//cout << totCount[i] << ' ';
		} //cout << endl;
		for (int i = 0; i < 10001; i++) {
			//cout << "\tADDING TO " << i << ' ' << totCount[i] * deltaX << endl;
			total[i] += totCount[i] * deltaX;
		} //cout << endl;
		  //cout << "\t\tDX: " << deltaX << ' ' << "DY: " << yDist << endl;
		area += yDist * deltaX;
		if (arr[i].isLower) inset[arr[i].id] = true;
		else inset[arr[i].id] = false;
	}
	vector<int> final(100001, 0);
	for (int i = 0; i < 10001; i++) {
		final[idMap[i]] += total[i];
	}
	for (int i = 0; i < 10001; i++) {
		if (final[i] == 0) continue;
		cout << i + 1 << ' ' << final[i] << endl;
	}
	return 0;
}