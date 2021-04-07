#include <stdio.h>
#include <string.h>

int T, ans = 1;
char arr[100010][6];


int main() {
	scanf("%d", &T);
	for (int ttt = 0; ttt < T; ttt++) {
		int mx = 100, cnt = 0;
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", arr[i]);
		}
		if (N >= 33) printf("0\n");
		else {
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					for (int k = j + 1; k < N; k++) {
						cnt = 0;
						if (arr[i][0] != arr[j][0])cnt++;
						if (arr[i][1] != arr[j][1])cnt++;
						if (arr[i][2] != arr[j][2])cnt++;
						if (arr[i][3] != arr[j][3])cnt++;
						if (arr[k][0] != arr[j][0])cnt++;
						if (arr[k][1] != arr[j][1])cnt++;
						if (arr[k][2] != arr[j][2])cnt++;
						if (arr[k][3] != arr[j][3])cnt++;
						if (arr[i][0] != arr[k][0])cnt++;
						if (arr[i][1] != arr[k][1])cnt++;
						if (arr[i][2] != arr[k][2])cnt++;
						if (arr[i][3] != arr[k][3])cnt++;
						if (cnt < mx) mx = cnt;
					}
				}
			}
			printf("%d\n", mx);
		}
	}
	return 0;
}