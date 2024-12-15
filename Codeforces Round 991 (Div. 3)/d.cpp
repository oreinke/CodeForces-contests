#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        string s;
        cin >> s;
        
        for (int i = 1; i < s.length(); i++){
            int j = i;
            while (j > 0 && s[j] - 1 > s[j - 1]) {
                char c = s[j - 1];
                s[j - 1] = s[j] - 1;
                s[j] = c;
                j--;
            }
        }
        cout << s << endl;
    }

}