#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int n, k,a;
vector<int> v;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    cout<<v[k-1]<<endl;
}

