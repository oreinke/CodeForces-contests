#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a (n);
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int numMexes = 1;
        int mex = 0;
        while (cnt[mex]) mex++;

        int dups = 0;
        vector<int> nums;
        for (auto [x, y] : cnt) {
            dups += y;
            if (x < mex) {
                dups--;
                nums.push_back(y);
            }
        }

        sort(nums.begin(), nums.end());
        deque<int> maxMex;
        for(int num : nums) maxMex.push_back(num);
        printf("1");
        for (int i = 1; i <= n; ++i) {
            if (dups > 0) {
                dups--;
            }
            else {
                numMexes--;
            }

            while (!maxMex.empty() && maxMex.front() <= i) {
                maxMex.pop_front();
                numMexes++;
            }
            printf(" %d", numMexes);
        }
        printf("\n");

    }
}