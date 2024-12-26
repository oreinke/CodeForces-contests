#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<int> mono(n), stereo(n);
        for (int i = 0; i < n; i++) {
            cin >> mono[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> stereo[i];
        }

        int dif = 0;
        for (int i = 0; i < n - 1; i++) {
            dif += max(0, mono[i] - stereo[i + 1]);
        }
        dif += mono[n - 1];

        cout << dif << endl;
    }
}