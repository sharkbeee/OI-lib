#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, x, y, a[N], m[N];
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0; return a;
    }
    ll d = exgcd(b, a % b, y, x);
	y -= a / b * x;
    return d;
}
ll exCRT() {
    ll a1 = a[1], m1 = m[1], a2, m2;
    for (ll i = 2; i <= n; i++) {
        a2 = a[i], m2 = m[i];
        ll c = ((a2 - a1) % m2 + m2) % m2;
        ll g = exgcd(m1, m2, x, y), t = m2 / g;
        if (c % g) return -1;
        x *= c / g, x = (x % t + t) % t;
        a1 += x * m1, m1 *= t, a1 = (a1 % m1 + m1) % m1;
    }
    return a1;
}
int main() {
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> m[i] >> a[i];
    cout << exCRT();
    return 0;
}
