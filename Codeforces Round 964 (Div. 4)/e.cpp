#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> powo3;
    powo3.push_back(3);
    while (powo3[powo3.size() - 1] < 1000000) {
        powo3.push_back(powo3[powo3.size() - 1] * 3);
    }
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int l, r;
        cin >> l >> r;
        int curPow = 0;
        long long ops = 0;
        while (powo3[curPow] <= l) {
            curPow++;
        }
        // reduce smallest val to 0
        ops += (curPow + 1) * 2;
        l++;
        if (l == powo3[curPow]) {
            curPow++;
        }
        while (l < 1000000)
            if (r < powo3[curPow]) {
                ops += (r - l + 1) * (curPow + 1);
                l = 1000000000;
            }
            else {
                ops += (powo3[curPow] - l) * (curPow + 1);
                l = powo3[curPow];
                curPow++;
        }
        cout << ops << "\n";

    }
}