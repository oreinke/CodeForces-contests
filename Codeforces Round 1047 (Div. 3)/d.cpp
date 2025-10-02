#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a (n), cnt (n + 1, 0), curNum (n + 1, 0);
        for (auto &x : a) cin >> x;
        for (int num : a) cnt[num]++;
    
        bool valid = true;
        for (int i = 1; i <= n && valid; ++i) 
            if (cnt[i] % i != 0) valid = false;
        if (valid) {
            int num = 1;
            for (int i = 0; i < n && valid; ++i) {
                if (cnt[a[i]] % a[i] == 0) {
                    curNum[a[i]] = num++;
                }
                printf("%d ", curNum[a[i]]);
                cnt[a[i]]--;
            }
        }
        else {
            printf("-1");
        }
        printf("\n");
    }
}