#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y, k; cin >> x >> y >> k;
        x = (x / k) + ((x % k == 0) ? 0 : 1);
        y = (y / k) + ((y % k == 0) ? 0 : 1);
        if (y >= x) {
            cout << y * 2 << endl;
        }
        else {
            cout << x * 2 - 1 << endl;
        }
    }
}