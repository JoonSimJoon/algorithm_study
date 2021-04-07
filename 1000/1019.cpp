#include <stdio.h>
#include <iostream>
using namespace std;
#define ll long long
ll N,bf;
ll cntn[11];
int main() {
	cin >> N;
	ll tcnt = 1;
	while (N > 0) {
		int num = N % 10;
		N /= 10;
		for (int i = 0; i < num; ++i) cntn[i] += (N + 1) * tcnt;
		cntn[num] += N * tcnt + bf + 1;
		for (int i = num+1; i < 10; ++i) cntn[i] += N * tcnt;
		cntn[0] -= tcnt;
		bf += num * tcnt;
		tcnt *= 10;

	}
	for (int i = 0; i < 10; i++) cout << cntn[i] << " ";
	return 0;
}