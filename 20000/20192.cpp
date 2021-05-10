#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int n; cin >> n;
    int top = 1;
    bool up = true;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (up) {
            if (top > a) {
                up = false;
                ans++;
            }
        }
        else {
            if (top < a) {
                up = true;
                ans++;
            }
        }
        top = a;
    }
 
    cout << ceil(log2(ans));
    return 0;
}
