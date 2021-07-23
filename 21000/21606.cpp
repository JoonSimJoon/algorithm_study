#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int N,ans;
int che[200010];
int visited[200010];
vector<int> v[200010];
vector<int> fl;
queue <int> q;
int main(){
	scanf("%d",&N);
	for(int a,i=0;i<N;i++){
		scanf("%1d",&a);
		che[i+1]=a;
		if(a==1) fl.push_back(i+1);
	}
	for(int a,b,i=0;i<N-1;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int fll = fl.size();
	for(int i=0;i<fll;i++){
		int nre = fl[i];
		q=queue<int> ();
		memset(visited,0,sizeof(visited));
		visited[nre]=1;
		q.push(nre);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			int vl = v[now].size();
			for(int next,i=0;i<vl;i++){
				next=v[now][i];
				if(visited[next]==0){
					visited[next]=1
;					if(che[next]==1){
						ans++;
					}
					else q.push(next);
				}
			}
		}
		//printf("%d %d\n",nre,ans);

	}
	printf("%d",ans);
	return 0;
}