#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        string end = "AM";
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        if (h >= 12) {
            end = "PM";
            h %= 12;
        }
        if (h == 0) h = 12;
        if (h < 10) cout << "0";
        cout << h << s.substr(2, 3) << " " << end << endl;
    }
}