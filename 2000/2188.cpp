#include<stdio.h>
#include<vector>
#define MAX 201
using namespace std;
vector<int> want [MAX];
int visited[MAX];
int room[MAX];
int solve(int);
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
    {
        int a, b;
        scanf("%d", &a);
        while (a--)
        {
            int b;
            scanf("%d", &b);
            want[i].push_back(b);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        fill(visited,visited+N, 0);
        if (solve(i))
        {
            //for (int j = 1; j <= M; ++j)
            //    printf("%d ", room[j]);
            //printf("\n");
            ++ans;
        }
    }
    printf("%d", ans);
}
int solve(int c)
{
    if (visited[c])
        return 0;
    visited[c] = 1;
    for (int w : want[c]) //원하는방에 갈수있는지 체크
    {
        if (!room[w] || solve(room[w])) //방이 비어있거나, 원래있던놈을 밀어낼수있으면
        {
            room[w] = c;
            return 1;
        }
    }
    return 0;
}

