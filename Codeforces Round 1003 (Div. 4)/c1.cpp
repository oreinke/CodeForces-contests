#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        // cout << "-----------\n";
        int n, m; cin >> n >> m;
        vector<int> a (n);
        set<int> b;

        for (auto &x : a) cin >> x;
        for (int i = 0; i < m; ++i) {
            int x; cin >> x;
            b.insert(x);
        }

        bool nonD = true;
        if (*(b.begin()) - a[0] < a[0]) {
            a[0] = *b.begin() - a[0];
        }
        // printf("val a[0]: %d\n", a[0]);
        for (int i = 1; i < n && nonD; ++i) {
            auto it = b.lower_bound(a[i] + a[i - 1]);
            if (it != b.end()) {
                // printf("it: %d, a[%d]: %d, a[%d]: %d\n", *it, i, a[i],i - 1, a[i - 1]);
                if (a[i] >= a[i - 1]) {
                    a[i] = min(a[i], (*it) - a[i]);
                }
                else {
                    a[i] = (*it) - a[i];
                }  
            }
            // printf("val a[%d]: %d\n", i, a[i]);
            if (a[i] < a[i - 1]) nonD = false;
        }
        if (nonD) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}