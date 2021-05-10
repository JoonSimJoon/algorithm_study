#include <iostream>
using namespace std;

int T;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while (T--) {
        int s, k; cin >> s >> k;
        if (k % 2) {
            if (s % 2) cout << "1\n";
            else cout << "0\n";
        } else {
            s %= (k + 1);
            if (s == k) cout << k << '\n';
            else if (s % 2) cout << "1\n";
            else cout << "0\n";
        }
    }
	return 0;
}
