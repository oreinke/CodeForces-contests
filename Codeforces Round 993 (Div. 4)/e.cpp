// Major contest error was rushing to implement before looking to reduce further.
// We failed to find subsituting x/k^n for y into l2 <= y <= r2,
// and then merging this with the bound for x.
// this would give a inequality for x where all valid x are valid members of the language
// k^n can be atmost 32 diff numbers due to constraints, basically netting a O(1) sol.

// BIG NOTE: Never use ceil. Floating point errors will occur.
// instead we used: int lb = l2 / curK + ((l2 % curK == 0) ? 0 : 1);
// same result, no fp bs

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        unsigned long long k; 
        int l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        int origK = k;
        vector<int> ks;
        ks.push_back(1);
        while (k <= r2) {
            ks.push_back((int) k);
            k *= origK;
        }

        long long count = 0;
        for (int curK : ks) {
            int lb = l2 / curK + ((l2 % curK == 0) ? 0 : 1);
            lb = max(l1, lb);
            int rb = min(r1, r2 / curK);
            if (rb - lb >= 0) {
                count += rb - lb + 1;
            }
        }

        cout << count << endl;
    }
}