#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct nd {
	int x, y;
};
struct ln {
	nd st, en;
};
int N;
vector<ln> v;
ln tmp;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp.st.x >> tmp.st.y >> tmp.en.x >> tmp.en.y;
	}
	return 0;
}