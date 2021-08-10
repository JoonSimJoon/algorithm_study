#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define ll long long
#define mp(a,b) make_pair(a,b)
#define sws ios::sync_with_stdio(false), cin.tie()
#define MAX 1000000000
using namespace std;
int N, H, tmp, ans = MAX, rng;
vector<int> A, B;
int main() {
    sws;
    cin >> N >> H;
    FOR(i, 0, N) {
        cin >> tmp;
        if (i % 2 == 0) A.push_back(tmp);
        else B.push_back(tmp);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int totA = A.size(), totB = B.size();
    FOR(i, 1, H+1) {
        int x = totA - (lower_bound(A.begin(), A.end(), i) - A.begin());
        int y = totB - (lower_bound(B.begin(), B.end(), H - i + 1) - B.begin());
        if (ans > x + y) {
            ans = x + y;
            rng = 1;
        }
        else if (ans == x + y) rng++;
    }
    cout << ans << ' ' << rng;
}
