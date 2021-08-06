#include<bits/stdc++.h>
using namespace std;
 
int arr[1001];
int arr2[1001];
int dp[1001][1001];
 
int main()
{
    int n,i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&arr2[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(abs(arr[i]-arr2[j])<=4)
                dp[i][j]=dp[i-1][j-1]+1;
        }
    printf("%d",dp[n][n]);
}
