#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cCount = 1;

int minReduction (vector<int> &nums, int start, int target, vector<int> &dp) {
    // printf("Called! cnt: %d, start: %d\n", cCount, start); cCount++; fflush(stdout);
    if (start == target) return 0;
    if (start < target) return 1e9;
    if (dp[start] != -1) return dp[start];

    int res = 1e9;
    for (int num : nums) {
        int nStart = gcd(start, num);
        if (nStart == start || nStart < target) continue;
        res = min(res, minReduction(nums, nStart, target, dp));
    }
    dp[start] = res + 1;
    return res + 1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums (n), dp(5001, -1);
        for (auto &x : nums) cin >> x;
        int target = nums[0];
        for (int i = 1; i < n; ++i) {
            target = gcd(target, nums[i]);
        }
        // printf("target: %d\n", target); fflush(stdout);
        int tCount = 0;
        int reduc = 1e9;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) tCount++;
            reduc = min(reduc, minReduction(nums, nums[i], target, dp));
        }

        if (tCount > 0) {
            printf("%d\n", n - tCount);
        }
        else {
            printf("%d\n", n + reduc -1);
        }
    }
}