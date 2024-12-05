#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, k;
        cin >> n >> k;
        k = max(0, n - k);
        
        int numOdd = (n / 2 + n % 2) - (k / 2 + k % 2);
        if (numOdd % 2 == 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}