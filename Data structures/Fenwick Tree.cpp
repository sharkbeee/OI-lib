#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], c1[N], c2[N];
void update(int x, int k) { for (int i = x; i <= n; i += (i & -i)) c1[i] += k, c2[i] += x * k; }
int query(int x) { int res = 0; for (int i = x; i; i &= (i - 1)) res += (x + 1) * c1[i] - c2[i]; return res; }
int main() {
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], update(i, a[i] - a[i - 1]);
    }
    return 0;
}
