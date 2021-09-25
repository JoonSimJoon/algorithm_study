#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define ll long long

ll N,K,L;
string tmp;

struct Node{
	string val;
	Node* key;
};

struct anthole{
	Node now;
	vector<anthole*> next;
	anthole(string val){
		this->now.val=val;
	}
};

int cmp(Node a, Node b){
	return -1*a.val.compare(b.val);
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	anthole *Head = new anthole("Head");
	anthole *tmp = new anthole("none");
	for(ll i=0;i<N;i++){
		anthole *check = Head;
		cin>>K;
		for(ll j=0;j<K;j++){
			cin>>tmp->now.val;
			if(check->next.empty()){ 
				check->next.push_back(tmp);
				check=tmp;
			}else{
				L = check->now.size();
				for(ll i=0;i<L;i++){
					if(check->now[i].val.compare(tmp->now.val)==0){
						check=check->now[i].key;
					}
				} 
			}
		}
	}
	return 0;
}