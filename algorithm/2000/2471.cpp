#include<bits/stdc++.h>
using namespace std;

#define nn 210
bool did[nn];

string mob;
pair<int,int> par[nn];
int idx[nn], n, k;

priority_queue<string> pq[nn];
vector<string> res[nn];
set<string> uniq[nn];

void mobile( int x, int pos, bool dir, int lim, string now ){
    while( 1 ){
        if( pos==lim ) break;
        if( idx[pos] ) break;
        now += mob[pos];
        if( dir ) pos++;
        else pos--;
    }
    if( pos==lim ){
        if( uniq[x].count(now) ) return;
        uniq[x].insert(now);
        if( int(pq[x].size())==k && pq[x].top()<now ) return;
        pq[x].push(now);
        return;
    }
    int y = idx[pos], m = int(res[y].size());
    for( int i=0; i<m; i++ ){
        if( int(pq[x].size())>=k ) break;
        string tmp = now + res[y][i];
        int next_pos = par[y].first-1;
        if( dir ) next_pos = par[y].second+1;
        mobile( x, next_pos, dir, lim, tmp );
    }
}
void dfs( int x ){

    if( did[x] ) return;
    did[x] = 1;
    
    // 하위 막대 전처리
    int l = par[x].first, r = par[x].second;
    for( int i=l+1; i<r; i++ ){
        if( idx[i] ){
            dfs(idx[i]);
            i = par[idx[i]].second;
        }
    }

    vector<string> t1, t2;

    mobile( x, l+1, 1, r, "" );
    while( !pq[x].empty() ){
        t1.push_back(pq[x].top());
        pq[x].pop();
    }
    mobile( x, r-1, 0, l, "" );
    while( !pq[x].empty() ){
        t2.push_back(pq[x].top());
        pq[x].pop();
    }

    for( int i=int(t1.size())-1, j=int(t2.size())-1; !(i<0&&j<0); ){
        if( int(res[x].size()) == k ) break;
        if( j<0 ) res[x].push_back(t1[i--]);
        else if( i<0 ) res[x].push_back(t2[j--]);
        else if( t1[i]<t2[j] ) res[x].push_back(t1[i--]);
        else res[x].push_back(t2[j--]);
    }

}
int main(){
    
    cin >> mob >> k;
    
    vector<int> st;
    for( int i=0, l=int(mob.size()); i<l; i++ ){
        if( mob[i]=='(' ) st.push_back(i);
        if( mob[i]==')' ){
            int u = st.back(), v = i;
            par[++n] = {u,v};
            idx[u] = idx[v] = n;
            st.pop_back();
        }
    }

    dfs(n);
    if( int(res[n].size()) < k ) cout << "NO";
    else cout << res[n][k-1];

    return 0;
}
