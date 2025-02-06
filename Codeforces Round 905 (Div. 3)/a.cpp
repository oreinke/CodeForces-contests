#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        for (int i = 0; i < 4; ++i) {
            if (str[i] == '0') {
                str[i] = '9' + 1;
            }
        }
        int total = 4;
        total += abs('1' - str[0]);
        total += abs(str[0] - str[1]);
        total += abs(str[1] - str[2]);
        total += abs(str[2] - str[3]);
        cout << total << endl;
    }
}