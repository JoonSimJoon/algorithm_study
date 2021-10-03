#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;

	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a > b)
		cout << a;
	else
		cout << b;

	return 0;
}