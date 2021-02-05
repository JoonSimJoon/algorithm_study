#include <stdio.h>
#include <queue>
using namespace std;
queue< pair<int, int> > q;
int dx[5] = { 0,0,1,-1 };
int dy[5] = { 1,-1,0,0 };
int N, M, cnt[3];
int map[120][120];
int check[120][120];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			check[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] != 2) {
				q.push({ i,j });
				while (!q.empty()) {
					pair<int, int> now, next;
					now = q.front();
					check[now.first][now.second] = 2;
					q.pop();
					for (int i = 0; i < 4; i++) {
						next.first = now.first + dx[i];
						next.second = now.second + dy[i];
						if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < M && check[next.first][next.second]!=2 && map[now.first][now.second] == map[next.first][next.second]) {
							q.push(next);
							check[now.first][now.second] = 2;
						}
					}
				}
				/*for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						printf("%2d", check[i][j]);
					}
					printf("\n");
				}
				printf("\n");*/
				cnt[map[i][j]]++;
			}
		}
	}
	printf("%d", min(cnt[0], cnt[1]));
	return 0;
}