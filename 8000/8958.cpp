#include <iostream>
#include <string>
using namespace std;

int result=0;
int tmp;
string s;
int main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;
	cin>>N;
	while(N--){
		cin>>s;
		int l = s.size();
		result=0;
		tmp=0;
		for(int i=0;i<l;i++){
			if(s[i]=='O'){
				tmp++;
				result+=tmp;
			}
			else tmp=0;
		}
		cout<<result<<"\n";
	}
	return 0;
}