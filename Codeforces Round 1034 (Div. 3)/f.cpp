#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001
vector<int> spf(MAXN + 1, 1);

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    // stores smallest prime factor for every number

    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { // if the number is prime ,mark
                           // all its multiples who havent
                           // gotten their spf yet
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) // if its smallest prime factor is
                          // 1 means its spf hasnt been
                          // found yet so change it to i
                    spf[j] = i;
            }
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1 && ret.size() < 2) {
        if (ret.size() == 0 || ret[0] != spf[x]) ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


int main() {
    sieve();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> perm (n + 1, 0);
        perm[1] = 1;
        map<int, vector<int>> p;
        set<int> primeSet;
        for (int i = 2; i <= n; ++i) {
            vector<int> primeFac = getFactorization(i);
            primeSet.insert(primeFac[0]);
            if (i == primeFac[0] && i * 2 > n) {
                perm[i] = i;
                // printf("Sticking point, i: %d\n", i);
            }
            else {
                p[primeFac[0]].push_back(i);
                if (primeFac[0] == 2 && primeFac.size() > 1) {
                    p[primeFac[1]].push_back(i);
                    primeSet.insert(primeFac[1]);

                }
            }
        }

        for (int num : primeSet) {
            if (num == 2) continue;
            // printf("prime: %d\n", num);
            int size =  p[num].size();
            vector<int> arr = p[num];
            for (int i = 0; i < size; ++i) {
                // printf("num: %d\n", arr[i]);
                perm[arr[i]] = arr[(i + 1) % size];
            }
        }

        if (perm[2] == 0) {
            int ind = 0, next = 1;
            vector<int> arr = p[2];
            while (next < arr.size()) {
                if (perm[arr[next]] == 0) {
                    perm[arr[ind]] = arr[next];
                    // printf("ind: %d, next: %d, perm[arr[ind]]: %d\n", ind, next, perm[arr[ind]]);
                    ind = next;
                }
                next++;
            }
            perm[arr[ind]] = 2;
        }

        for (int i = 1; i <= n; ++i) {
            cout << perm[i] << " ";
        }
        cout << endl;
    }
}