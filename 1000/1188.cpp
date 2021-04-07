#include <iostream>
#include <math.h>
using namespace std;
#define LL long long
int  N, M, ans;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
	cin >> N >> M;
	cout << M - gcd(N, M) << endl;
	return 0;
}