#include <iostream>
#include <vector>
using namespace std;

int arr[51][51];
vector<int> v[51];
int N, M, K;
int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	cin >> K;

	return 0;
}

//https://xy-plane.tistory.com/14