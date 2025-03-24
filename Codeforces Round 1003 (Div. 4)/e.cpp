#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main () {
    int t; cin >> t;
    while (t--) {
        int x, y, k; cin >> x >> y >> k;
        string res = "";
        if (abs(x - y) > k || (x < k && y < k)) {
            // cout << "F1\n";
            cout << "-1\n";
        }
        else {
            char xChar = '0', yChar = '1';
            if (y > x) {
                xChar = '1';
                yChar = '0';
                int buf = x;
                x = y;
                y = buf;
            }
            while (x > k) {
                for (int i = 0; i < k; ++i) res += xChar;
                for (int i = 0; i < min(y, k); ++i) res += yChar;
                
                x -= k;
                y -= k;
            }
            for (int i = 0; i < x; ++i) res += xChar;
            for (int i = 0; i < y; ++i) res += yChar;
            cout << res << endl;
        }
        

    }
}