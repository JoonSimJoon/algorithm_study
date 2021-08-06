#include <iostream>
using namespace std;

double D[1000010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		cout.precision(15);

	int N;
	cin>>N;
	D[0] = 0;
	D[1] = 1.0;
	D[2] = (D[0] + D[1]) / 6 + 1;
	D[3] = (D[0] + D[1] + D[2]) / 6 + 1;
	D[4] = (D[0] + D[1] + D[2] + D[3]) / 6 + 1;
	D[5] = (D[0] + D[1] + D[2] + D[3] + D[4]) / 6 + 1;
	for(int i=6;i<=N;i++){
		D[i] = (D[i - 1] + D[i - 2] + D[i - 3] + D[i - 4] + D[i - 5] + D[i-6]) / 6 + 1;
	}
	cout<<(D[N]);
	return 0;
}