#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[1005][1005];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    d[0][0] = 1;
    d[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            d[i][j] = (d[i-1][j] + d[i-1][j-1]) % 10007;
        }
    }
    cout << d[n][k];
    return 0;
}
