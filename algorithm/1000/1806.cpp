#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<ll> v;
ll N, S, a, point1, point2, cnt, res=987654321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
    v.push_back(0);
    cnt = v[0];
    while (point1 <= point2 && point2 < N){
        if (cnt < S) cnt += v[++point2];
        else if (cnt == S){
            res = min(res, (point2 - point1 + 1));
            cnt += v[++point2];
        }
        else if (cnt > S){
            res = min(res, (point2 - point1 + 1));
            cnt -= v[point1++];
        }
    }
    if (res == 987654321) cout << "0" << "\n";
    else cout << res << "\n";
	return 0;
}