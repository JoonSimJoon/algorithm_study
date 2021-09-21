#include <stdio.h>
#define MOD 1000000007

typedef long long int ll;

ll fac[4000010] = {0};
ll pow(ll a, ll b){
	if(b==0)   return 1;
	if(b%2==1) return (a*pow(a,b-1) % MOD) % MOD;
	else       return pow((a*a) % MOD, b/2) % MOD;
}


int main(){
	fac[0] = 1;
	fac[1] = 1;
	for(int i=1; i<=4000000; i++)fac[i+1] = ( fac[i] * (i+1) ) % MOD;
	
	int m,n,k;
	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &n, &k);
		ll tmp = (fac[k]*fac[n-k] % MOD);
		printf("%lld\n", fac[n] * pow(tmp, MOD-2) % MOD);
	} 
	return 0;
}