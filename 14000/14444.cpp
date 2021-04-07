#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int arr[200010];
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	string s2 = "";
	for (int i = 0; i < s.size(); i++) {
		s2 += "_";
		s2 += s[i];
	}
	s2 += "_";
	int sl = s2.size();
	int st = 0, en = 0, res = 0;

	for (int i = 0; i < sl; i++) {
		if (i <= st) arr[i] = min(arr[2 * en - i], st - i);

		while (i - arr[i] - 1 >= 0 && i + arr[i] + 1 < sl && s2[i - arr[i] - 1] == s2[i + arr[i] + 1]) arr[i]++;

		if (i + arr[i] > st) {
			st = i + arr[i];
			en = i;
		}
	}
	for (int i = 0; i < sl; i++) {
		int tmp = res;
		res = max(res, arr[i]);
		if (res > tmp) {
			ans = i - res + 1;
			ans /= 2;
		}
	}
	cout << res << "\n";
	//string ans_s = s.substr(ans, res);
	//cout << ans_s << "\n";
	return 0;
}

//boj 14444