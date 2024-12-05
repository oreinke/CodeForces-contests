#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    
    for (int tc = 0; tc < t; tc++) { 
        int n;
        cin >> n;

        long long total = 0;   
        vector<int> arr;
        for (int i = 0; i < n; i++) { 
            int num;
            cin >> num;
            total += num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());


        int threshold = arr[arr.size() / 2];
        if ( n < 3) {
            cout << "-1\n";
        }
        else if (total / (2 * n) > threshold || ((total % (2 * n) != 0) && total / (2 * n) >= threshold)) {
            cout << "0\n";
        }
        else {
            // cout << "Thresh: " << threshold << ", n: " << n << " , total: " << total << endl;
            cout << (threshold * (long long) n * 2 - total + 1) << endl;
        }



    }
}