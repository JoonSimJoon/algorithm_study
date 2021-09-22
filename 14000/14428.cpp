#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const ll CONSTMAX = 1e9+15; 
ll N,M;
ll arr[100020];
ll seg[400020];

ll init(ll st, ll en, ll idx){
    if(st==en){
        seg[idx]=st;
        return seg[idx];
    } 
    ll mid = (st+en)/2;
    seg[idx]=(arr[init(st,mid,idx*2)]<=arr[init(mid+1,en,idx*2+1)]?seg[idx*2]:seg[idx*2+1]);
    return seg[idx];
}

void change(ll st, ll en, ll idx, ll key){
    if(key<st || key>en) return;
    //cout<<"*"<<arr[seg[idx]]<<" "<<arr[key]<<"\n";
    if(st==en){
        return;
    }
    ll mid = (st+en)/2;
   	change(st,mid,idx*2,key);
   	change(mid+1,en,idx*2+1,key);
   	if(arr[seg[idx*2]]<=arr[seg[idx*2+1]]) seg[idx]=seg[idx*2];
   	else seg[idx]=seg[idx*2+1];
   	return;
}



ll query(ll st, ll en, ll left, ll right, ll idx){
    if (left > en || right < st) return -1;
    if (left <= st && en <= right) return seg[idx]; 
    ll mid = (st + en) / 2;
    ll q1 = query(st, mid, left, right, idx*2);
    ll q2 = query(mid+1, en, left, right, idx*2+1);
    if(q1==-1) return q2;
    if(q2==-1) return q1;
    if (arr[q1] <= arr[q2]) return q1;
    return q2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arr[100001]=1e9+1;
    cin>>N;
    for(ll i=1;i<=N;i++){
        cin>>arr[i];
    }
    init(1,N,1);

    cin>>M;
    while(M--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            arr[b]=c;
            //init(1,N,1);
            change(1,N,1,b);
            /*for(int i=1;i<3*N;i*=2){
		        for(int j=0;j<i;j++){
		            cout<<seg[i+j]<<" ";
		        }
		        cout<<"\n";
		    }*/
        }else{
            cout<<query(1,N,b,c,1)<<"\n";
        }
    }
    return 0;
}