#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool found = false;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) found = true;
        }
        if (found) cout << "1\n";
        else {
            cout << s.size() << endl;
        }
    }
}