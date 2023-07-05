#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], st[N][21];
int query(int l, int r) {
    int s = __lg(r - l + 1);
    return min(st[l][s], st[r - (1 << s) + 1][s]);
}
int main() {
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], st[i][0] = a[i];
    for (int s = 1; s <= 20; s++)
        for (int i = 1; i + (1 << s) - 1 <= n; i++)
            st[i][s] = min(st[i][s - 1], st[i + (1 << (s - 1))][s - 1]);
    return 0;
}
