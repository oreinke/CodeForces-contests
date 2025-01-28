#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi nums(n);
        for(auto &x : nums) cin >> x;
        int sub = min(nums[0], nums[1]);
        nums[0] -= sub;
        nums[1] -= sub;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] - min(nums[i], nums[i + 1]) >= nums[i - 1]) {
                int sub = min(nums[i], nums[i + 1]);
                nums[i] -= sub;
                nums[i + 1] -= sub;
            }
        }
        
        bool correct = true;
        //cout << nums[0] << " ";
        for (int i = 1; i < n && correct; ++i) {
            //cout << nums[i] << " "; 
            if (nums[i] < nums[i - 1]) {
                correct = false;
            }
        }
        //cout << endl;

        if (correct) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}