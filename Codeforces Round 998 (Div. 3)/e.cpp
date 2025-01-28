#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m1, m2; cin >> n >> m1 >> m2;
        set<pair<int, int>> f;
        for (int i = 0; i < m1; ++i) {
            int u, v; cin >> u >> v;
            if (u <= v) {
                f.insert({u, v});
            }
            else {
                f.insert({v, u});
            }
        }
        int total = 0;
        for (int i = 0; i < m2; ++i) {
            int u, v; cin >> u >> v;
            if (u > v) {
                int temp = u;
                u = v;
                v = temp;
            }
            if (f.find({u, v}) == f.end()) {
                total++;
            }
            else {
                f.erase({u, v});
            }
        }
        total += f.size();
        cout << total << endl; 
            

    } 
}