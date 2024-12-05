#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++){
            int buf;
            cin >> buf;
            nums.push_back(buf);
        }
        sort(nums.begin(), nums.end());
        int score = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                score++;
                i++;
            }
        }
        cout << score << "\n";
    }
}