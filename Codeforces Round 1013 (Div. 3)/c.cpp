#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << -1 << endl;
        }
        else {
            for (int i = 1; i <= n; ++i) {
                printf("%d ", ((i + i - 2) % n + 1));
            }
            printf("\n");
        }

    }
}