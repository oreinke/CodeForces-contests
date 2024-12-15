#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        long long sum1 = 0;
        long long rem1 = 0;
        long long div1 = n / 2 + (n % 2);

        long long sum2 = 0;
        long long rem2 = 0;
        long long div2 = n / 2;

        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            if (i % 2 == 1) {
                rem1 += num;
                sum1 += rem1 / div1;
                rem1 %= div1;
            }
            else {
                rem2 += num;
                sum2 += rem2 / div2;
                rem2 %= div2;
            }
            
        }

        // cout << "rem1: " << rem1 << " , sum1: " << sum1 << " div1: " << div1 << endl; 
        // cout << "rem2: " << rem2 << " , sum2: " << sum2 << " div2: " << div2 << endl; 
        if (rem1 == 0 && rem2 == 0 && sum1 == sum2) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}