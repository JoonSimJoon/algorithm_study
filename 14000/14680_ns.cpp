#include <iostream>
using namespace std;
#define dev 1000000007
int T, N1, M1, M2, N, K, M;
int arr1[200][200];
int arr2[200][200];
int ans[200][200];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> T;
	cin >> N >> M1;
	M = M1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M1; j++) {
			cin >> arr1[i][j];
		}
	}
	cin >> M2 >> K;
	for (int i = 0; i < M2; i++) {
		for (int j = 0; j < K; j++) {
			cin >> arr2[i][j];
		}
	}
	if (M1 != M2) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int h = 0; h < M; h++) {
				ans[i][j] += (arr1[i][h] * arr2[h][j]) % dev;
				res = (res + ans[i][j]) % dev;
			}
		}
	}
	M = K;
	T -= 2;
	while (T--) {
		cin >> N1 >> M1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M1; j++) {
				cin >> arr1[i][j];
			}
		}
		if (M1 == N) {
			for (int i = 0; i < N1; i++) {
				for (int j = 0; j < M; j++) {
					for (int h = 0; h < N; h++) {
						ans[i][j] += (arr1[i][h] * ans[h][j]) % dev;
						res = (res + ans[i][j]) % dev;
					}
				}
			}
		}
		else if (N1 == M) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M1; j++) {
					for (int h = 0; h < M; h++) {
						ans[i][j] += (ans[i][h] * arr1[h][j]) % dev;
						res = (res + ans[i][j]) % dev;
					}
				}
			}
		}
		else {
			cout << "-1\n";
			return 0;
		}
	}
	cout << res << "\n";
	return 0;
}