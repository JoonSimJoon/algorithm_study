#include <stdio.h>
 
int N, M, ans;
int use[20];
inline int min(int A, int B) { return A < B ? A : B; }
inline int abs(int x) { return x < 0 ? -x : x; }
 
void DFS(int first, int second, int depth, int moveCnt) {
    // 분기한정
    if (moveCnt > ans) return;
 
    if (depth == M) {
        ans = (ans, moveCnt);
        return;
    }
    DFS(use[depth], second, depth + 1, moveCnt + abs(first - use[depth]));
    DFS(first, use[depth], depth + 1, moveCnt + abs(second - use[depth]));
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    int first, second;
    scanf("%d", &N); // 벽장의 개수
    scanf("%d %d", &first, &second); // 열린 문
    scanf("%d", &M); // 사용 순서
    for (int i = 0; i < M; i++) {
        scanf("%d", &use[i]);
    }
 
    ans = N * M + 1;
    DFS(first, second, 0, 0);
    printf("%d", ans);
}

