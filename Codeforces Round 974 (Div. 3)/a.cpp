#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n, k;
        cin >> n >> k;

        int wallet = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num >= k) {
                wallet += num;
            }
            else if (num == 0 && wallet > 0) {
                count++;
                wallet--;
            }
        }

        cout << count << endl;
    }
}