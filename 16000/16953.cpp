#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long int lli;
int main() {

	int a, b;
	cin >> a >> b;

	queue<pair<lli,lli>> q;
	q.push({ a,1 });

	lli ans = -1;
	while (!q.empty()) {

		lli x = q.front().first;
		lli cnt = q.front().second;
		q.pop();
		
		if (x == b) {
			ans = cnt;
			break;
		}
		lli c1 = x * 2;
		lli c2 = x * 10 + 1;

		if (c1 <= b) q.push({ c1,cnt+1 });
		if (c2 <= b) q.push({ c2,cnt+1 });
	}
	cout << ans << "\n";
	return 0;
}
