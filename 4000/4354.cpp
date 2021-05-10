#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int fail[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		string s;
		cin >> s;
		if (s == ".") break;
		memset(fail, 0, sizeof(fail));
		int len = s.size();
		for (int i = 1, j = 0; i < len; i++) {
			while (j > 0 && s[i] != s[j]) j = fail[j - 1];
			if (s[i] == s[j]) fail[i] = ++j;
		}
		int t = fail[len - 1];
		if (len % (len - t)) cout << "1\n";
		else cout << len / (len - t) << '\n';
	}
	return 0;
}
