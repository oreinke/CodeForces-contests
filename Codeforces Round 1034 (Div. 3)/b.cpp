#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, j, k; cin >> n >> j >> k;
        vector<int> a (n);
        for (auto &x : a) cin >> x;
        int val = a[j - 1];
        int cnt = 0;
        for (int num : a) if (num > val) cnt++;
        if ((k == 1) && cnt > k - 1) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
}