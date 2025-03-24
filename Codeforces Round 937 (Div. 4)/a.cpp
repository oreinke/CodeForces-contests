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
        if (a < b && b < c) {
            cout << "STAIR\n";
        }
        else if(a < b && b > c) {
            cout << "PEAK\n";
        }
        else {
            cout << "NONE\n";
        }
    }
}