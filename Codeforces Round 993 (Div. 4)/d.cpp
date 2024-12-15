#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        set<int> unused;
        for (int i = 0; i < n; i++) {
            unused.insert(i + 1);
            int num;
            cin >> num;
            arr[i] = num;
        }
        for (int i = 0; i < n; i++) {
            if (unused.find(arr[i]) != unused.end()) {
                cout << arr[i] << " ";
                unused.erase(arr[i]);
            }
            else {
                auto it = unused.begin();
                int val = *it;
                cout << val << " ";
                unused.erase(val);
            }
        }
        cout << endl;
    }
}