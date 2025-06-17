#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int gelly = min(a, c);
        int flower = min(b, d);
        if (gelly < flower) {
            cout << "Flower\n";
        }
        else {
            cout << "Gellyfish\n";
        }
    }
}