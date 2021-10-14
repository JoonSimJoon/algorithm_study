#include <iostream>
using namespace std;
#define ll long long
ll N,M,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	if(N%2==1){
		for (int i = 0; i < N; i++){
			if(i%2==0){
				for (int i = 0; i < M-1; i++){
					cout<<"R";
				}
			}else{
				for (int i = 0; i < M-1; i++){
					cout<<"L";
				}
			}
			if(i!=N-1) cout<<"D";
		}
	}
	else if(M%2==1){

		for (int i = 0; i < M; i++){
			if(i%2==0){
				for (int i = 0; i < N; i++){
					cout<<"D";
				}
			}else{
				for (int i = 0; i < M-1; i++){
					cout<<"U";
				}
			}
			if(i!=N-1) cout<<"R";
		}
	}else{
		
	}
	return 0;
}