#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> grid (n, vector<int> (m));
        vector<pair<int, int>> maxi;
        int best = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] > best) {
                    best = grid[i][j];
                    maxi.clear();
                    maxi.push_back({i, j});
                }
                else if (grid[i][j] == best) {
                    maxi.push_back({i, j});
                }
            }
        }

        int maxCnt = 0, maxR = 0;
        map<int, int> cnt;
        for (auto [x, y] : maxi) {
            cnt[x]++;
            if (cnt[x] > maxCnt) {
                maxR = x;
                maxCnt = cnt[x];
            }
        }

        set<int> cntC;
        for (auto [x, y] : maxi) {
            if (x != maxR) cntC.insert(y);
        }

        if (cntC.size() < 2) {
            best--;
        }
        else {
            maxCnt = 0;
            int maxC = 0;
            map<int, int> cnt2;
            for (auto [x, y] : maxi) {
                cnt2[y]++;
                if (cnt2[y] > maxCnt) {
                    maxC = y;
                    maxCnt = cnt2[y];
                }
            }

            set<int> cntR;
            for (auto [x, y] : maxi) {
                if (y != maxC) cntR.insert(x);
            }
            if (cntR.size() < 2) best--;
        }
        cout << best << endl;

        
        
    }
}