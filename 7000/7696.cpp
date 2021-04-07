#include <stdio.h>
#include <vector>
#define LL long long
std::vector<LL> v;
LL cnt = 1;
int main() {
	for (LL i = 1; ; i++) {
		if (cnt > 1000000) break;
		else {
			LL k = i;
			int visited[11] = { 0, };
			while (k > 0) {
			//	printf("%d~\n", i);
				visited[k % 10]++;
				if (visited[k % 10] >= 2) {
					k = -1; break;
				}
				k /= 10;
			}
			if (k != -1) {
				v.push_back(i);
				cnt++;
			}
		}
	}

	while (1) {
		LL N;
		scanf("%lld", &N);
		if (N == 0) {
			break;
		}
		else {
			printf("%lld\n", v[N - 1]);
		}
	}
	return 0;
}