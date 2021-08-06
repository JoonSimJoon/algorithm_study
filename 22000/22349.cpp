#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <string.h>
#include <vector>
using namespace std;
#define ll long long
set<ll> sa,sb;
set<ll>::iterator ita,itb;
stack<ll> s;
 ll bef=0,ans=-1,al,bl;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll T;
    cin>>T;
    while(T--){
        string a,b;
        bef=0,ans=-1;
        cin>>a>>b;
        al = a.size();
        bl = b.size();
        s=stack<ll>();
       
        for(ll i=0;i<al;i++){
            if(s.empty()){
                if(a[i]=='(') s.push(1);
                else{
                    bef=0;
                }
            }else{
                if(a[i]=='(') s.push(1);
                else{
                    s.pop();
                    bef++;
                    if(ans<bef) ans=bef;
                    //sa.insert(bef);
                }
            }
        }
        if(ans==-1) ans=0;
        cout<<ans*2<<"\n";
    }
    return 0;
}


