#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string str; cin >> str;
        int cnt = 0;
        for (char c : str) {
            if (c == '1') cnt++;
        }

        cout << (cnt * (n - 1)) + (n - cnt) << endl;
    }
}