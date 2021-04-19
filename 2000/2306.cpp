#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
using namespace std;

string K;
int dp[500][500];
char DNA[2][2] = { {'a','t'},{'g','c'} };
int dfs(int Sidx, int Eidx) {
	if (Eidx - Sidx + 1 < 2)
		return  0;

	int&ret = dp[Sidx][Eidx];

	if (ret != -1)return ret;

	ret = 0;
	
	for (int d = 0; d < 2; ++d) {
		if (K[Sidx] == DNA[d][0])
			for (int i = Sidx + 1; i <= Eidx; ++i)
				if (K[i] == DNA[d][1])ret = max(ret, 2 + dfs(Sidx + 1, i - 1) + dfs(i + 1, Eidx));
	
		if (K[Sidx] != DNA[d][0])ret = max(ret, dfs(Sidx + 1, Eidx));
	}
	
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));

	cin >> K;

	cout << dfs(0, K.size() - 1);
	return 0;
}