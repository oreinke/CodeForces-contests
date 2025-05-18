#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    // printf("t: %d\n", t); fflush(stdout);

    while (t--) {
        // printf("Here??\n"); fflush(stdout);

        int n; cin >> n;
        // printf("n: %d\n", n); fflush(stdout);
        vector<bool> seen (2 * n, false);
        vector<int> vals (2 * n - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num; cin >> num;
                // printf("num: %d\n", num); fflush(stdout);

                if(i == 0 || (i == n - 1 && j > 0)) {
                    vals[i + j] = num;
                    // cout << "assigned at: " << i << " " << j <<endl;
                    seen[num - 1] = true;
                }
            }
        }

        for (int i = 0; i < 2 * n; ++i) {
            if (!seen[i]) {
                cout << i + 1;
                break;
            }
        }
        for (int val : vals)  cout << " " << val;
        cout << endl;
        // printf("Here!"); fflush(stdout);
    }
    // printf("How???"); fflush(stdout);

}