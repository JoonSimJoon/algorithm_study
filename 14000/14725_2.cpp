#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define ll long long

ll N,K,L;
string tmp;
int flag=0;
struct anthole{
	string val;
	vector<anthole*> next;
	anthole(string val){
		this->val=val;
	}
};

int cmp(anthole* a, anthole* b){
	return a->val<b->val;
}
void print(anthole* nd,ll dep){
	for (ll dd = 0; dd < dep; dd++){
		cout<<"--";
	}
	cout<<nd->val<<"\n";
	if(nd->next.empty()) return;
	else{
		ll lx = nd->next.size();
		sort(nd->next.begin(),nd->next.end(),cmp);
		for(ll dd =0; dd <lx;dd++){
			print(nd->next[dd],dep+1);
		}
	}
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
			flag=0;
			cin>>tmp->val;
			if(check->next.empty()){ 
				anthole *newnode = new anthole(tmp->val);
				check->next.push_back(newnode);
				check=newnode;
			}else{
				L = check->next.size();
				for(ll dd=0;dd<L;dd++){
					if(check->next[dd]->val.compare(tmp->val)==0){
						check=check->next[dd];
						flag=1;
						break;
					}
				} 
				if(flag==0){
					anthole *newnode = new anthole(tmp->val);
					check->next.push_back(newnode);
					check=newnode;
				}

			}
		}
	}
	L = Head->next.size();
	sort(Head->next.begin(),Head->next.end(),cmp);

	for(ll lxs = 0; lxs<L;lxs++){
		print(Head->next[lxs],0);
	}
	return 0;
}