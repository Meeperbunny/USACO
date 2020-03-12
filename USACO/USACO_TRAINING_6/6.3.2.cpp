/*
ID: mckibbe1
TASK: cryptcow
LANG: C++11
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define FIN 47
typedef long long ll;
using namespace std;
char OO[100], TT[100], TH[100], FO[100], s[100], comp[100], subGet[100], ans[100] = "Begin the Escape execution at the Break of Dawn";
int counts[200];
int cCount = 0, oCount = 0, wCount = 0, len = 0, i = 0;
int ssss = 0, j = 0;
bool works = true, found = false;
unordered_map<char*, int> checker;
char *augment(char* base, int a, int b, int c) {
	//cout << "AUGMENTING " << base << ' ' << a << ' ' << b << ' ' << c << endl;
	ssss = 0;
	for (i = 0; i < a; i++) subGet[ssss] = base[i], ssss++;
	for (i = b + 1; i < c; i++) subGet[ssss] = base[i], ssss++;
	for (i = a + 1; i < b; i++) subGet[ssss] = base[i], ssss++;
	for (i = c + 1; i < len; i++) subGet[ssss] = base[i], ssss++;
	//cout << "REAL " << subGet << endl;
	return subGet;
}
bool isEq(char* a) {
	//cout << a << ' ' << ans << endl;
	for (i = 0; i < 47; i++) {
		//cout << a[i] << ' ';
		if (a[i] != ans[i]) {
			//cout << "NO BUENPO" << endl;
			return false;
		}
	}
	return true;
}
void ccc() {
	for (i = 0; i < 75; i++) comp[i] = '\0';
}
void dfs(char* curr, int size) {
	//cout << "START " << curr << ' ' << size << endl;
	if (size <= 48) {
		//cout << "FOUND" << endl;
		found = true;
	}
	if (found) return;
	int compCount = 0, cc = 0, oo = 0, ww = 0;
	int cArr[20], oArr[20], wArr[20];
	memset(comp, 0, sizeof(comp));
	//cout << "C " << curr << endl;
	for (i = size - 1; i >= 0; i--) {
		if (curr[i] == 'W') {
			for (int q = size - 1, j = 46; q > i + 1; q--, j--) {
				//cout << "A " <<  curr[q - 1] << ' ' << ans[j] << endl;
				if (curr[q - 1] != ans[j]) return;
			}
			break;
		}
	}
	for (i = 0; i < size; i++) {
		if (curr[i] == 'C' || curr[i] == 'O' || curr[i] == 'W') {
			if (curr[i] == 'C') {
				if (cc == 0) {
					for (j = 0; j < i; j++) if (curr[j] != ans[j]) {
						//cout << "INVALID START" << endl;
						return;
					}
				}
				cArr[cc] = i;
				cc++;
			}
			else if (curr[i] == 'O') {
				oArr[oo] = i;
				oo++;
			}
			else if (curr[i] == 'W') {
				wArr[ww] = i;
				ww++;
			}
			if (compCount != 0 && strstr(ans, comp) == NULL) {
				//cout << "INVAID SUB" << endl;
				//cout << comp << endl;
				return;
			}
			//cout << "C " << comp << endl;
			memset(comp, 0, sizeof(comp));
			//cout << "C " << comp << endl;
			//cout << "PRINTING " << comp << endl;
			compCount = 0;
		}
		else {
			comp[compCount] = curr[i];
			compCount++;
		}
	}

	//for (int a = 0; a < cc; a++) cout << cArr[a] << ' ';
	//cout << endl;
	//for (int b = 0; b < oo; b++) cout << oArr[b] << ' ';
	//cout << endl;
	//for (int c = ww - 1; c >= 0; c--) cout << wArr[c] << ' ';
	//cout << endl;

	//cout << cc << ' ' << oo << ' ' << ww << endl;
	if (checker[curr] >= 10000) return;
	else checker[curr]++;
	for (int a = 0; a < cc; a++) {
		for (int c = ww - 1; c >= 0; c--) {
			for (int b = 0; b < oo; b++) {
				if (found) return;
				if (cArr[a] > oArr[b] || oArr[b] > wArr[c]) continue;
				//cout << cArr[a] << ' ' << oArr[b] << ' ' << wArr[c] << endl;
				char *filler = augment(curr, cArr[a], oArr[b], wArr[c]);
				char temp[75];
				memset(temp, 0, sizeof(filler));
				strncpy(temp, filler, sizeof(temp));
				dfs(temp, size - 3);
			}
		}
	}

}
int main() {
	freopen("cryptcow.in", "r", stdin);
	freopen("cryptcow.out", "w", stdout);
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	memset(s, 0, sizeof(s));
	memset(comp, 0, sizeof(comp));
	memset(subGet, 0, sizeof(subGet));
	memset(counts, 0, sizeof(counts));
	fgets(s, 75, stdin);
	len = (int)strlen(s);
	while (s[len - 1] == ' ') len--;
	//cout << s << ' ' << len << ' ' << endl;
	memset(counts, sizeof(counts), 0);
	for (i = 0; i < FIN; i++) counts[ans[i]]++;
	for (i = 0; i < len; i++) {
		counts[s[i]]--;
		if (s[i] == 'C') cCount++;
		else if (s[i] == 'O') oCount++;
		else if (s[i] == 'W') wCount++;
		//else if (counts[s[i]] < 0) works = false;
	}
	if (isEq(s)) {
		cout << 1 << ' ' << 0 << '\n';
		return 0;
	}
	//cout << "AAA" << endl;
	if (!works || cCount != oCount || oCount != wCount) {
		cout << 0 << ' ' << 0 << '\n';
		return 0;
	}
	//cout << "AAA" << endl;
	len = 48 + cCount * 3;
	//char base[20] = "AAAAACBBBBODDDDWLLL";
	//cout << augment(base, 5, 10, 15) << endl;

	dfs(s, len);
	//13 30 39
	if (found) {
		cout << 1 << ' ' << cCount << '\n';
	}
	else {
		cout << 0 << ' ' << 0 << '\n';
	}
	return 0;
}