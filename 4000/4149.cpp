#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll N;
ll gcd(ll a,ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

vector<ll> factors;

void factorize(ll n) {
    //n이 1이면 계산할 필요없다.
    if (n == 1) return;
    //소수 판정
    if (primality_test(n)) {
        factors.push_back(n);
        return;
    }
    
    ll x, y, c, g = n;
    
    auto f = [=](ll x) {
        return ((__int128_t)x * x % n + c) % n;
    }
    do {
        //실패했을 경우 다른 x0, c로 테스트
        if (g == n) {
            x = y = rand() % (n - 2);
            c = rand() % 10 + 1;
            g = 1;
        }
        x = f(x);
        y = f(f(y));
        g = gcd(abs(x - y), n);
    } while (g == 1);
    //n의 인수를 찾음. 분할 정복
    factorize(g);
    factorize(n / g);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	ll M=N;
	vector<ll> v1,v2;
	while(M>1){
		for(ll x=2;x<=M;x++){
			if(M%x==0){
				M/=x;
				v1.push_back(x);
				break;
			} 
		}
	}
	for(ll i=0;i<v1.size();i++) cout<<v1[i]<<" ";
	facorize(N);
	for(ll i=0;i<factors.size();i++) cout<<factors[i]<<" ";
	
	return 0;
}
