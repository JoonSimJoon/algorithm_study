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
            if(ans==-1) break;
            stack<int> s;
            for(int j=a;j<=b;j++){
                if(s.empty()==0){
                    if(gal[j]=='('){
                    	if(s.top()<0){
                    		gal[j]=')';
                    		s.pop();
						}
					} 
                    else{
						s.pop();
                    }
                }else{
                    if(gal[j]=='(') s.push(j);
                    else{
                        if(visited[j]==0){
                            visited[j]=1;
                            gal[j]='(';
                            s.push(-j);
                            cnt++;
                        }else{
                            ans=-1;
                        }
                    }
                }
                cout<<j<<" "<<cnt<<" "<<ans<<"\n";
            }
            if(!s.empty()){
                while(ans!=-1 && !s.empty()){
                    if(visited[s.top()]==1){
                        ans=-1;
                    }else{
                        visited[s.top()]=1;
                        gal[s.top()]=')';
                        cnt++;
                        s.pop();
                        if(s.empty()==1){
                            ans=-1;
                            break;
                        }else{
                            s.pop();
                        }
                    }
                }
            } 
            cout<<gal<<"\n";
            
        }
        if(ans!=-1){
            cout<<cnt<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
}

