#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int sum = 0;
        int leftOver = 0;
        if (a >= m) {
            sum += m;
        }
        else {
            sum += a;
            leftOver += m - a;
        }

        if (b >= m) {
            sum += m;
        }
        else {
            sum += b;
            leftOver += m - b;
        }

        sum += min(leftOver, c);
        cout << sum << endl;
    }
}