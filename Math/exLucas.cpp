#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll qpow(ll x, ll y, ll p) {
    ll res = 1, t = x;
    while (y) {
        if (y & 1) res = (res * t) % p;
        t = (t * t) % p, y >>= 1;
    } return res;
}
ll inv(ll a, ll p) { ll x, y; exgcd(a, p, x, y); return (p + x % p) % p; }
ll CRT(ll a, ll b, ll p) { return (a * (p / b) % p) * inv(p / b, b) % p; }
ll fac(ll n, ll p, ll k) {
    if (!n) return 1;
    ll res = 1;
    for (ll i = 2; i <= k; i++) if (i % p) res = (res * i) % k;
    res = qpow(res, n / k, k);
    for (ll i = 2; i <= n % k; i++) if (i % p) res = (res * i) % k;
    return res * fac(n / p, p, k) % k;
}
ll C(ll n, ll m, ll p, ll k) {
    if (n < m) return 0;
    ll u = fac(n, p, k), v = fac(m, p, k), w = fac(n - m, p, k), cnt = 0;
    for (ll i = p; i <= n; i *= p) cnt += n / i;
    for (ll i = p; i <= m; i *= p) cnt -= m / i;
    for (ll i = p; i <= n - m; i *= p) cnt -= (n - m) / i;
    return u * inv(v, k) % k * inv(w, k) % k * qpow(p, cnt, k) % k;
}
ll exLucas(ll n, ll m, ll p) {
    ll t = p, ans = 0;
    for (int i = 2; i <= t / i; i++)
        if (t % i == 0) {
            ll res = 1;
            while (t % i == 0) t /= i, res *= i;
            ans = (ans + CRT(C(n, m, i, res), res, p)) % p;
        }
    if (t > 1) ans = (ans + CRT(C(n, m, t, t), t, p)) % p;
    return ans;
}
int main() {
    ll n, m, p;
    cin >> n >> m >> p;
    cout << exLucas(n, m, p);
    return 0;
}
