#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
vector<ll> v;
ll N,M,idx,answer;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	for(ll i=0;i<=N;i++){
		if(v[i]==0){
			idx=i;
			break;
		}
	}
	for (int i = 0; i < idx; i += M) answer -= (v[i] * 2);
    for (int i = N; i > idx; i -= M) answer += v[i] * 2;
	answer -= max(abs(v[0]), v[N]);
    cout << answer;
	return 0;
}