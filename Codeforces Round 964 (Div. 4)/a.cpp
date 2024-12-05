#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin>> n;
        cout  << n % 10 + n / 10 << "\n";
    }
}