#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef pair<int, int> pii;
struct Edge {
    int u, v, w, next;
} e[N << 1];
int n, m, pos, head[N], dis[N], vis[N];
void add(int u, int v, int w) {
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
void dij(int st) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<pii> q;
    q.push({0, st}), dis[st] = 0;
    while (q.size()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue; vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (dis[v] > dis[u] + w) q.push({dis[v] = dis[u] + w, v});
        }
    }
}
int main() {
	cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dij(1);
    return 0;
}
