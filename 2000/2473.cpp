#include<cstdio>
#include<algorithm>
using namespace std;
long long arr[5050], ans[3];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }
    sort(arr, arr + n);
    long long mini = 3 * 10e9 + 10;
    for (int i = 0; i < n - 2; i++) { //시작점 정하기
        int point1, point2;
        point1 = i + 1; point2 = n - 1;
        while (1) { // 투포인터
            if (point1 >= point2) break;
            long long x = arr[i] + arr[point1] + arr[point2];
            long long nx = x < 0 ? -x : x;
            if (mini > nx) {
                mini = nx;
                ans[0] = arr[i];
                ans[1] = arr[point1];
                ans[2] = arr[point2];
            }
            if (x > 0) {
                point2--;
            }
            else {
                point1++;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}
