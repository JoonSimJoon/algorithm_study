#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
long long int N, dp[130] = { 1,1,1,2,2,3,4,5, }, arr[130];
int main() {
	scanf("%lld", &N);
	for (int i = 4; i < 102; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		arr[i] = dp[x - 1];
	}
	for (int i = 0; i < N; i++) printf("%lld\n", arr[i]);
	return 0;
}