#include <bits/stdc++.h>

using namespace std;

int gcd (int x, int y) {
    int a = y;
    int b = x;
    if (x > y) {
        a = x;
        b = y;
    }

    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}


int main() { 
    int n;
    cin >> n;
    vector<int> cities(n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        cities[i] = num;
    }

    vector<int> cnt(n, 0);
    cnt[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (cnt[j] != 0 && gcd (cities[i], cities[j]) != 1) {
                cnt[i] = cnt[i] + cnt[j] % 998244353;
            }
        }
    }
    cout << cnt[0] << endl;
}

