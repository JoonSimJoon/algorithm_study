#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
#define MOD 1000000007

struct line {
    int x;
    int l, r;
    int start;
};

bool comp(const line& a, const line& b) {
    return a.x < b.x;
}

vector<line> v;

ll sum[200001];
ll cnt[200001];

// left, right : 업데이트 할 선분의 왼쪽, 오른쪽 위치
// value : 시작하는 선분이면 1, 끝나는 선분이면 -1
// node_idx : 노드의 번호
// node_left, node_right : 노드가 담당하는 구간의 왼쪽과 오른쪽 값
void update(int left, int right, int value, int node_idx, int node_left, int node_right) {
    if (left > node_right || right < node_left) return;

    // cnt 배열 업데이트하기
    if (left <= node_left && node_right <= right) {
        cnt[node_idx] += value;
    }
    else{
        int mid = (node_left + node_right) / 2;
        update(left, right, value, node_idx * 2, node_left, mid);
        update(left, right, value, node_idx * 2 + 1, mid + 1, node_right);
    }

    // sum 배열 업데이트하기
    if (cnt[node_idx] != 0) {
        sum[node_idx] = node_right - node_left + 1;
    }
    else {
        if (node_left != node_right) sum[node_idx] = sum[node_idx * 2] + sum[node_idx * 2 + 1];
        else sum[node_idx] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
       int x1, x2, y1, y2;
       scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        v.push_back(line{x1, y1, y2, 1});
        v.push_back(line{x2, y1, y2, -1});
    }
    sort(v.begin(), v.end(), comp);

    ll res = 0;
    update(v[0].l, v[0].r - 1, v[0].start, 1, 0, 30000 - 1);
    for(int i = 1; i < 2 * n; i++) {
        res += (v[i].x - v[i - 1].x) * sum[1];
        update(v[i].l, v[i].r - 1, v[i].start, 1, 0, 30000 - 1);
    }
    cout << res;
}
