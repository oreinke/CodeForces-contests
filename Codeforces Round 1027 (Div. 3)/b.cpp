#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        // cout << "string: " << str << endl;
        int zeros = 0, ones = 0;
        for (char c : str) {
            if (c == '0') {
                zeros++;
            }
            else {
                ones++;
            }
        }
        while (k > 0) {
            // printf ("k: %d, ones: %d, zeros: %d\n",k, ones, zeros);
            if (ones > zeros) {
                ones -= 2;
            }
            else {
                zeros -= 2;
            }
            k--;
        }
            // printf ("k: %d, ones: %d, zeros%d\n",k, ones, zeros);

        if (ones == zeros) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}