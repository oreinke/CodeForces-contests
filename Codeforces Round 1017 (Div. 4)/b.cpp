#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, l, r; cin >> n >> m >> l >> r;
        if (m == n) {
            cout << l << " " << r << endl;
        }
        else {
            int rBound = min (m, r - 1);
            m -= rBound;
            cout << -1 * m << " " << rBound <<endl;
        }
    }
}