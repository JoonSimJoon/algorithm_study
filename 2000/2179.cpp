#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct s {
	string str;
	int key;
};

vector<s> v;
int N, cnt = -1, res;
s ans1, ans2, tmp;
int cp(s a, s b) {
	if (a.str.compare(b.str) > 0) return 0;
	else return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp.str;
		tmp.key = i;
		v.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			res = 0;
			int sl = v[i].str.length();
			for (int k = 0; k < sl; k++) {
				if (v[i].str[k] == v[j].str[k]) res++;
				else break;
			}
			if (res > cnt) {
				ans1 = v[i];
				ans2 = v[j];
				cnt = res;
			}
		}
	}
	/*sort(v.begin(), v.end(), cp);
	for (int i = 0; i < N - 1; i++) {
		res = 0;
		int sl = v[i].str.length();
		for (int j = 0; j < sl; j++) {
			if (v[i].str[j] == v[i + 1].str[j]) res++;
			else break;
		}
		if (res > cnt) {
			ans1 = v[i];
			ans2 = v[i + 1];
			cnt = res;
		}
		else if (res == cnt) {
			if (ans1.key < v[i].key) {
				ans1 = v[i];
				ans2 = v[i + 1];
			}
		}
	}*/
	cout << ans1.str << "\n" << ans2.str;
	return 0;
}