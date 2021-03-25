#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int N;
string arr[60];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}