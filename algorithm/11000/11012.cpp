#include<stdio.h>
#include<malloc.h>

const int sz = 1e5 + 2;
struct Node {
	int l, r, v;
};
Node segment[sz * 4 + 10000 * 17];
int seg_num, head[sz];
int* list[sz], size[sz], cap[sz];

void re(int idx, int y) {
	if (++size[idx] >= cap[idx]) {
		list[idx] = (int*)realloc(list[idx], sizeof(int) * (cap[idx] += 10));
	}
	list[idx][size[idx] - 1] = y;
}

int init(int l, int r) {
	int idx = ++seg_num;
	segment[idx] = { 0,0,0 };
	if (l < r) {
		int m = l + r >> 1;
		segment[idx].l = init(l, m);
		segment[idx].r = init(m + 1, r);
	}
	return idx;
}

int update(int n_idx, int l, int r, int target) {
	int idx = ++seg_num;
	segment[idx] = segment[n_idx];
	segment[idx].v++;
	if (l < r) {
		int m = l + r >> 1;
		if (target <= m) segment[idx].l = update(segment[idx].l, l, m, target);
		else segment[idx].r = update(segment[idx].r, m + 1, r, target);
	}
	return idx;
}

int query(int n_idx, int l, int r, int q_l, int q_r) {
	if (q_r < l || r < q_l) return 0;
	if (q_l <= l && r <= q_r) return segment[n_idx].v;
	int m = l + r >> 1;
	return query(segment[n_idx].l, l, m, q_l, q_r) +
		query(segment[n_idx].r, m + 1, r, q_l, q_r);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		seg_num = 0;
		for (int i = 0; i < sz; i++) head[i] = size[i] = 0;

		head[0] = init(1, sz - 1);
		int n, m;
		scanf("%d %d", &n, &m);
		while (n--) {
			int x, y;
			scanf("%d %d", &x, &y);
			x++, y++;
			re(x, y);
		}

		for (int i = 1; i < sz; i++) {
			head[i] = head[i - 1];
			for (int j = 0; j < size[i]; j++) {
				n = list[i][j];
				head[i] = update(head[i], 1, sz - 1, n);
			}
		}

		int res = 0;
		while (m--) {
			int l, r, b, t;
			scanf("%d %d %d %d", &l, &r, &b, &t);
			l++, r++, b++, t++;
			res += query(head[r], 1, sz - 1, b, t) - query(head[l - 1], 1, sz - 1, b, t);
		}
		printf("%d\n", res);
	}
}