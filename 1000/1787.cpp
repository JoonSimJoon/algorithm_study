#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX = 1e6 + 10;
int n, dp[MAX], pi[MAX];
char str[MAX];

int func(int pos) {
    if (pos < 0 || pi[pos] == 0) {
        return INF;
    }

    int ret = dp[pos];
    if (ret != -1) {
        return ret;
    }

    return dp[pos] = min(pi[pos], func(pi[pos] - 1));
}

int main() {
    scanf("%d%s", &n, str);

    int match = 0;
    for (int i = 1; i < n; ++i) {
        while (match && str[i] != str[match]) {
            match = pi[match - 1];
        }
        if (str[i] == str[match]) {
            ++match;
        }
        pi[i] = match;
    }

    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int ret = func(i);
        if (ret != INF) {
            ans += (ll)(i - ret + 1);
        }
    }

    printf("%lld\n", ans);
}
