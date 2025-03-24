#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 == 0) {
                    cout << "##";
                }
                else {
                    cout << "..";
                }
            }
            cout << endl;
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 == 0) {
                    cout << "##";
                }
                else {
                    cout << "..";
                }
            }
            cout << endl;
        }
    }
}