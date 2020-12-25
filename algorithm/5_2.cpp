#include <stdio.h>
#include <algorithm>
using namespace std;
#define LL long long
struct s {
	LL x, y, h;
};
bool cp(s a, s b) {
	if (a.h == b.h) {
		if (a.x == b.x) return a.y < b.y;
		else return a.x < b.x;
	}
	else return a.h > b.h;
}
bool cpx(s a, s b) {
	if (a.h == b.h) {
		if (a.x == b.x) return a.y < b.y;
		else return a.x < b.x;
	}
	else return a.h < b.h;
}
int N;
s arr[1011],ans[1011];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld %lld", &arr[i].x, &arr[i].y, &arr[i].h);
	}
	sort(arr, arr + N, cp);
	
	for (int kkk = 0; kkk < N; kkk++) {
		ans[kkk] = arr[kkk];
		for (int i = 0; i < N; i++) {
			int tmp = abs(arr[i].x - ans[kkk].x) > abs(arr[i].y - ans[kkk].y) ? abs(arr[i].x - ans[kkk].x) : abs(arr[i].y - ans[kkk].y);
			if (ans[kkk].h - tmp < arr[i].h) {
				ans[kkk].h = arr[i].h + tmp;
			}
		}
	}
	sort(ans, ans + N, cpx);
	printf("%lld %lld %lld ", ans[0].x, ans[0].y, ans[0].h);
	return 0;
}
/*
int n;
int a[N], b[N], c[N];

int ans_x, ans_y, ans_h;

bool check(int h) {
   int minx(-1e9), maxx(1e9), miny(-1e9), maxy(1e9);
   for (int i = 0; i < n; i++) {
	  int fh = h - c[i];
	  minx = max(minx, -fh + a[i]);
	  maxx = min(maxx, +fh + a[i]);
	  miny = max(miny, -fh + b[i]);
	  maxy = min(maxy, +fh + b[i]);
   }
   if (minx <= maxx && miny <= maxy) {
	  ans_x = minx;
	  ans_y = miny;
	  ans_h = h;
	  return true;
   }
   return false;
}

int main() {
   fastio;
   cin >> n;
   for (int i = 0; i < n; i++) {
	  cin >> a[i] >> b[i] >> c[i];
   }

   int s = *max_element(c, c + n), e = 2e8;
   while (s <= e) {
	  int mid = s + e >> 1;
	  if (check(mid)) e = mid - 1;
	  else s = mid + 1;
   }

   cout << ans_x << ' ' << ans_y << ' ' << ans_h << endl;
}
*/