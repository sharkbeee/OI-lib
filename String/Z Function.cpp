#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int Z[N]; char s[N];
void getZ() {
    int l = 0, r = 0, len = strlen(s);
    Z[0] = len;
    for (int i = 1; i < len; i++) {
        if (i <= r && Z[i - l] < r - i + 1) Z[i] = Z[i - l];
        else {
            Z[i] = max(0, r - i + 1);
            while (i + Z[i] < len && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        }
        if (r < i + Z[i] - 1) l = i, r = i + Z[i] - 1;
    }
}
int main() {
    cin >> s;
    getZ();
    return 0;
}
