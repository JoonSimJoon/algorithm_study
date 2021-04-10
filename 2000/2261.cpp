/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pll pair< ll, ll>
ll N,x,ans=20000*20000*2+15;
int cp1(pll x, pll y){
	if(x.first==y.first){
		return x.second<y.second;
	}
	else return x.first<y.first;
}

int cp2(pll x, pll y){
	if(x.second==y.second){
		return x.first<y.first;
	}
	else return x.second<y.second;
}
pll a;
vector< pll > v1,v2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll i=0;i<N;i++){
		cin>>a.first>>a.second;
		v1.push_back(a);
		v2.push_back(a);
	}
	sort(v1.begin(),v1.end(),cp1);
	sort(v2.begin(),v2.end(),cp2);
	for(ll i=0;i<N-1;i++){
		if(ans>(v1[i].first-v1[i+1].first)*(v1[i].first-v1[i+1].first)+(v1[i].second-v1[i+1].second)*(v1[i].second-v1[i+1].second)){
			ans=(v1[i].first-v1[i+1].first)*(v1[i].first-v1[i+1].first)+(v1[i].second-v1[i+1].second)*(v1[i].second-v1[i+1].second);
		}
		if(ans>(v2[i].first-v2[i+1].first)*(v2[i].first-v2[i+1].first)+(v2[i].second-v2[i+1].second)*(v2[i].second-v2[i+1].second)){
			ans=(v2[i].first-v2[i+1].first)*(v2[i].first-v2[i+1].first)+(v2[i].second-v2[i+1].second)*(v2[i].second-v2[i+1].second);
		}
	}
	cout<<ans<<"\n";
	return 0;
}*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

typedef struct point {
    int x, y;
    bool operator<(const struct point &p) const {
        if(y == p.y) return x < p.x;
        else return y < p.y;
    }
} POINT;

bool comp(POINT a, POINT b) {
    return a.x < b.x;
}

int dist(POINT a, POINT b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main()
{
    int n;
    scanf("%d",&n);

    vector<POINT> v(n);
    for(int i=0 ; i<n ; i++) {
        int x, y;
        scanf("%d %d",&v[i].x, &v[i].y);
    }
    sort(v.begin(), v.end(), comp);

    set<POINT> cand = {v[0], v[1]};
    int mdist = dist(v[0], v[1]);
    int st = 0;
    for(int i=2 ; i<n ; i++) {
        POINT cur = v[i];
        while(st < i) {
            POINT p = v[st];
            int xDif = cur.x - p.x;
            if(xDif*xDif > mdist) {
                cand.erase(p);
                st++;
            }
            else {
                break;
            }
        }
        int d = (int)sqrt((double)mdist)+1;

        POINT lowBound = {-100000, cur.y-d};
        POINT upBound = {100000, cur.y+d};

        auto lower = cand.lower_bound(lowBound);
        auto upper = cand.upper_bound(upBound);
        for(auto it = lower ; it != upper ; it++) {
            int d = dist(cur, *it);
            if(d < mdist) mdist = d;
        }
        cand.insert(cur);
    };

    printf("%d",mdist);
}
