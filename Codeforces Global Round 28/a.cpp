#include <bits/stdc++.h>

using namespace std;

// Stupid ass math bullshit 
// commented out part is original code.
// at each steps choose to -33 or get rid of as pair of 33
// however this is mathematically equivalent to -33 some power of 10 number of times
// so the answer is just n % 33 == 0 ? yes : no
// kms

// bool rem2(int, map<int, bool>);
// bool check(int, map<int, bool>);

// bool rem2(int n, map<int, bool> dp) {
//     int lower = 0;
//     int places = 0;
//     bool retVal = false;
//     while (n > 9) {
//         if (n % 10 == 3 && (n % 100 / 10) == 3) {
//             retVal = retVal || check(((n / 100) * pow(10, places) + lower), dp);
//         }

//         lower += n % 10 * pow(10, places);
//         places++;
//         n /= 10;
//     }
//     return retVal;
// }


// bool check(int n, map<int, bool> dp) {
//     if (dp.find(n) != dp.end()) {
//         return dp[n];
//     }

//     if (n < 0) {
//         dp[n] = false;
//         return false;
//     }
//     if (n % 33 == 0) {
//         dp[n] = true;
//         return true;
//     }
    
//     while (n > 0) {

//     }

//     dp[n] = rem2(n, dp) || check(n - 33, dp);
//     return dp[n];
// }


int main() {
    int t;
    cin >> t;
    // map<int, bool> dp; 
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        // if (check(n, dp)) {
        //     cout << "yes\n";
        // }
        // else {
        //     cout << "no\n";
        // }
        if (n % 33 == 0) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}

