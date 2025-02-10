#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main () {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ull> scores(n);
        ull resSum = 0;
        for (int i = 0 ; i < n; ++i) {
            ull score = 0;
            for (int k = 0; k < m; ++k) {
                ull x; cin >> x;
                score += x;
                resSum += x * (m - k);
            }
            scores[i] = score;
        }
        sort(scores.begin(), scores.end());
        reverse(scores.begin(), scores.end());
        ull res = 0;
        for (int i = 0; i < n; ++i) {
            res += scores[i] * (n - 1 - i) * m;
        }
        cout << res + resSum << endl;
    }
}
