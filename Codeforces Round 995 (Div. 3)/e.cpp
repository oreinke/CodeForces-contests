#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<unsigned long long> a (n), b(n);
        for (auto &x : a) cin >> x; 
        for (auto &x : b) cin >> x; 
        
        vector<pair<int, int>> ev;

        for (int x : a) {
            ev.emplace_back(x, 1);
        }
        
        for (int x : b) {
            ev.emplace_back(x, 2);
        }

        sort(ev.begin(), ev.end());


        unsigned long long profit = 0;
        int curB = 0;
        int cnt = n;
        for (int i = 0; i < 2 * n;) {
            auto [x, y] = ev[i];
            if (curB <= k) {
                profit = max(profit, x * 1uLL * cnt);
            }

            while (i < 2 * n && ev[i].first == x) {
                if (ev[i].second == 1) {
                    curB++;
                }
                else {
                    curB--;
                    cnt--;
                }
                ++i;
            }
        }

        cout << profit << endl;
    }
}