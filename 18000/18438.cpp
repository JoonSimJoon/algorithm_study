#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 10000

using namespace std;

char s1[MAX], s2[MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

vector < char > res;
vector < char > vs(MAX);
const int tt = 20;
int tmp[tt][MAX], chk[tt][MAX];
int dp[2][MAX], num[2][MAX];
int check[MAX];
int l1, l2;

void solve(int x1, int y1, int x2, int y2) {
	// (x1, y1) ~ (x2, y2) 까지의 LCS 구하기.
	//printf("%d %d %d %d\n", x1, y1, x2, y2);
	if (x2 - x1 < 18) {
		for (int i = 0; i < tt; i++) {
			for (int j = 0; j < MAX; j++) {
				tmp[i][j] = chk[i][j] = 0; 
			}
		}
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				int nx = i - x1 + 1, ny = j;
				if (s1[i - 1] == s2[j - 1]) {
					tmp[nx][ny] = tmp[nx - 1][ny - 1] + 1;
					chk[nx][ny] = 1;
				}
				else if (ny != y1 && tmp[nx - 1][ny] < tmp[nx][ny - 1]) {
					chk[nx][ny] = 3;
					tmp[nx][ny] = tmp[nx][ny - 1];
				}
				else {
					chk[nx][ny] = 2;
					tmp[nx][ny] = tmp[nx - 1][ny];
				}
			}
		}
		int nx = x2 - x1 + 1, ny = y2, cnt = 0;
		while (1) {
			if (nx <= 0 || ny <= y1 - 1) {
				break;
			}
			if (chk[nx][ny] == 1) {
				if (check[ny - 1] == 0) {
					vs[cnt++] = s2[ny - 1];
					check[ny - 1] = 1;
				}
				nx--;
				ny--;
			}
			else if (chk[nx][ny] == 2) {
				nx--;
			}
			else {
				ny--;
			}
		}
		for (int i = cnt - 1; i >= 0; i--) {
			res.push_back(vs[i]);
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = num[i][j] = 0;
		}
	}
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (i == (x1 + x2) / 2) {
				//*
				if (s1[i - 1] == s2[j - 1]) {
					num[i % 2][j] = j;
				}
				else if (j != y1 && dp[(i - 1) % 2][j] < dp[i % 2][j - 1]) {
					num[i % 2][j] = num[i % 2][j - 1];
				}
				else {
					num[i % 2][j] = j;
				}
				//*/num[i % 2][j] = j;
			}
			else if (i > (x1 + x2) / 2) {
				if (s1[i - 1] == s2[j - 1]) {
					num[i % 2][j] = num[(i - 1) % 2][j - 1];
				}
				else if (j != y1 && dp[(i - 1) % 2][j] < dp[i % 2][j - 1]) {
					num[i % 2][j] = num[i % 2][j - 1];
				}
				else {
					num[i % 2][j] = num[(i - 1) % 2][j];
				}
			}
			if (s1[i - 1] == s2[j - 1]) {
				dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
			}
			else {
				dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
			}
			//printf("%3d", dp[i % 2][j]);
		}
		//puts("");
	}
	int nx = (x1 + x2) / 2, ny = num[x2 % 2][y2];
	solve(x1, y1, nx, ny);
	solve(nx, ny, x2, y2);
}

int main() {
	scanf("%s\n%s", s1, s2);
	l1 = strlen(s1), l2 = strlen(s2);
	solve(1, 1, l1, l2);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%c", res[i]);
	}
	return 0;
}