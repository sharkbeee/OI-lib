#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll pos, p[N], g[N], phi[N];
bitset<100005> np;
void euler(ll n) {
	for (ll i = 2; i <= n; i++) {
		if (!np[i]) p[++pos] = i, g[i] = i, phi[i] = i - 1;
		for (ll j = 1; j <= pos && i * p[j] <= n; j++) {
			np[i * p[j]] = 1, g[i * p[j]] = p[j];
			if (i % p[j]) phi[i * p[j]] = phi[i] * (p[j] - 1);
			else {
				phi[i * p[j]] = phi[i] * p[j]; break;
			}
		}
	}
}
int main() {
	euler(1e5);
	return 0;
}
