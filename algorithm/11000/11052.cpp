#include<iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1002];
int dp[1002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    dp[1] = arr[1];
    for (int i = 2; i <= N; i++){
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + arr[i - j]);
        }
    }
    cout << dp[N];
    return 0;
}