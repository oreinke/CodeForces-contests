#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string x, y; cin >> x >> y;
        int found = -1;
        for (int i = 0; x.size() < y.size() * 100; ++i){

            if (x.find(y) < x.size()) {
                found = i;
                break; 
            }
            x = x + x;
            //cout << i << endl;
            //fflush(stdout);
        } 
        cout << found << endl;
    }

  
}