#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
 
ll gcd(ll n, ll a)
{
	if (a == 0) return n;
	return gcd(a, n % a);
}
 
ll extended_euclid(ll n, ll a)
{
	vector<ll> Si = { 1, 0 };
	vector<ll> Ti = { 0, 1 };
	vector<ll> Ri = { n, a };
	ll Qi = n / a ;
	ll r1, r2, temp;
	while (1)
	{
		r2 = Ri[Ri.size() - 2];
		r1 = Ri[Ri.size() - 1];
		
		temp = r2 % r1;
		Ri.push_back(temp);
		if (temp==0) return Ti[Ti.size()-1];
		Qi = r2 / r1;
		Si.push_back(Si[Si.size() - 2] - Si[Si.size() - 1] * Qi);
		Ti.push_back(Ti[Ti.size() - 2] - Ti[Ti.size() - 1] * Qi);
 
	}
}
int main()
{
	ll n, a;
	cin >> n >> a;
 
	cout << n - a << " ";
	if (gcd(n, a) != 1)
	{
		cout << -1;
		return 0;
	}
 
	ll ret = extended_euclid(n, a);
	while (ret < 0)
	{
		ret += n;
	}
 
	cout << ret;
	return 0;
}