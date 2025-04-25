#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int largestSolo = -1, smallestSolo = 1e9;
        int target = -1;
        bool bad = false, bHasVal = false;
        vector<int> a(n), b(n);
        for ( auto &x : a) cin >> x;
        for ( auto &x : b) cin >> x;
        for (int i = 0; i < n && !bad; ++i) {
            if (b[i] == -1) {
                largestSolo = max(largestSolo, a[i]);
                smallestSolo = min(smallestSolo, a[i]);
            }
            else {
                bHasVal = true;
                if (target != -1 && (a[i] + b[i]) != target) {
                    bad = true;
                }
                else {
                    target = a[i] + b[i];
                }
            }
        }

        if (!bad) {
            if (bHasVal) {
                if ((smallestSolo + k) < target || largestSolo > target) {
                    bad = true;
                }
                else {
                    cout << "1\n";
                }
            }
            else {
                if ((largestSolo - smallestSolo) > k) {
                    bad = true;
                }
                else {
                    cout << (smallestSolo + k - largestSolo + 1) << endl;
                }
            }
        }

        if (bad) cout << "0\n";
    }
}