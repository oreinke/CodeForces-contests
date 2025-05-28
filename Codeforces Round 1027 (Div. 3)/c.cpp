#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int prev = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num > prev + 1) {
                cnt++;
                prev = num;
            }
        }
        cout << cnt << endl;
    }
}