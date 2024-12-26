#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> questions (m);
        for (int i = 0; i < m; i++) {
            cin >> questions[i];
        }
        
        set<int> mono;
        for (int i = 0; i < k; i++) {
            int num;
            cin >> num;
            mono.insert(num);
        }

        string str;
        if (k == n) {
            for (int i = 0; i < m; i++) {
                str.push_back('1');
            }
        }
        else if (k == n - 1) {
            for (int i : questions) {
                if (mono.find(i) != mono.end()) {
                    str.push_back('0');
                }
                else {
                    str.push_back('1');
                }
            }
        }
        else {
            for (int i = 0; i < m; i++) {
                str.push_back('0');
            }
        }
        cout << str << endl;

    }
}