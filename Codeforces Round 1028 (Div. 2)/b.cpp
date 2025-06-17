#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    vector<ll> pow2 (300001);
    pow2[0] = 1;
    for (int i = 1; i < 300001; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % 998244353;
    }


    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p (n), q (n);
        for (auto &x : p) cin >> x;
        for (auto &x : q) cin >> x;
        
        int largest = -1, indp = -1, indq = -1;
        for (int i = 0; i < n; ++i) {
            ll ans = 0;
            if (p[i] > largest) {
                largest = p[i];
                indp = i;
                indq = -1;
            }
            else if (p[i] == largest) {
                indp = i;
            }

            if (q[i] > largest) {
                largest = q[i];
                indq = i;
                indp = -1;
            }
            else if (q[i] == largest) {
                indq = i;
            }
            
            if (indp == -1 || indq == -1) {
                if (indp == -1) {
                    ans = (pow2[q[indq]] + pow2[p[i - indq]]) % 998244353;
                }
                else {
                    ans = (pow2[p[indp]] + pow2[q[i - indp]]) % 998244353;

                }
            }
            else {
                int bigS = max(q[i - indp], p[i - indq]);
                ans = (pow2[largest] + pow2[bigS]) % 998244353;
            }
            

            cout << ans << " ";
        }
        cout << endl;     
    }
}