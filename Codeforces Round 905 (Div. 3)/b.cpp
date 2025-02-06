#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        map<char, int> letters;
        
        for (int i = 0; i < n; ++i) {
            letters[str[i]]++;
        }

        int oddCnt = 0;
        for (auto [x, y] : letters) {
            if (y % 2 == 1) oddCnt++;
        }

        if ((str.length() - k) % 2 == 1) {
            oddCnt--;
            if (oddCnt > k) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            if (oddCnt > k || ((k - oddCnt) % 2) == 1) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
}