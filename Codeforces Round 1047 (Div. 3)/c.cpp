#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
    //     ll num = b;
    //     int i = 2;
    //     vector<pair<int, int>> primes;
    //     while (num > 1 && i * i <= num) {

    //     }
    //     if 
        if (a % 2 + b % 2 == 2) {
            cout << a * b + 1 << endl;
        }
        else if (a % 2 + b % 2 == 1) {
            if (b % 2 == 0 && (b / 2) % 2 == 0) {
                cout << a * (b / 2) + 2 << endl;
            }
            else cout << "-1\n";
        }
        else {
            cout << a * (b / 2) + 2 << endl;
        }
    }

}