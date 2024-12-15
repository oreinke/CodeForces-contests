#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        string s;
        cin >> s;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == 'q') {
                cout << 'p';
            }
            else if (s[i] == 'p') {
                cout << 'q';
            }
            else {
                cout << 'w';
            }    
        }
        cout << endl;
    }
}