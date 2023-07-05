#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N = 1e5 + 5;
struct node {
    int l, r, sum, minx, maxx, tag1, tag2 = inf;
} t[N << 2];
int n, m, a[N];
void pushup(int p) {
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
    t[p].minx = min(t[p << 1].minx, t[p << 1 | 1].minx);
    t[p].maxx = max(t[p << 1].maxx, t[p << 1 | 1].maxx);
}
void add_sum(int p, int k) {
    t[p].sum += (t[p].r - t[p].l + 1) * k;
    t[p].minx += k, t[p].maxx += k, t[p].tag1 += k;
}
void add_cov(int p, int k) {
    t[p].sum = (t[p].r - t[p].l + 1) * k;
    t[p].minx += k, t[p].maxx += k;
    t[p].tag1 = 0, t[p].tag2 = k;
}
void pushdown(int p) {
    if (t[p].tag2 != inf) add_cov(p << 1, t[p].tag2), add_cov(p << 1 | 1, t[p].tag2), t[p].tag2 = inf;
    if (t[p].tag1) add_sum(p << 1, t[p].tag1), add_sum(p << 1 | 1, t[p].tag1), t[p].tag1 = 0;
}
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) { t[p].sum = t[p].minx = t[p].maxx = a[l]; return; }
    int mid = l + r >> 1; build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r), pushup(p);
}
void update_sum(int p, int l, int r, int k) {
    if (l <= t[p].l && t[p].r <= r) { add_sum(p, k); return; }
    pushdown(p); int mid = t[p].l + t[p].r >> 1;
    if (l <= mid) update_sum(p << 1, l, r, k);
    if (r > mid) update_sum(p << 1 | 1, l, r, k);
    pushup(p);
}
void update_cov(int p, int l, int r, int k) {
    if (l <= t[p].l && t[p].r <= r) { add_cov(p, k); return; }
    pushdown(p); int mid = t[p].l + t[p].r >> 1;
    if (l <= mid) update_cov(p << 1, l, r, k);
    if (r > mid) update_cov(p << 1 | 1, l, r, k);
    pushup(p);
}
int query_sum(int p, int l, int r) {
    if (t[p].l > r || t[p].r < l) return 0;
    if (l <= t[p].l && t[p].r <= r) return t[p].sum;
    pushdown(p); int mid = t[p].l + t[p].r >> 1, res = 0;
    if (l <= mid) res += query_sum(p << 1, l, r);
    if (r > mid) res += query_sum(p << 1 | 1, l, r);
    return res;
}
int query_min(int p, int l, int r) {
    if (t[p].l > r || t[p].r < l) return 0;
    if (l <= t[p].l && t[p].r <= r) return t[p].minx;
    pushdown(p); int mid = t[p].l + t[p].r >> 1, res = inf;
    if (l <= mid) res = query_sum(p << 1, l, r);
    if (r > mid) res = min(res, query_sum(p << 1 | 1, l, r));
    return res;
}
int query_max(int p, int l, int r) {
    if (t[p].l > r || t[p].r < l) return 0;
    if (l <= t[p].l && t[p].r <= r) return t[p].maxx;
    pushdown(p); int mid = t[p].l + t[p].r >> 1, res = -inf;
    if (l <= mid) res = query_sum(p << 1, l, r);
    if (r > mid) res = max(res, query_sum(p << 1 | 1, l, r));
    return res;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    return 0;
}
