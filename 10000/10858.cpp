#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N;
int a= -1000001;
int b = 1000001;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int x,i = 0; i < 9; i++){
		cin>>x;
		if(x>a) a=x,b=i;
	}
	cout<<a<<" "<<b+1;
	return 0;
}