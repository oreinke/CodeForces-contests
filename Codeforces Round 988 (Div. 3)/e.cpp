#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;

    cin >> t;

    for (int tc = 0; tc < t; tc++) { 
        int n;
        cin >> n;

        int end = 2;
        int zeros = 0;
        while (end <= n) { 
            cout << "? 1 " << end << "\n";
            cout.flush()
            cin >> zeros;
            if (zeros > 0) {
                break;
            }
            else {
                end++;
            }
        }
        if (zeros == 0) {
            cout << "! IMPOSSIBLE\n";
        }
        else {
            string s;
            for (int i = 0; i < end - 1 - zeros; i++) {
                s += '1';
            }

            for (int i = 0; i < zeros; i++) {
                s += '0';
            }
            s += '1';
            
            long long cur = zeros;
            end++;
            while (end <= n) {
                int next;
                cout << "? 1 " << end << "\n";
                cout.flush()
                cin >> next;
                if (next > cur) {
                    s += '1';
                }
                else {
                    s += '0';
                }
                end++;
            }

            cout << "! " << s << "\n";
        }
    }
}