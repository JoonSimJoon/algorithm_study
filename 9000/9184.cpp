#include <iostream>
using namespace std;
int dp[22][22][22];

int f(int a,int b,int c){
	if(dp[a][b][c]!=0) return dp[a][b][c];
	else{
		if(a<=0 || b<=0 ||c<=0) return 1;
		else if(a>20 || b>20 || c>20){
			return f(20,20,20);
		}
		else{
			if(a<b && b<c){
				return dp[a][b][c] = f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
			}else{
				return dp[a][b][c] = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//f(20,20,20);
	while(1){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==-1 && b==-1 && c==-1) break;
		else{
			if(a<=0 || b<=0 ||c<=0) cout << "w(" << a << ", " << b << ", " << c << ") = 1\n";
			else if(a>20 || b>20 || c>20){
				cout << "w(" << a << ", " << b << ", " << c << ") = "<<f(20,20,20)<<"\n";
			}
			else cout << "w(" << a << ", " << b << ", " << c << ") = "<<f(a,b,c)<<"\n";
		}
	}
	return 0;
}