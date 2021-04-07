#include <iostream>
using namespace std;
int N, M, K;
int arr1[200][200];
int arr2[200][200];
int ans[200][200];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int h = 0; h < M; h++) {
				ans[i][j] += arr1[i][h] * arr2[h][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}