#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	// priority_queue
	priority_queue<int,vector<int>,greater<int> > pq;
	cin>>N;
	for(int i=0,x;i<N;i++){
		cin>>x;
		if(x==0){
			if(pq.empty()) cout<<"0\n";
			else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}else{
			pq.push(x);
		}
	}

	return 0;

}
