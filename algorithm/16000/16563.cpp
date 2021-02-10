#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int N;
vector<int> v;
int arr[5000010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= 500000; i++) {
		for (int j = 2; i * j <= 500000; j++) {
			arr[i * j] = 1;
		}
		if (arr[i] == 0) v.push_back(i);
	}
	int vl = v.size();
	while (N--) {
		int K, bf, mem;
		cin >> K;
		bf = K;
		mem = K;
		int flag = 1;
		while (K > 0) {
			flag = 1;
			for (int i = 0; v[i] * v[i] <= K; i++) {
				if (K % v[i] == 0) {
					K /= v[i];
					flag = 0;
					cout << v[i] << " ";
					break;
				}
			}
			if (flag == 1) {
				if (K != 1) cout << K;
				cout << "\n";
				break;
			}
		}

	}
	return 0;
}