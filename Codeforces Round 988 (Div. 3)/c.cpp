#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int num;
        cin >> num;
        if (num < 5) {
            cout << "-1\n";
        }
        else {
            for (int i = 7; i <= num; i += 2) {
                cout << i << " ";
            }
            cout << "1 3 5 4 2 ";
            for (int i = 6; i <= num; i += 2) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}