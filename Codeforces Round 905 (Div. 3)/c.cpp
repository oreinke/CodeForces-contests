#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int best = k;
        int nEven = 0;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num % k == 0) {
                best = 0;
            }
            best = min(best, k - (num % k));

            if (num % 2 == 0) nEven++;
        }

        if (k == 4) {
            best = min(best, ((nEven >= 2) ? 0 : 2 - nEven));
        }
        cout << best << endl;
    }
}