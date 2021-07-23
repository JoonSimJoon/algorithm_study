#include <iostream>
#define MAX 801
using namespace std;
int n,e,dist[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> e;
    int a,b,c,v1,v2;
    fill(&dist[0][0],&dist[n][n]+1,-1);
    for(int i=0;i<=n;i++){
        dist[i][i] = 0;
    }
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    cin >> v1 >> v2;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dist[i][k] == -1) continue;
            for(int j=1;j<=n;j++){
                if(dist[k][j]==-1) continue;
                if(dist[i][j]== -1 || dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int ans = -1;
    if(dist[1][v1] != -1 && dist[v1][v2] != -1 && dist[v2][n] != -1){
        // 1 -> v1 -> v2 -> n
        ans = dist[1][v1]+dist[v1][v2]+dist[v2][n];
    }
    if(dist[1][v2] != -1 && dist[v2][v1] != -1 && dist[v1][n] != -1){
        // 1 -> v2 -> v1 -> n
        int tmp = dist[1][v2]+dist[v2][v1]+dist[v1][n];
        if(ans == -1 || ans > tmp){
            ans = tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}