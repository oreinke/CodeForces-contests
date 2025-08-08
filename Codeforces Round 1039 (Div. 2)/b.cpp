#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            q.push_back(num);
        }

        string ans = "";
        bool inc = true;
        bool dec = false;
        q.pop_front();
        ans += 'L';
        while (q.size() > 1) {
            if (dec) {
                if (q.front() > q.back()) {
                    ans += "RL";
                    q.pop_back();
                    q.pop_front();
                    
                }
                else {
                    ans += "LR";
                    q.pop_back();
                    q.pop_front();
                }
                inc = true;
                dec = false;
            }
            else {
                if (q.front() > q.back()) {
                    ans += "LR";
                    q.pop_back();
                    q.pop_front();
                }
                else {
                    ans += "RL";
                    q.pop_back();
                    q.pop_front();
                }
                inc = false;
                dec = true;
            }
        }
        if (q.size() == 1) ans += 'L';
        cout << ans <<endl;
    }
}