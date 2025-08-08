#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        int big = -1, lil = 1e9;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            big = max(big, num);
            lil = min(lil, num);
        }

        if (abs(big - s) < abs(lil - s)) {
            cout << abs(big - s) + big - lil <<endl;
        }
        else {
            cout << abs(lil - s) + big - lil <<endl;
        }
    }
}