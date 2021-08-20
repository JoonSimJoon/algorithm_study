#include <cstdio>
#define MOD 1000000000

typedef long long ll;
ll dp[10001];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	k = n + k - 1;
	
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= k; i++) {
		dp[i] = 1;
		for(int j = i - 1; j > 0; j--){
			dp[j] = (dp[j - 1] + dp[j]) % 1000000000;
		}
	}
	printf("%lld", dp[n]);
}