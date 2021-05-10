#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int base;
vector<int> v(8, 0);
vector<int> result;

void fun(int roopedTime, int startPoint) {
	if (roopedTime == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", result[v[i]]);
		}
		printf("\n");
	}
	else {
		for (int i = startPoint; i < n; i++) {
			v[roopedTime] = i;
			fun(roopedTime + 1,i);
		}
	}
}

int main() {
	int temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		result.push_back(temp);
	}
	sort(result.begin(), result.end());
	fun(0,0);


	return 0;
}
