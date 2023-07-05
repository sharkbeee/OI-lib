#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, sz;
struct Mat {
    ll data[11][11];
    Mat() { memset(data, 0, sizeof data); }
    ll* operator[](ll x) { return data[x]; }
    Mat operator*(Mat t) {
        Mat res;
        for (int i = 1; i <= sz; i++)
            for (int j = 1; j <= sz; j++)
                for (int k = 1; k <= sz; k++)
                    res[i][j] = (res[i][j] + data[i][k] * t[k][j]) % mod;
        return res;
    }
    Mat operator^(ll y) const {
        Mat res, base;
        for (int i = 1; i <= sz; i++) res[i][i] = 1;
        memcpy(base.data, res.data, sizeof base.data);
        while (y) {
            if (y & 1) res = res * base;
            base = base * base, y >>= 1;
        } return res;
    }
};

int main() {
    Mat f, mat;
    return 0;
}
