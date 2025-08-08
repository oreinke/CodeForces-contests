#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long n, c; cin >> n >>  c;
        vector<long long> bags (n);
        for (auto &x : bags) cin >> x;
        sort(bags.rbegin(), bags.rend());

        int cnt = 0;
        for (auto bag : bags) {
            //printf("bag: %ld, c: %ld\n",bag, c * (long long) pow(2, cnt));
            if (bag * (long long) pow(2, cnt)<= (c )) cnt++;
        
        }
        cout << n - cnt << endl;
    }
}