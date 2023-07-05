#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
	int u, v, next;
} e[N << 1];
int n, pos, head[N], deep[N], st[N][21];
void add(int u, int v) {
	e[++pos] = {u, v, head[u]};
	head[u] = pos;
}
void dfs(int u, int fa = 0) {
	st[u][0] = fa, deep[u] = deep[fa] + 1;
	for (int i = 1; i <= __lg(deep[u]); i++) st[u][i] = st[st[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].next) if (e[i].v != fa) dfs(e[i].v, u);
}
int LCA(int u, int v) {
	if (deep[u] < deep[v]) swap(u, v);
	while (deep[u] != deep[v]) u = st[u][__lg(deep[u] - deep[v])];
	if (u == v) return u;
	for (int i = __lg(deep[u]); i >= 0; i--) if (st[u][i] != st[v][i]) u = st[u][i], v = st[v][i];
	return st[u][0];
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs(1);
	return 0;
}
