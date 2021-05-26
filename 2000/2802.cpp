#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct s{
	int R,G,B;
};
vector<s> v;
int N,M;
s a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a.R>>a.G>>a.B;
		v.push_back(a);
	}
	return 0;
}
