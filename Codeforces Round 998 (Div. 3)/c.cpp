#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        map<int, int> cnt;
        set<int> nums;
        for (int i = 0; i < n; ++i) {
            int offer; cin >> offer;
            cnt[offer]++;
            nums.insert(offer);
        }

        int total = 0;
        for (int i : nums) {
            // printf("adding %d on %d\n", min(cnt[k - i], cnt[i]), i);
            total += min(cnt[k - i], cnt[i]);
        }
        total /= 2;

        cout << total << endl;
        // int total = 0;
        // while (!nums.empty()) {
        //     // cout << "-------------\n";
        //     int alice = -1;
        //     for (int i : nums) {
        //         if (cnt[k - i] == 0 || ( i + i == k && cnt[i] == 1)) {
        //             alice = i;
        //             cnt[i]--;
        //             if (cnt[i] == 0) {
        //                 nums.erase(i);
        //             }
        //             break;
        //         }
        //     }
        //     if (alice == -1) {
        //         alice = *nums.begin();
        //         cnt[alice]--;
        //         if (cnt[alice] == 0) {
        //             nums.erase(alice);
        //         }
        //     }

        //     int bob = -1;
        //     if (cnt[k - alice] > 0) {
        //         bob = k - alice;
        //         cnt[bob]--;
        //         if (cnt[bob] == 0) {
        //             nums.erase(bob);
        //         }
        //     }
        //     else {
        //         for (int i : nums) {
        //             if (cnt[k - i] == 0 || ( i + i == k && cnt[i] == 1)) {
        //                 bob = i;
        //                 cnt[i]--;
        //                 if (cnt[i] == 0) {
        //                     nums.erase(i);
        //                 }
        //                 break;
        //             }
        //         }
        //     }

        //     if (bob == -1) {
        //         for (int i : nums) {
        //             if (cnt[k - i] < cnt[i]) {
        //                 bob = i;
        //                 cnt[i]--;
        //                 if (cnt[i] == 0) {
        //                     nums.erase(i);
        //                 }
        //                 break;
        //             }
        //         }
        //     }
        //     if (bob == -1) {
        //         int i = *nums.begin();
        //         bob = i;
        //         cnt[i]--;
        //         if (cnt[i] == 0) {
        //             nums.erase(i);
        //         }
        //     }
        //     // cout << "alice: " << alice << ", bob: " << bob << endl;
        //     if (bob + alice == k) total++;

        // }
        // cout << total <<endl;

    }
}