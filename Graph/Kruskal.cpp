#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
    int u, v, w;
    bool operator<(const Edge t) const { return w < t.w; }
};
int n, m, pos, f[N];
vector<Edge> e;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int a, int b) { f[find(a)] = find(b); }
int kruskal() {
	int res = 0;
	sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 0; i < m; i++)
        if (find(e[i].u) != find(e[i].v)) {
            res += e[i].w, merge(e[i].u, e[i].v);
        }
    return res;
}
int main() {
	cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w; 
        e.push_back({u, v, w});
    }
    kruskal();
    return 0;
}
