#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 5;
struct Edge {
   	int u, v, next;
} e[N << 1];
int n, m, idx, cid, cur, pos, head[N], dfn[N], low[N]; vector<int> bcc[N]; stack<int> s;
void add(int u, int v) {
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
void tarjan(int u, int rt) {
	dfn[u] = low[u] = ++idx, s.push(u);
	for (int i = head[u], res = 0; i; i = e[i].next) {
		int v = e[i].v;
		if (!dfn[v]) {
	    	tarjan(v, rt);
	    	if (low[v] >= dfn[u]) {
				++cid;
				do {
		    	  	cur = s.top(), s.pop(); bcc[cid].pb(cur);
		    	} while (cur != v);
			    bcc[cid].pb(u);
		  	}
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], dfn[v]);
  	}
}
int main() {
	cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      	int u, v; cin >> u >> v;
      	add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, i);
  	return 0;
}
