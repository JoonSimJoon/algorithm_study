#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 2001;
int N;
int cache[MAX][MAX];
vector<int> num;

int go(int i, int j){
    if (i > j) return 0;
    else if (i == j) return 1;

    int &ret = cache[i][j];
    if (ret != -1) return ret;
    ret = 2;

    int d = num[j] - num[i];
    int nxt = num[j] + d;

    int idx = lower_bound(num.begin(), num.end(), nxt) - num.begin();

    if (num[idx] == nxt) return ret = go(j, idx) + 1;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());

    int ans = 1;
    int cnt = 1;
    for (int i = 1; i <= N; i++){
        if (num[i] == num[i - 1]){
            ans = max(ans, ++cnt);
        }
        else cnt = 1;
    }

    num.erase(unique(num.begin(), num.end()), num.end());
    //같은 수들 지워줌
    
    int N = num.size();
    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N; j++){
            ans = max(ans, go(i, j));
        }
    }

    cout << ans << endl;
    return 0;
}