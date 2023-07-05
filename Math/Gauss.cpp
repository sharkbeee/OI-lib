#include <bits/stdc++.h>
using namespace std;
typedef double db;
#define EPS 1e-8
int n; db a[105][105];
void Gauss() {
    for (int i = 0; i < n; i++) {
        int id = i;
        for (int j = i + 1; j < n; j++) if (abs(a[j][i]) > abs(a[id][i])) id = j;
        for (int j = 0; j <= n; j++) swap(a[i][j], a[id][j]);
        if (abs(a[i][i]) <= EPS) {
            /* No Solution */
            return;
        }
        for (int j = 0; j < n; j++) {
            for (int k = i + 1; i != j && k <= n ; k++)
                a[j][k] -= a[j][i] / a[i][i] * a[i][k];
        }
    }
}
int main() {
    Gauss();
    return 0;
}
