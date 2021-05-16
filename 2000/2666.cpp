#include <stdio.h>
 
int N, M, ans;
int use[20];
inline int min(int A, int B) { return A < B ? A : B; }
inline int abs(int x) { return x < 0 ? -x : x; }
 
void DFS(int first, int second, int depth, int moveCnt) {
    // �б�����
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
    scanf("%d", &N); // ������ ����
    scanf("%d %d", &first, &second); // ���� ��
    scanf("%d", &M); // ��� ����
    for (int i = 0; i < M; i++) {
        scanf("%d", &use[i]);
    }
 
    ans = N * M + 1;
    DFS(first, second, 0, 0);
    printf("%d", ans);
}

