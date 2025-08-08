#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> b (n);
        for (auto &x : b) cin >> x;
        int m = b[0];

        bool possible = true;
        for (int i = 1; i < n && possible; ++i) {
            if (b[i] >= m * 2) possible = false;
            m = min(m, b[i]);
        }

        if (possible) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}