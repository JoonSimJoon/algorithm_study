#include <iostream>
#include <queue>

using namespace std;

typedef struct info {
    int y;
    int x;
    int dst;
    int used;
}INFO;


int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int N, M,K;
char map[1000][1000];

bool visited[1010][1010][13]; // 0 : 벽 부수지 않음 1 : 벽 이미 부숨

queue<INFO> que;

void bfs() {
    que.push({0,0,1,0});

    while(!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        int dst = que.front().dst;
        int used = que.front().used;

        // cout << "(y, x) : " << "(" << y << ", " << x << ")" << endl;
        // cout << "dst : " << dst << endl;
        // cout << "used : " << (used ? "true" : "false") << endl << endl;

        que.pop();

        if(x == M - 1 && y == N - 1) {
            cout << dst;
            exit(0);
        }

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nused = used;

            if(nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1)
                continue;
            
            if(visited[ny][nx][used])
                continue;
            
            if(map[ny][nx] == '1') {
                if(used>=K)
                    continue;
                if(!(used<K) && visited[ny][nx][used])
                    continue;

                nused++;
            }

            visited[ny][nx][nused] = true;

            que.push({ny, nx, dst + 1, nused});
        }
    }

    cout << -1;
    exit(0);
}

int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M>>K;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> map[i][j];

    bfs();
}
