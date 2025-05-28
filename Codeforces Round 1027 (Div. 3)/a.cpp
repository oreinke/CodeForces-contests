#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 0) {
            cout << "0 0\n";
        }
        else {
            int res = -1;
            int sqr = (int) sqrt(n);
            if (sqr * sqr == n) {
                cout << "0 " << sqr << endl;
            }
            else {
                cout << "-1\n";
            }
        }
    
    }
}