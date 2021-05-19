#include <iostream>

using namespace std;

const int MAX = 1000 + 1;

int N;
int graph[MAX][MAX];
int degree[MAX];  

void DFS(int node)

{
        for(int i = 1; i <= N; i++)
                 while (graph[node][i])
                 {
                         graph[node][i]--;
                         graph[i][node]--;
                         DFS(i);
                 }
        cout << node << " ";
}
int main(void){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> N;
        for (int i = 1; i <= N; i++)
                 for (int j = 1; j <= N; j++)
                 {
                         cin >> graph[i][j];
                         degree[i] += graph[i][j];
                         degree[j] += graph[i][j];

                 }
        bool canEuler = true;
        for (int i = 1; i <= N; i++) {
                degree[i] /= 2;  
                 if (degree[i] % 2)
                 {
                         canEuler = false;
                         break;
                 }
        }
        if (canEuler)
        {
                 DFS(1);
                 cout << "\n";
        }
        else
                 cout << -1 << "\n";
        return 0;
}
