#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> cnt;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int num; cin >> num;
            cnt[num]++;
            if (res == 0 && cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1) res = i;
        }
        cout << res << endl;
    }
}