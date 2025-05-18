#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll total = k * n + (n * n - n) / 2;
        ll l = 1, r = n;
        while (r - l > 1) {
            // printf("l: %d, r: %d\n", l, r);
            ll m = (r + l) / 2;
            if (abs(2 * (k * m + m * (m - 1) / 2) - total) > 
                abs(2 * (k * (m - 1) + (m - 1) * (m - 2) / 2) - total)) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        cout << min(abs(2 * (k * l + l * (l - 1) / 2) - total), abs(2 * (k * r + r * (r - 1) / 2) - total)) << endl;
         
    }
}