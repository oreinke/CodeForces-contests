#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> a, b;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            a.insert(num);
        }
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            b.insert(num);
        }
        if (a.size() + b.size() > 3) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}