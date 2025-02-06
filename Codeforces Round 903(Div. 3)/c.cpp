#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> grid (n);
        for (auto &x : grid) cin >> x;
        ll totalChange = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                vector<int> letters;
                int x = i;
                int y = j;
                letters.push_back(grid[x][y]);
                letters.push_back(grid[y][n - 1 - x]);
                letters.push_back(grid[n - 1 - x][n - 1 - y]);
                letters.push_back(grid[n - 1 - y][x]);
                // printf("| %d, %d | %d, %d | %d, %d | %d, %d |\n", x, y, y, n -1 - x, n - 1 - x, n - 1 - y, n- 1- y, x);
                sort(letters.begin(), letters.end());

                totalChange += letters[3] - letters[0];
                totalChange += letters[3] - letters[1];
                totalChange += letters[3] - letters[2];
            }
        }
        cout << totalChange << endl;
    }
}