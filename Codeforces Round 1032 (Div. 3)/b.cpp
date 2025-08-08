#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string str; cin >> str;
        vector<int> freq (26, 0);
        for (char c : str) freq[c - 'a']++;
        bool found = false;
        for(int i = 0; i < 26; ++i) {
            if (freq[i] > 2) found = true;
            else if (freq[i] == 2) {
                if ((str[0] != ('a' + i) || str[n - 1] != ('a' + i))) found = true;
            }
        }
        if (found) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}