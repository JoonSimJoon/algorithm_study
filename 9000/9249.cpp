#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define Max 1<<20


string s1, s2, S;
int ans, h;
int pos[Max], sa[Max];
int d;
int N;
bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += d, j += d;
	return (i < N && j < N) ? pos[i]<pos[j] : i>j;
}

void SA() {
	N = S.size();
	for (int i = 0; i < N; i++) {
		pos[i] = S[i];
		sa[i] = i;
	}
	for (d = 1;; d *= 2) {
		int temp[Max] = { 0 };
		sort(sa, sa + N, cmp);
		for (int i = 0; i < N - 1; i++) temp[i+1] = temp[i] + cmp(sa[i], sa[i+1]);
		for (int i = 0; i < N; i++) pos[sa[i]] = temp[i];
		if (temp[N - 1] == N - 1) return;
	}
}
void LCP() {
	for (int i = 0,k=0; i < N; i++,k=max(k-1,0)) {
		if (pos[i] == N - 1) continue;
		for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k]; k++);
		if (ans < k && ((i<s1.size()&& sa[pos[i]+1]>=s1.size())||(i>=s1.size() && sa[pos[i]+1]<s1.size()))) {
			ans = k;
			h = i;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s1 >> s2;
	if (s1.size() < s2.size()) {
		swap(s1, s2);
	}
	S = s1 + '$' + s2;
	
	SA();
	LCP();
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%c", S[i + h]);
	}

}
