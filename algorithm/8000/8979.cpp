#include <stdio.h>
int ol[1010][5], N, K, nd, cnt = 0;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nd);
		scanf("%d%d%d", &ol[nd][0], &ol[nd][1], &ol[nd][2]);
	}
	for (int i = 1; i <= N; i++) {
		if (ol[i][0] == ol[K][0]) {
			if (ol[i][1] == ol[K][1]) {
				if (ol[i][2] > ol[K][2]) {
					cnt++;
				}
			}
			else if (ol[i][1] > ol[K][1]) {
				cnt++;
			}
		}
		else if (ol[i][0] > ol[K][0]) {
			cnt++;
		}
	}
	printf("%d", cnt + 1);
	return 0;
}