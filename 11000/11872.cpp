#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p % 4 == 3) {
            p++;
        } else if (p > 0 && p % 4 == 0) {
            p--;
        
}        x ^= p;
    }

    cout << (x != 0 ? "koosaga" : "cubelover") << '\n';

    return 0;
}