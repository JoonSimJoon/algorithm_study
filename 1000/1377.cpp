#include <stdio.h>
#include <algorithm>

using namespace std;

class p {
public:
    int n, i;
};

int bt[1100000];

int f(int l, int r, int s) {
    if(l>r) return s;
    if(l==r) return s+bt[l];
    if(l%2==0&&r%2) return f(l/2,r/2,s);
    else if(l%2==0&&r%2==0) return f(l/2,r/2-1,s+bt[r]);
    else if(l%2&&r%2) return f(l/2+1,r/2,s+bt[l]);
    else return f(l/2+1,r/2-1,s+bt[l]+bt[r]);
}

void r(int s, int d) {
    if(s==0) return;
    bt[s]+=d;
    r(s/2,d);
}

bool cmp(const p &i, const p &j) {
    if(i.n!=j.n) return i.n>j.n;
    else return i.i>j.i;
}

int main() {
    int n, b=1;
    p arr[500000];
    scanf("%d",&n);
    while(b<n)
        b*=2;
    for(int i=0;i<n;i++) {
        arr[i].i=i;
        scanf("%d",&arr[i].n);
    }
    sort(arr,arr+n,cmp);
    int mx=0;
    for(int i=0;i<n;i++) {
        r(b+arr[i].i,1);
        int t=f(b,b+arr[i].i-1,0);
        mx=t+1>mx?t+1:mx;
    }
    printf("%d",mx);
}