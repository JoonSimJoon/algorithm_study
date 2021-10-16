#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[4][4001], N;
ll ans;
vector<int> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[j][i];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            v.push_back(-(arr[0][i] + arr[1][j]));
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            auto lower_it = lower_bound(v.begin(), v.end(), arr[2][i] + arr[3][j]);
            auto upper_it = upper_bound(v.begin(), v.end(), arr[2][i] + arr[3][j]);
            ans += upper_it - lower_it;
        }
    cout << ans << "\n";
}
