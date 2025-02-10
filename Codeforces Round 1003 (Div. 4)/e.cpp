#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main () {
    int t; cin >> t;
    while (t--) {
        int x, y, k; cin >> x >> y >> k;
        string res = "";
        if (abs(x - y) > k) {
            // cout << "F1\n";
            cout << "-1\n";
        }
        else {
            if (x > y) {
                if (x < k) {
                    // cout << "F2\n";
                    res = "-1";
                    x = -1;
                    y = -1;
                }
                else {
                    for (int i = 0; i < k; ++i) {
                        res += '0';
                    }
                    x -= k;
                    for (int i = 0 ; i  < min(y, k); ++i) {
                        res += '1';
                    }
                    y -= k;

                    for (int i = 0; i < x; ++i) {
                        res += '0';
                    }
                    for (int i = 0; i < y; ++i) {
                        res += '1';
                    }

                }
            }
            else {
                if (y < k) {
                    // printf("y: %d, k: %d\n", y, k);
                    // cout << "F3\n";
                    res = "-1";
                    x = -1;
                    y = -1;
                }
                else {
                    for (int i = 0; i < k; ++i) {
                        res += '1';
                    }
                    y -= k;
                    for (int i = 0 ; i  < min(x, k); ++i) {
                        res += '0';
                    }
                    x -= k;

                    for (int i = 0; i < y; ++i) {
                        res += '1';
                    }
                    for (int i = 0; i < x; ++i) {
                        res += '0';
                    }
                }
            }
            
            // cout << "F5\n";
            cout << res << endl;
        }
        

    }
}