#include <bits/stdc++.h>
using namespace std;

using Int = int;
using Long = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    Long n;
    cin >> n;

    Long ans = n, num = n;
    for (Long i = 2L;i*i <= n;++i) {
        if (num % i == 0) {
            ans /= i;
            ans *= i - 1;

            while (num % i == 0) {
                num /= i;
            }
        }
    }

    if (num != 1) {
        ans /= num;
        ans *= num - 1;
    }

    cout << ans << "\n";
}