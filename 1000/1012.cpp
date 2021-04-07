#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct s {
	int x, y;
};
int cnt, N, M,a, b, K;
int arr[60][60];
queue<s> q;
s now, nex;

void bfs(s tts ) {
	q.emplace();
	q.push(tts);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		nex.x = 0, nex.y = 0;
		arr[now.x][now.y] = 0;
		for (int i = 0; i < 4; i++) {
			nex.x = now.x + dx[i];
			nex.y = now.y + dy[i];	
			if (nex.x >= 0 && nex.x < M && nex.y >= 0 && nex.y < N){
				if (arr[nex.x][nex.y] == 1) {
					arr[nex.x][nex.y] = 0;	
					q.push(nex);
				}
			}
		}
	}
	cnt++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int T;
	cin >> T;
	while (T--) {
		cnt = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			arr[a][b] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[j][i]) {
					bfs({ j,i });
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}