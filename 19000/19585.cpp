#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define ll long long

ll N,M,K,L;
string tmp;
int flag=0;
struct anthole{
	string val;
	vector<anthole*> next;
	anthole(string val){
		this->val=val;
	}
};
anthole *Color = new anthole("Head");
anthole *Nick = new anthole("Head");

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

ll find_Color(anthole* nd,string x, ll pos){
	if(nd->next.empty()) return pos;
	ll sizex = nd->next.size();
	string tt="a";
	tt[0]=x[pos];
	for(ll i=0;i<sizex;i++){
		if(nd->next[i]->val.compare(tt)==0){
			return find_Color(nd->next[i],x,pos+1);
		}
	}
	return -1;
}

ll find_Nick(anthole* nd,string x, ll pos){
	if(nd->next.empty()) return pos;
	ll sizex = nd->next.size();
	string tt="a";
	tt[0]=x[pos];
	for(ll i=0;i<sizex;i++){
		if(nd->next[i]->val.compare(tt)==0){
			return find_Nick(nd->next[i],x,pos+1);
		}
	}
	return -1;
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(ll i=0;i<N;i++){
		anthole *check = Color;
		string st,tt;
		cin>>st;
		tt = "a";
		K = st.length();
		for(ll j=0;j<K;j++){
			sort(check->next.begin(),check->next.end(),cmp);
			tt[0]=st[j];
			flag=0;
			if(check->next.empty()){ 
				anthole *newnode = new anthole(tt);
				check->next.push_back(newnode);
				check=newnode;
			}else{
				L = check->next.size();
				for(ll dd=0;dd<L;dd++){
					if(check->next[dd]->val.compare(tt)==0){
						check=check->next[dd];
						flag=1;
						break;
					}
				} 
				if(flag==0){
					anthole *newnode = new anthole(tt);
					check->next.push_back(newnode);
					check=newnode;
				}
			}
		}
	}
	//nick
	for(ll i=0;i<M;i++){
		anthole *check = Nick;
		string st,tt;
		cin>>st;
		tt = "a";
		K = st.length();
		for(ll j=0;j<K;j++){
			sort(check->next.begin(),check->next.end(),cmp);
			tt[0]=st[j];
			flag=0;
			if(check->next.empty()){ 
				anthole *newnode = new anthole(tt);
				check->next.push_back(newnode);
				check=newnode;
			}else{
				L = check->next.size();
				for(ll dd=0;dd<L;dd++){
					if(check->next[dd]->val.compare(tt)==0){
						check=check->next[dd];
						flag=1;
						break;
					}
				} 
				if(flag==0){
					anthole *newnode = new anthole(tt);
					check->next.push_back(newnode);
					check=newnode;
				}
			}
		}
	}
	/*L = Color->next.size();
	for(ll lxs = 0; lxs<L;lxs++){
		print(Color->next[lxs],0);
	}
	*//*L = Nick->next.size();
	for(ll lxs = 0; lxs<L;lxs++){
		print(Nick->next[lxs],0);
	}*/
	sort(Color->next.begin(),Color->next.end(),cmp);
	sort(Nick->next.begin(),Nick->next.end(),cmp);
	cin>>K;
	ll lxs;
	int fl=-1,fc=-1;
	for(ll i=0;i<K;i++){
		fl=-1;
		fc=-1;
		string sx,tx;
		tx="a";
		cin>>sx;
		L = sx.length();
		tx[0]=sx[0];
		lxs=Color->next.size();
		for(ll j=0;j<lxs;j++){
			if(Color->next[j]->val.compare(tx)==0){
				fl=find_Color(Color->next[j],sx,1);
				break;
			}
		}
		//cout<<fl<<"\n";
		if(fl==-1){
			cout<<"No\n";
		}
		else{
			tx[0]=sx[fl];
			lxs=Nick->next.size();
			for(ll j=0;j<lxs;j++){
				if(Nick->next[j]->val.compare(tx)==0){
					fc=find_Nick(Nick->next[j],sx,fl+1);
					break;
				}
			}
			if(fc==-1){
				cout<<"No\n";
			}else if(fc==L){
				cout<<"Yes\n";
			}
		}
		//cout<<fl<<" "<<fc;
	}
	return 0;
}