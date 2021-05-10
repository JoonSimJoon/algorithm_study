#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string S,T;
int cnt=0;
int flag;
int mem=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>S>>T;
	int sl = S.size();
	int tl = T.size();
	int i=0;	
	for(int j=0;j<tl;j++){
		if(j==0) cnt++;
		if(S[i]==T[j]){
			i++;
			if(i==sl) break;
			else{
				mem=j;
			}
		}else{
			if(j==mem){
				flag=-1;
				break;
			}
		}
		if(j==tl-1) j=-1;
	}
	if(flag==-1) cout<<"-1\n";
	else cout<<cnt<<"\n";
	return 0;
}
