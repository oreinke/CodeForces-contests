#include <bits/stdc++.h>

using namespace std;

long long dfs(int row, int col, int d, bool up, vector<vector<int>> &holds, map<pair<int, int>, long long> &horiz, map<pair<int, int>, long long> &vert) {
    long long res = 0;
    if (vert.find({row, col}) != vert.end()) {
        res += vert[{row, col}];
    }
    else {
        for (int r = row + 1; r < holds.size() && r <= d; ++r) {
            for (int i = 0; i < holds[r].size(); ++i) {
                if (((holds[r][i] - holds[row][col]) * (holds[r][i] - holds[row][col]) + (r - row) * (r - row)) <= (d * d)) {
                    res = (res + dfs(r, i, d, true, holds, horiz, vert) % 998244353);
                }
            }   
        }
        vert[{row, col}] = res;
    }

    if (up) {
        if (horiz.find({row, col}) != horiz.end()) {
            res = (res + horiz[{row, col}]) % 998244353;
        }
        else {
            long long horizRes = 0;
            for (int i = 0; i < holds[row].size(); ++i) {
                if (i == col) continue;
                if (((holds[row][i] - holds[row][col]) * (holds[row][i] - holds[row][col])) <= (d * d)) {
                    horizRes = (horizRes + dfs(row, i, d, false, holds, horiz, vert)) % 998244353;
                }
            }
            horiz[{row, col}] = horizRes;
            res = (res + horizRes) % 998244353;
        }
    }

    return res;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, d; cin >> n >> m >> d;
        vector<vector<int>> holds (n);
        for (int i = 0; i < n; ++i) {
            string str; cin >> str;
            for (int j = 0; j < m; ++j) {
                if (str[j] == 'X') holds[i].push_back(j);
            }
        }

        reverse(holds.begin(), holds.end());
        cout << "-------------------------------\n";
        for (vector<int> arr : holds) {
            for (int num : arr) cout << num << " ";
            cout << endl;
        }
        cout << "-------------------------------\n";


        map<pair<int, int>, long long> vert, horiz;    
        for (int i = 0; i < holds[n - 1].size(); ++i) {
            vert[{n - 1, i}] = 1;
        }

        long long cnt = 0;
        for (int i = 0; i < holds[0].size(); ++i) {
            cnt = (cnt + dfs(0, i, d, true, holds, horiz, vert)) % 998244353;
        }

        cout << cnt << endl;
    }
}