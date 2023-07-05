#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N], t[N];
int nxt[N];
void getNxt() {
	int len = strlen(t);
	for (int i = 1, j = 0; i < len; i++) {
		while (j && t[i] != t[j]) j = nxt[j - 1];
		if (t[i] == t[j]) j++;
		nxt[i] = j;
	}
}
void match() {
	int len1 = strlen(s), len2 = strlen(t);
	for (int i = 0, j = 0; i < len1; i++) {		
		while (j && s[i] != t[j]) j = nxt[j - 1];
		if (s[i] == t[j]) j++;
		if (j == len2) {
            /* match successfully */
            j = nxt[j - 1];
        }
	}
}
int main() {
    cin >> s >> t;
	getNxt(), match();
	return 0;
}
