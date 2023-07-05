#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
    int u, v, w, next;
} e[N << 1];
int n, m, pos, head[N], dis[N], vis[N];
void add(int u, int v, int w) {
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
void SPFA(int st) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue<int> q; q.push(st), dis[st] = 0;
    while (q.size()) {
        int u = q.front(); q.pop(); vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next) {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) q.push(v);
            }
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
    SPFA(1);
    return 0;
}
