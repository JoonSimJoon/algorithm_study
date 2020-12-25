#include <stdio.h>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
int N, T, cost;
int dp[1010][1010], ans[1010][1010];

struct s {
	int x, y;
};

s arr[1013];
int distance(s a, s b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int f(int x, int y) {
	int here = max(x, y) + 1;
	if (here == T + 2) return 0;

	int& ret = dp[x][y];
	if (ret != -1) return ret;

	ret = f(here, y) + distance(arr[x], arr[here]);

	int ygo = f(x, here) + distance(arr[y], arr[here]);
	if (ygo < ret) {
		ret = ygo;
		ans[x][y] = 1;
	}

	return ret;
}


int main() {
	scanf("%d %d", &N, &T);
	arr[0] = { 1,1 };
	arr[1] = { N,N };
	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 2; i < T + 2; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	printf("%d\n", f(0, 1));
	for (int x = 0, y = 1; max(x, y) + 1 < T + 2; ) {
		printf("%d\n", ans[x][y] + 1);
		if (ans[x][y]) y = max(x, y) + 1;
		else x = max(x, y) + 1;
	}

	return 0;
}