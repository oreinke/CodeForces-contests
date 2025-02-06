#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t-- ) {
        int n; cin >> n;
        vi arr (n);
        for (auto &x : arr) cin >> x;
        vi dp (n);
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (i + arr[i] + 1 == n) {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i + 1] + 1;
                if (i + arr[i] + 1 < n) {
                    dp[i] = min(dp[i], dp[i + arr[i] + 1]);
                }
            }
        }

        cout << dp[0] << endl;
    }
}