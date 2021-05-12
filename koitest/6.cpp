#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int N,K,cnt=0,ans=0;
        int visited[3010]={0, };
        cin>>N>>K;
        string gal;
        cin>>gal;
        for(int i=0;i<K;i++){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            if((a-b)%2==0) ans=-1;
            if(ans==-1) break;
            stack<int> s;
            for(int j=a;j<=b;j++){
               	if(gal[j]=='('){
               		if(s.empty()==0){
               			if(s.top()<0){
               				s.pop();
               				if(visited[j]==1){
								ans=-1;
								break;
							}else{
								visited[j]=1;
							}
							cnt++;
               				gal[j]=')';
						   }
					}
               		else s.push(j);
				}else{
					if(s.empty()==1){
						if(visited[j]==1){
							ans=-1;
							break;
						}else{
							visited[j]=1;
						}
						gal[j]='(';
						if(j==0){
							s.push(-3010);
						}
						else s.push(-j);
					}else{
						s.pop();
					}
				}
               // cout<<j<<" "<<cnt<<" "<<ans<<"\n";
            }
            
          //  cout<<gal<<"\n";
            
        }
        if(ans!=-1){
            cout<<cnt<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
}

