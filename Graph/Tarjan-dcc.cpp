#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
	int u, v, next;
} e[N << 1];
int n, m, idx, cid, cur, pos = 1, head[N], dfn[N], low[N], dcc[N]; stack<int> s;
void add(int u, int v) {
	e[++pos] = {u, v, head[u]};
	head[u] = pos;
}
void tarjan(int u, int eid) {
	dfn[u] = low[u] = ++idx, vis[u] = 1, s.push(u);
	for (int i = head[u]; i; i = e[i].next) {
    	int v = e[i].v;
    	if (!dfn[v]) tarjan(v, i), low[u] = min(low[u], low[v]);
    	else if (i != (eid ^ 1)) low[u] = min(low[u], dfn[v]);
  	}
	if (low[u] == dfn[u]) {
		++cid;
		do {
			cur = s.top(), s.pop(), dcc[cur] = cid;
		} while (cur != u);
  	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		add(u, v), add(v, u);
	}
  	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, 0);
  	return 0;
}
