#include <stdio.h>

double arr[12345] = {0.0};
double dp[12345] = {0.0};

double max(double a, double b){return a>b?a:b;}

int main(){
	int n;
	double ans = -1;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lf", &arr[i]);
		dp[i] = arr[i];
	}
	for(int i=1; i<n; i++) dp[i] = max(arr[i], dp[i-1]*arr[i]);
	for(int i=0; i<n; i++) ans = max(ans, dp[i]);
	
	printf("%.3lf", ans);
	return 0;
}
