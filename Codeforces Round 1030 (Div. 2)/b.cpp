#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << 2 * n - 1 << endl;
        cout << "1 1 " << n << endl;
        int len = 1;
        for (int i = 2; i <= n; ++i) {
            cout << i << " 1 " << len << endl;
            cout << i << " " <<  len + 1 << " " << n <<endl;
            len++;
        }
    }
}