#include <iostream>
using namespace std;
#define ll long long
ll N,K=1,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
        
    if(N==1) cout<<"0";
    else{
        while(K<N) K*=2;
        ans=K;
        for(ll i=K;i>=N;i-=2){
            ans--;
        }
        cout<<ans;
    }
    cout<<"\n"; // asd
    return 0;
}