#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
	int u, v, next;
} e[N << 1];
int n, m, idx, cid, cur, pos, head[N], dfn[N], low[N], vis[N], scc[N]; stack<int> s;
void add(int u, int v) {
	e[++pos] = {u, v, head[u]};
	head[u] = pos;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++idx;
	vis[u] = 1, s.push(u);
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v), low[u] = min(low[u], low[v]);
		} else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++cid;
		do {
			cur = s.top(), s.pop();
			vis[cur] = 0, scc[cur] = cid;
		} while (cur != u); 
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v, add(u, v);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	return 0;
}
