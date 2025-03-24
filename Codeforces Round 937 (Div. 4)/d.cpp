#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

bool recursion (int n, vector<int> &nums, map<int,int> memo) {
    if (n == 1 || n == 0) return true;

    if (memo[n] != 0) {
        if (memo[n] == 1) {
            return true;
        }
        return false;
    }

    bool result = false;
    for (int i : nums) {
        
        if (i <= n && n % i == 0) {
            if (recursion(n / i, nums, memo)) {
                result = true;
            }
        }
    }
    memo[n] = result;
    return result;
}

int main() {
    int t; cin >> t;
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(11);
    nums.push_back(100);
    nums.push_back(101);
    nums.push_back(110);
    nums.push_back(111);
    nums.push_back(1000);
    nums.push_back(1001);
    nums.push_back(1010);
    nums.push_back(1011);
    nums.push_back(1100);
    nums.push_back(1101);
    nums.push_back(1110);
    nums.push_back(1111);
    nums.push_back(11000);
    nums.push_back(11001);
    nums.push_back(11010);
    nums.push_back(11011);
    nums.push_back(11100);
    nums.push_back(11101);
    nums.push_back(11110);
    nums.push_back(11111);
    nums.push_back(10000);
    nums.push_back(10001);
    nums.push_back(10010);
    nums.push_back(10011);
    nums.push_back(10100);
    nums.push_back(10101);
    nums.push_back(10110);
    nums.push_back(10111);
    nums.push_back(111000);
    nums.push_back(111001);
    nums.push_back(111010);
    nums.push_back(111011);
    nums.push_back(111100);
    nums.push_back(111101);
    nums.push_back(111110);
    nums.push_back(111111);
    nums.push_back(110000);
    nums.push_back(110001);
    nums.push_back(110010);
    nums.push_back(110011);
    nums.push_back(110100);
    nums.push_back(110101);
    nums.push_back(110110);
    nums.push_back(110111);
    nums.push_back(101000);
    nums.push_back(101001);
    nums.push_back(101010);
    nums.push_back(101011);
    nums.push_back(101100);
    nums.push_back(101101);
    nums.push_back(101110);
    nums.push_back(101111);
    nums.push_back(100000);
    nums.push_back(100001);
    nums.push_back(100010);
    nums.push_back(100011);
    nums.push_back(100100);
    nums.push_back(100101);
    nums.push_back(100110);
    nums.push_back(100111);
    map<int, int> memo;
    while (t--) {
        int n; cin >> n;
        if (recursion(n, nums, memo)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}