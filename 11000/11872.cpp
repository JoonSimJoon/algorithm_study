#include <bits/stdc++.h>
using namespace std;
long long sum;
int x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        sum+=x;
    }
    if(sum%N==0) cout<<"koosaga"<<"\n";
    else cout<<"cubelover\n";
    return 0;
}