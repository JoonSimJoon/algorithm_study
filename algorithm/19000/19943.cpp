#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int tn;
int n;
int x[100100], h[101000];
int t;
ll a[100100], b[100100], p[100100], c, na, nb, m;

priority_queue<pair<int, int> >pq;
priority_queue<int>pq2;

void clearQ(priority_queue<int>& sq) {
	priority_queue<int> empty;
	swap(sq, empty);
}
void clearQ2(priority_queue<pair<int,int> >& sq) {
	priority_queue<pair<int, int> > empty;
	swap(sq, empty);
}
void push(){
	while (t > 0){
		if ((b[t - 1] - nb + na - a[t - 1] - 1) / (na - a[t - 1]) <= p[t - 1])t--;
		else break;
	}
	a[t] = na;
	b[t] = nb;
	if (!t) p[t] = -(1ll << 32);
	else p[t] = (b[t - 1] - nb + na - a[t - 1] - 1) / (na - a[t - 1]);
	t++;
}
void update(ll l){
	int pos = 0;
	for (int d = 1 << 16; d; d >>= 1)
	{
		if (pos + d >= t)continue;
		if (p[pos + d] > l)continue;
		pos += d;
	}
	c = -l * l + a[pos] * l + b[pos];
	m = max(m, -c);
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tn;
	while (tn--){
		cin >> n;
		clearQ2(pq);
		clearQ(pq2);
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> h[i];
			pq.push({ -x[i] + h[i],i });
		}
		m = 0;
		c = 0;
		t = 0;
		for (int i = 0; i < n; i++)
		{
			while (pq.top().second < i)pq.pop();
			if (pq.top().second != i)continue;
			if (pq2.size() && pq2.top() > x[i] + h[i])continue;
			na = 2 * (x[i] - h[i]);
			nb = c - 1ll * (x[i] - h[i]) * (x[i] - h[i]);
			push();
			update(x[i] + h[i]);
			pq2.push(x[i] + h[i]);
		}
		printf("%lld.%02lld\n", m / 4, m % 4 * 25);
	}
	return 0;
}