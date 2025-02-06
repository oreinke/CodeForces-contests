#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int smol = c;
        if (a <= b && a <= c) {
            smol = a;
        }
        else if (b <= a && b <= c) {
            smol = b;
        }

        int sum = 100;
        if ( a % smol == 0 && b % smol == 0 && c % smol == 0) {
            sum = a / smol + b / smol + c / smol - 3;
            // cout <<"SUM: " <<sum << endl;
        }
        if (sum <= 3) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}