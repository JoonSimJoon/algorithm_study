#include <iostream>
using namespace std;

int n;
int score[1000] = {};
int maxx = 0;
double result = 0;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (score[i] > maxx)
			maxx = score[i];
		result += score[i];
	}
	result = (result / maxx * 100) / n;

	cout << fixed;
	cout.precision(6);
	cout << result << endl;
}