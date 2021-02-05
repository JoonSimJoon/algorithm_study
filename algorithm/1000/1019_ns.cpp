//dp n=n/10+m%10
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define LL long long
//vector<LL> v[11];
int arr[11];
LL N,tmp,k=1,ko=1;
int NL,flag=1;
int main() {
	scanf("%lld", &N);
	/*for (LL i = 1; i <= N; i++) {
		tmp = i;
		while (tmp > 0) {
			arr[tmp % 10]++;
			tmp = tmp / 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}*/
	//자릿수->9*자릿수-1->
	tmp = N;
	while (tmp > 0) {
		NL++;
		if (tmp % 10 != 9) flag = 0;
		tmp /= 10;
		
	}
	if (flag == 0) NL--;
	for (int j = 0; j < NL - 1; j++) {
		k *= 10;
		ko *= 10;
		ko++;
	}
	//N이 9*10^(NL-1)에 가까운 경우
	if (N-ko>ko*10+1-N) {
		for (int i = 1; i <= 9; i++) {
			arr[i] = k * NL;
		}
		arr[0] = k * NL - ko;

		for (LL i = ko * 9 + 1; i <= N; i++) {
			tmp = i;
			while (tmp > 0) {
				arr[tmp % 10]++;
				tmp = tmp / 10;
			}
		};
		for (int i = 0; i < 10; i++) {
			printf("%d ", arr[i]);
		}
	}
	else {
		for (int i = 1; i <= 9; i++) {
			arr[i] = k * NL;
		}
		arr[0] = k * NL - ko;

		for (LL i = ko * 9 + 1; i > N; i--) {
			tmp = i;
			while (tmp > 0) {
				arr[tmp % 10]--;
				tmp = tmp / 10;
			}
		};
		for (int i = 0; i < 10; i++) {
			printf("%d ", arr[i]);
		}
	}
	return 0;
}