#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, s, m;
        cin >> n >> s >> m;
        vector<int> times;
        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            times.push_back(s);
            times.push_back(e);
        }
        sort(times.begin(), times.end());

        int max = times[0];
        for (int i = 2; i < times.size(); i+=2) {
            if (max < times[i] - times[i - 1]) {
                max = times[i] - times[i - 1];
                if (max >= s) {
                    break;
                }
            }
        }
        if (max < m - times[times.size() - 1]) {
            max = m - times[times.size() - 1];
        }


        if (max >= s) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}