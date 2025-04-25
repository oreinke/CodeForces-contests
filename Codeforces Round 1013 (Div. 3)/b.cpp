#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;    
        vector<int> arr;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num >= k) {
                cnt++;
            }
            else{
                arr.push_back(num);
            }
        }

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int s = 0;
        int stren = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (s == 0) {
                s++;
                stren = arr[i];
            }
            else {
                s++;
                stren = arr[i];
                if (stren * s >= k) {
                    cnt++;
                    s = 0;
                }
            }
        }
        cout << cnt << endl;
    }
}