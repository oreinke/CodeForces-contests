#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        int num = n;
        for (int i = 1; i <= n; i++) {
            // cout << "i: " << i << endl;
            string s;
            cin >> s;
            sum += s.length();
            if (n == num && sum > m) {
                num = i - 1;
            }
        }
        cout << num << endl;
    }
}