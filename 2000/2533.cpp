#include <stdio.h>
#include <vector>
#include <algorithm>
 
using namespace::std;
 
int n;
int dp[1000005][2];
bool visited[1000005];
vector<int> child[1000005];
vector<int> edge[1000005];
 
void getchild(int now){
    visited[now] = true;
    for(int i=0 ; i<edge[now].size() ; i++){
        int next = edge[now][i];
        if(!visited[next]){
            child[now].push_back(next);
            getchild(next);
        }
    }
}
 
int getdp(int now,bool chk){
    if(dp[now][chk]!=0) return dp[now][chk];
    if(child[now].size()==0) return dp[now][chk] = chk;
    if(chk){
        int ans=0;
        for(int i=0 ; i<child[now].size() ; i++){
            int next = child[now][i];
            ans += min(getdp(next,false), getdp(next,true));
        }
        return dp[now][chk] = ans + 1;
    }
    else{
        int ans=0;
        for(int i=0 ; i<child[now].size() ; i++){
            int next = child[now][i];
            ans += getdp(next,true);
        }
        return dp[now][chk] = ans;
    }
}
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    getchild(1);
    printf("%d",min(getdp(1,false),getdp(1,true)));
}


