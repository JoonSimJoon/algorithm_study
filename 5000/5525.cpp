//#include <stdio.h>
//#include <vector>
//std::vector<int> v;
//int n, m,cnt;
//char s[2000010];
//int main() {
//	scanf("%d %d", &n, &m);
//	scanf("%s", s);
//	for (int i = 0; i < m; i++) {
//		if (s[i] == 'i') {
//			int k = 1;
//			while(i+k<m) {
//				if (k % 2 == 0 && s[i + k] != 'i') {
//					i = i + k-1;
//					break;
//				}
//				else if (k % 2 == 1 && s[i + k] != 'o') {
//					i = i + k-1;
//					break;
//				}
//				k++;
//			}
//			v.push_back((k - 1) / 2);
//		}
//	}
//	int vl = v.size();
//	for (int i = 0; i < vl; i++) {
//		if (n <= v[i]) {
//			cnt += v[i] - n + 1;
//		}
//	}
//	printf("%d\n", cnt);
//	return 0;
//}
#include <stdio.h>
#include <vector>
std::vector<int> v;
int N, M, cnt;
int length;
char S[2000010];
int main() {
	scanf("%d %d", &N, &M);
	scanf("%s", S);
	for (int i = 1; i < M-1; i++) {
		if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
			length++;
			if (length == N) {
				length--;
				cnt++;
			}
			i++;
		}
		else length = 0;
	}
	printf("%d\n", cnt);
	return 0;
}