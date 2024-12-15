#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        int kLim = r2 / l1;

        int origK = k;
        vector<int> ks;
        ks.push_back(1);
        while (k <= kLim) {
            ks.push_back(k);
            k *= origK;
        }

        long long count = 0;

        for (int curK : ks) {
            int smallestMult = curK * l1;
            start = smallest + min(l2 % curK, curK - (l2 % curK));

        }

        cout << count << endl;
    }
}