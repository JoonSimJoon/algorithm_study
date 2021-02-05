#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[501][501];
int N, K, S, a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		arr[a][b] = -1;
		arr[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || j == k || i == k) continue;
				else {
					if (arr[i][j] == 0) {
						if (arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
						else if (arr[i][k] == -1 && arr[k][j] == -1)arr[i][j] = -1;
					}
				}
			}
		}
	}
	cin >> S;
	for (int i = 0; i < S; i++) {
		cin >> a >> b;
		cout << arr[a][b] << "\n";
	}
	return 0;
}