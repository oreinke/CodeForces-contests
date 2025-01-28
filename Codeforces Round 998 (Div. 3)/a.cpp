#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >>t;
    while (t--) {
        int a1, a2, a4, a5; cin >> a1 >> a2 >> a4 >> a5;
        map<int, int> cnt;
        vector<int> nums;
        cnt[a1 + a2]++;
        nums.push_back(a1 + a2);
            cnt[a4 - a2]++;
            nums.push_back(a4 - a2);
        

            cnt[a5 - a4]++;
            nums.push_back(a5 - a4);
        
        int val = 0;
        for (int i : nums) {
            val= max(val, cnt[i]);
        }
        cout << val << endl;
    }
}