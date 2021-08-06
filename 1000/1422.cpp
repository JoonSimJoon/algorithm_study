
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) {
    if (a.length() != b.length())
        return a.length() > b.length();
    return a > b;
}
bool cc(string a, string b) {
    return a + b > b + a;
}
 
int main() {
    string now;
    vector<string> nums, ans;
    int n, k;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> now;
        nums.push_back(now);
    }
    sort(nums.begin(), nums.end(), cmp);
    for (int i = k; i < n; i++)
        ans.push_back(nums.front());
    for (string i : nums)
        ans.push_back(i);
    sort(ans.begin(), ans.end(), cc);
    for (string i : ans)
        cout << i;
    return 0;
}