#include <bits/stdc++.h>
using namespace std;
int n, m, g[5005][5005], dis[5005], vis[5005];
int prim() {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	int res = 0; dis[1] = 0;
	for (int i = 1; i <= n; i++) {
		int u = 0;
		for (int v = 1; v <= n; v++) if (!vis[v] && dis[v] < dis[u]) u = v;
		vis[u] = 1;
		for (int v = 1; v <= n; v++) if (!vis[v] && g[u][v] < dis[v]) dis[v] = g[u][v];
  	}
	for (int i = 1; i <= n; i++) res += dis[i];
  	return res;
}
int main() {
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	return 0;
}
