#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        int cnt = 0;
        for (char c : str) if (c == '1') cnt++;
        if (n >= k * 2 && cnt > k) {
            cout << "Bob\n";
        }
        else {
            cout << "Alice\n";
        }
    }
}