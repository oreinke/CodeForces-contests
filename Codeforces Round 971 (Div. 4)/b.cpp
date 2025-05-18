#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            string str; cin >> str;
            for (int j = 0; j < 4; ++j) 
                if (str[j] == '#') q.push_front(j + 1);
        }
        for (int i = 0; i < n; ++i) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << endl;
    }
}