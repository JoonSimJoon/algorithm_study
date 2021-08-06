#include <stdio.h>
#define MIL 1000000

typedef long long int ll;

ll arr[1234567] = {0};

void setup(){
	arr[1] = 1;
	for(int i=1; i<=MIL; i++){
		for(int j=2*i; j<=MIL; j+=i){
			arr[j] -= arr[i];
		}
	}
}

ll f(ll k){
	ll ans = 0;
	for(ll i=1; i*i<=k; i++) ans += arr[i]*k/(i*i);
	return ans;
}

int main(){
	setup();
	ll k;
	scanf("%lld", &k);
	
	ll s=0, e=k*2;
	while(s < e-1){
		ll mid = (s+e)/2;
		if(f(mid)<k) s = mid;
		else		 e = mid;
	}
	
	printf("%lld", e);
}