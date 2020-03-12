#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
struct Bird {
	string name;
	float a, b, c, d;
};
float getDist(float a, float b, float c, float d, float aa, float bb, float cc, float dd) {
	return sqrt(pow(a - aa, 2) + pow(b - bb, 2) + pow(c - cc, 2) + pow(d - dd, 2));
}
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int B, N;
		cin >> B >> N;
		vector<Bird> birds(B);
		for (int i = 0; i < B; i++) {
			cin >> birds[i].name >> birds[i].a >> birds[i].b >> birds[i].c >> birds[i].d;
		}

		for (int i = 0; i < N; i++) {
			float a, b, c, d;
			cin >> a >> b >> c >> d;
			vector<pair<float, string>> distances(B);
			for (int q = 0; q < B; q++) {
				distances[q] = make_pair(getDist(a, b, c, d, birds[q].a, birds[q].b, birds[q].c, birds[q].d), birds[q].name);
			}
			sort(distances.begin(), distances.end());
			map<string, int> ans;
			bool isTie = false;
			int cccc = 5;
			for (int q = 0; q < 5; q++) {
				ans[distances[q].second]++;
			}
			//check
			{
				int aaa = ans["Accipitridae"];
				int bbb = ans["Cathartidae"];
				int ccc = ans["Passeridae"];
				int arrr[3] = { aaa, bbb, ccc };
				sort(arrr, arrr + 3);
				if (aaa == bbb || bbb == ccc || aaa == ccc) {
					isTie = true;
				}
			}
			while (isTie) {
				isTie = false;
				ans[distances[cccc].second]++;
				cccc++;
				//check
				int aaa = ans["Accipitridae"];
				int bbb = ans["Cathartidae"];
				int ccc = ans["Passeridae"];
				int arrr[3] = { aaa, bbb, ccc };
				sort(arrr, arrr + 3);
				if (arrr[0] == arrr[1]) isTie = true;
			}

			int aaa = ans["Accipitridae"];
			int bbb = ans["Cathartidae"];
			int ccc = ans["Passeridae"];
			if (aaa > bbb && aaa > ccc) {
				cout << "Accipitridae" << endl;
			}
			if (bbb > aaa && bbb > ccc) {
				cout << "Cathartidae" << endl;
			}
			if (ccc > bbb && ccc > aaa) {
				cout << "Passeridae" << endl;
			}
		}
	}
	return 0;
}