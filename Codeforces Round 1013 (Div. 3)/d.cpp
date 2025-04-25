#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        unsigned long long n, m, k; cin >> n >> m >> k;
        if (k <= (n * (m / 2) + (m % 2 == 1 ? n : 0))) {
            cout << "1!\n";
        }
        else {
            k -= (n * (m / 2) + (m % 2 == 1 ? n : 0));
            int cnt = (k / n) * 2;
            if (k % n != 0) cnt += 2;
            if (m % 2 == 1) cnt++;
            cout << cnt << endl;
        }
        

    }
}