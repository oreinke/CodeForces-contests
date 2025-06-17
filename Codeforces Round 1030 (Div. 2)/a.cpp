#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < k; ++i) cout << "1";
        for (int i = k; i < n; ++i) cout << "0";
        cout << endl;
        
    }
}