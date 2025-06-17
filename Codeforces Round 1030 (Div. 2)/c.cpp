#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ull k; cin >> k;
        vector<ull> a (n);
        for (auto &x : a) cin >> x;

        ull cost = 1;
        ull bit = 0;
        ull cnt = 0;
        ull num = 0;
        while (bit < 64) {
            for (int i = 0; i < n; ++i) {
                if (!(a[i] & ( ((ull) 1) << bit))) {
                    if (k >= cost) {
                        k -= cost;
                    // printf("Old a[%llu]: %llu\n", i, a[i]);
                        cnt++;
                    }
                }
                else {
                    // printf("a[%llu]: %d has bit in position %d\n", i, a[i], bit);
                    cnt++;
                }
            }
            bit++;
            num += cost;
            // printf("bit: %llu,bCnt of %llu: %llu\n", bit, num, __builtin_popcount(num));
            cost *= 2;

        }
        // ull res = 0;
        // for (ull num : a) res += __builtin_popcount(num);
        // printf("bCnt of %llu: %llu\n", num, __builtin_popcount(num));
        cout << cnt << endl;
        // cout << "----------------------------------------\n";
    }
}