#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int day = 0;
        int all3 = a + b + c;
        
        day += n / all3 * 3;
        n %= all3;

        int curDist = 0;
        while (n > 0) {
            if (curDist == 0) {
                n -= a;
            }
            else if (curDist == 1) {
                n -= b;
            }
            else {
                n -= c;
            }
            day++;
            curDist++;
            curDist %= 3;
        }
        cout << day << endl;
    }
}