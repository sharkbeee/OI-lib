#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
    int val, l, r, dist = 1;
} t[N];
int n, m, f[N], vis[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (t[x].val > t[y].val) swap(x, y);
    t[x].r = merge(t[x].r, y);
    if (t[t[x].l].dist < t[t[x].r].dist) swap(t[x].l, t[x].r);
    t[x].dist = t[t[x].r].dist + 1;
    return x;
}
int main() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i].val;
    for (int i = 1; i <= n; i++) f[i] = i;
    return 0;
}
