#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
ll G, P, tmp;
ll arr[100010],ans;
int find(int u) {
	if (arr[u] == u)return u;
	return arr[u] = find(arr[u]);
}

void unit(int u, int v) {
	u = find(u);
	v = find(v);
	arr[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> G >> P;
	for (int i = 0; i <= G; i++) arr[i] = i;
	for (int i = 0; i < P; i++) {
		cin >> tmp;
		if (find(tmp) == 0) break;
		else {
			ans++;
			unit(find(tmp), find(tmp) - 1);
		}
	}
	cout << ans << "\n";
	return 0;
}