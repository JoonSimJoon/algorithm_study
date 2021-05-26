#include<bits/stdc++.h>
using namespace std;
int t; char ud='D', lr='R';
int main()
{
    int k; cin>>k;
    for(int i=0;i<2*k;i++)
    {
        char c; cin>>c;
        if(c==ud) t^=2,ud='D'+'U'-ud;
        if(c==lr) t^=1,lr='L'+'R'-lr;
    }
    int h; cin>>h; h^=t;
    for(int i=0;i<(1<<k);i++)
    {
        for(int j=0;j<(1<<k);j++)
        {
            cout<<(h^((i&1)<<1)^(j&1))<<' ';
        }
        cout<<'\n';
    }
}
