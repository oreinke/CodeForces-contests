#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int l, r, d, u; cin >> l >> r >> d >> u;
        if (l == r && r == d && d == u) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

}