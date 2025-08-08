#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a (n);
        for (auto &x : a) cin >> x;

        vector<int> pre (n), suf(n);
        pre[0] = a[0];
        suf[n - 1] = a[n - 1];
        for (int i = 1; i < n; ++i) pre[i] = min(pre[i - 1], a[i]);
        for (int i = n - 2; i >= 0; --i) suf[i] = max(suf[i + 1], a[i]);
        for (int i = 0; i < n; ++i) {
            if (pre[i] == a[i] || suf[i] == a[i]) {
                cout << "1";
            }
            else {
                cout << "0";
            }
        }
        cout << "\n";
    }
}
