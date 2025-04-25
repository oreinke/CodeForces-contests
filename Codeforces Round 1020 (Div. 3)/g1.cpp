#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 0; i < n -1 ; ++i) {
            int u, v; cin >> u >> v;
        }

        vector<int> vals (n);
        for (int i = 1; i <= n; ++i) {
            printf("? 1 1 %d\n", i); fflush(stdout);
            cin >> vals[i - 1];
        }
        // printf("here! 1\n");
        if (vals[0] == 1 || vals[0] == -1) {
            printf("! %d", vals[0]);
            for (int i = 1; i < n; ++i) {
                printf(" %d", vals[i] - vals[0]);
            }
            printf("\n"); fflush(stdout);
        }
        else {
            vector<int> pre (n);
            pre[0] = 0;
            for (int i = 1; i < n; ++i) {
                pre[i] = pre[i - 1] + vals[i];
            }

            printf("? 2 1\n"); fflush(stdout);
            int l = 2, r = n;
            while (l < r) {
                // printf("here! l: %d, r: %d\n", l, r);

                int m = (l + r) / 2;
                int res;
                printf("? 1 %d", (m - l + 1));
                for (int i = l; i <= m; ++i) printf(" %d", i);
                printf("\n");
                fflush(stdout);
                cin >> res;
                if (abs(res - (pre[m - 1] - pre[l - 2])) != 2 * (m - l + 1)) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }
            printf("? 2 1\n"); fflush(stdout);
            // printf("root: %d", l);
            printf("!");
            printf(" %d", vals[0] - vals[l - 1]);
            for (int i = 1; i < n; ++i) {
                if (i == l - 1) {
                    printf(" %d", vals[i]);
                }
                else {
                    printf(" %d", vals[i] - vals[0]);
                }
            }
            printf("\n"); fflush(stdout);
        }
    }
}