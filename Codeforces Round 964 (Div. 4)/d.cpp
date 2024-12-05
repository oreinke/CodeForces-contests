#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
     for (int tc = 0; tc < t; tc++) {
        string s, t;
        cin >> s >> t;
        string result = s;
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if (s[i] == '?') {
                result[i] = t[j];
                i++;
                j++;
            }
            else if (s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if (i >= s.size() && j < t.size()) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            while (i < s.size()) {
                if (s[i] == '?') {
                    result[i] = 'a';
                }
                i++;
            }
            cout << result << endl;
        }
     }

}