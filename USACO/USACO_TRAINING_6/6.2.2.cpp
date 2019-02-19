/*
ID: mckibbe1
TASK: packrec
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define NONE 0
#define TURN 1
#define MAXN 4
#define BIG 10000
using namespace std;
struct Rect {
	int h, w, id;
	void place(int lower, int upper, int dir, int s);
};
struct Point {
	bool ur;
	int x, y, id;
};
Rect arr[MAXN];
bool inSet[MAXN];
int vals[MAXN];
//#####
int pCounter = 0;
Point pointSet[MAXN * 2];
void Rect::place(int lower, int upper, int dir, int s) {
	//cout << lower << ' ' << upper << ' ' << w << ' ' << h << endl;
	Point l, u;
	l.x = lower; l.y = upper;
	if (dir == NONE) {
		u.x = l.x + w; u.y = l.y + h;
	}
	else if (dir == TURN) {
		u.x = l.x + h; u.y = l.y + w;
	}
	else assert(false);
	l.ur = false;
	u.ur = true;
	pointSet[pCounter] = l;
	pCounter++;
	pointSet[pCounter] = u;
	pCounter++;
}
list<pair<int, int>> availPoints[MAXN * 2];
bool rYSort(Point a, Point b) {
	return a.y > b.y;
}
void updatePoints(int s) {
	availPoints[s].clear();
	int topY = BIG;
	int baseX = 0;
	while (true) {
		//cout << "START" << endl;
		int m = 0, mx = baseX, c = -1;
		//cout << "MAXES " << topY << ' ' << baseX << endl;
		for (int i = 0; i < pCounter; i++) {
			Point curr(pointSet[i]);
			//cout << "\tcurr: " << curr.x << ' ' << curr.y << endl;
			if (curr.ur) {
				if (curr.x > baseX) {
					if (curr.y > m && curr.y < topY) {
						m = curr.y;
						c = i;
						mx = curr.x;
					}
					else if (curr.y == m && curr.y < topY && curr.x > mx) {
						mx = curr.x;
						c = i;
					}
				}
			}
		}
		//cout << "CUIRR " << mx << ' ' << m << endl;
		if (c == -1) {
			//cout << "ENDING" << endl;
			availPoints[s].push_back(make_pair(baseX, 0));
			//cout << baseX << ' ' << 0 << endl;
			break;
		}
		else {
			availPoints[s].push_back(make_pair(baseX, m));

			//cout << baseX << ' ' << m << endl;
			topY = m;
			baseX = mx;
		}
	}
}
int maxArea = BIG * BIG;
vector<pair<int, int>> rects;
void getArea() {
	int l = BIG, r = -1, u = -1, d = BIG;
	for (int i = 0; i < MAXN * 2; i++) {
		Point curr(pointSet[i]);
		r = max(r, curr.x);
		u = max(u, curr.y);
		l = min(l, curr.x);
		d = min(d, curr.y);
	}
	int a = min(u - d, r - l);
	int b = max(u - d, r - l);
	int aa = a * b;
	if (aa < maxArea) {
		maxArea = aa;
		//cout << "CALLED " << maxArea << endl;
		//for (int i = 0; i < 8; i++) {
		//	cout << pointSet[i].x << ' ' << pointSet[i].y << endl;
		//}
		//cout << endl << endl << endl << endl;
		rects.clear();
		rects.push_back(make_pair(a, b));
	}
	else if (aa == maxArea) {
		rects.push_back(make_pair(a, b));
	}
}
void eval(int s) {
	if (s == MAXN) {
		getArea();
		return;
	}
	else {
		if (s != 0) {
			updatePoints(s);
		}
		for (auto i : availPoints[s]) {
			//try 
			arr[vals[s]].place(i.first, i.second, NONE, s);
			eval(s + 1);
			pCounter -= 2;
			arr[vals[s]].place(i.first, i.second, TURN, s);
			eval(s + 1);
			pCounter -= 2;
		}
	}
}
//#####
void dfs(int s) {
	if (s == MAXN) {
		eval(0);
		return;
	}
	else {
		for (int i = 0; i < MAXN; i++) {
			if (inSet[i]) continue;
			inSet[i] = true;
			vals[s] = i;
			dfs(s + 1);
			inSet[i] = false;

		}
	}
}
int main() {
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	for (int i = 0; i < MAXN; i++) {
		inSet[i] = false;
		arr[i].id = i;
		cin >> arr[i].w >> arr[i].h;
	}
	availPoints[0].push_back(make_pair(0, 0));
	dfs(0);
	//arr[0].place(0, 0, NONE, 0);
	//arr[1].place(0, 2, TURN, 1);
	//arr[2].place(0, 4, NONE, 2);
	//updatePoints(3);
	//for (auto i : availPoints[3]) {
	//	cout << '\t' << i.first << ' ' << i.second << endl;
	//}
	cout /*<< "FINAL: "*/ << maxArea << endl;
	sort(rects.begin(), rects.end());
	int a = -1, b = -1;
	for (int i = 0; i < rects.size(); i++) {
		if (rects[i].first == a && rects[i].second == b) continue;
		a = rects[i].first;
		b = rects[i].second;
		cout << rects[i].first << ' ' << rects[i].second << endl;
	}
	return 0;
}