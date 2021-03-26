#include <iostream>
#include <string>
#include <string.h>

using namespace std;


int N, ans=0;
string arr[60];
int Row[3];
int dx[5] = { 0,1,0,-1 };
int dy[5] = { 1,0,-1,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				if (i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] > N-1 || j + dy[k] > N-1) continue;
				else {
					memset(Row, 0, sizeof(Row));
					swap(arr[i][j], arr[i + dx[k]][j + dy[k]]);
					
					for (int Nt = 1; Nt < j+1; Nt++) {
						if (arr[i][j - Nt] == arr[i][j]) Row[0]++;
						else break;
					}
					for (int Nt = 0; Nt < N-j; Nt++) {
						if (arr[i][j + Nt] == arr[i][j]) Row[0]++;
						else break;
					}for (int Nt = 0; Nt < i+1; Nt++) {
						if (arr[i - Nt][j] == arr[i][j]) Row[1]++;
						else break;
					}for (int Nt = 1; Nt < N-i; Nt++) {
						if (arr[i + Nt][j] == arr[i][j]) Row[1]++;
						else break;
					}
					ans = max(Row[0], max(Row[1], ans));
										
					swap(arr[i][j], arr[i + dx[k]][j + dy[k]]);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}