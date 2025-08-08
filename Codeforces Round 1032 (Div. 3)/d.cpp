#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a (n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        vector<string> ops;
        bool change = true;
        while (change) {
            change = false;
            for (int i = 0; i < n; ++i) {
                if (a[i] > n) {
                    change = true;
                    int indA = i, indB = -1;
                    for (int j = 0; j < n; ++j) {
                        if (b[j] <= n) {
                            indB = j;
                            break;
                        }
                    }

                    while (indA > indB) {
                        int temp = a[indA];
                        a[indA] = a[indA - 1];
                        a[indA - 1] = temp;
                        ops.push_back("1 " + to_string(indA));
                        indA--;
                    }

                    while (indA < indB) {
                        int temp = a[indA];
                        a[indA] = a[indA + 1];
                        a[indA + 1] = temp;
                        ops.push_back("1 " + to_string(indA + 1));
                        indA++;
                    }

                    int temp = a[indB];
                    a[indB] = b[indB];
                    b[indB] = temp;
                    ops.push_back("3 " + to_string(indB + 1));
                    break;
                }
            }
        }

        change = true;
        while (change) {
            change = false;
            for (int i = 0; i < n - 1; ++i)
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                ops.push_back("1 " + to_string(i + 1));
                change = true;
            }
        }

        change = true;
        while (change) {
            change = false;
            for (int i = 0; i < n - 1; ++i)
            if (b[i] > b[i + 1]) {
                int temp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = temp;
                ops.push_back("2 " + to_string(i + 1));
                change = true;
            }
        }
        cout << ops.size() << endl;
        for (string str : ops) cout << str << endl;
    }
}