#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << s.substr(0, s.size() - 2) << "i\n";
    }
}