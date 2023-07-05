#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, p, fac[1000008] = {1}, inv[1000008] = {1};
ll qpow(ll x, ll y) {
    ll res = 1, t = x;
    while (y) {
        if (y & 1) res = (res * t) % p;
        t = (t * t) % p, y >>= 1;
    } return res;
}
ll C(ll n, ll m) { return n < m ? 0 : fac[n] * inv[m] * inv[n - m] % p; }
ll Lucas(ll n, ll m) { return m ? C(n % p, m % p) * Lucas(n / p, m / p) % p : 1; }
int main() {
    ll n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= p + 5; i++)
    {
        fac[i] = fac[i - 1] * i % p;
        inv[i] = qpow(fac[i], p - 2);
    }
    cout << Lucas(n, m);
    return 0;
}
