#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, A;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        v.push_back(A);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}