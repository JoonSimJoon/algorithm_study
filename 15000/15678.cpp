#include <bits/stdc++.h>
 
using namespace std;
 
int N, D;
long long a[100000], dp[100000];
deque<pair<long long, long long>> q;
 
int main()
{
    cin >> N >> D;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
    {
        dp[i] = a[i];
        while (!q.empty() && q.front().first < i - D)
            q.pop_front();
        if (!q.empty())
            dp[i] = max(dp[i], q.front().second + a[i]);
        while (!q.empty() && q.back().second < dp[i])
            q.pop_back();
        q.push_back(make_pair(i, dp[i]));
    }
    cout << *max_element(dp, dp + N);
}