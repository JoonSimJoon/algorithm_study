#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

int n, m;
int base;
vector<int> v(8, 0);
vector<int> result;
unordered_set<string> checker;
void fun(int roopedTime, int startPoint) {
	if (roopedTime == m) {
		string temp;
		for (int i = 0; i < m; i++) {
			temp += to_string(result[v[i]]) + " ";
		}
		auto itr = checker.find(temp);
		if (itr == checker.end()) {
			checker.insert(temp);
			for (int i = 0; i < m; i++) {
				printf("%d ", result[v[i]]);
			}
			printf("\n");

		}
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

