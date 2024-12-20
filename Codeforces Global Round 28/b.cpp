#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, k;
        cin >> n >> k;
        int curNum = 1;
        vector<int> arr(n, 0);
        for (int i = k - 1; i < n; i += k) {
            arr[i] = curNum;
            curNum++;
        }
        for (int i = 0; i < n ; i++) {
            if (arr[i] == 0) {
                arr[i] = curNum;
                curNum++;
            }
        }

        for (int i : arr) {
            cout << i << " ";
        }  
        cout << endl;
    }
}