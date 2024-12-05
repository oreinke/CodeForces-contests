#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int p1, p2, o1, o2;
        cin >> p1 >> p2 >> o1 >> o2;
        int count = 0;
        if ((p1 > o1 && p2 >= o2) || (p1 >= o1 && p2 > o2)) {
            count+= 2;
        }

        if ((p1 > o2 && p2 >= o1) || (p1 >= o2 && p2 > o1)) {
            count+= 2;
        }

        cout << count << "\n";
    }
}