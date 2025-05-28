#include <bits/stdc++.h>

using namespace std;

vector<int> spf(1000002, 1);

void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= 1000001; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= 1000001; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}

map<int, int> getFactorization(int x)
{
    map<int, int> ret;
    while (x != 1) {
        ret[spf[x]]++;
        x = x / spf[x];
    }
    return ret;
}


int main() {
    sieve();
    int t; cin >> t;
    while (t--) {
        int x, y, k; cin >> x >> y >> k;
        if (k == 1 && y != x) {
            cout << "-1\n";
        }
        else {
            map<int,int> primeX = getFactorization(x),
                        primeY = getFactorization(y);
            
            // printf("Prime factorization of X:\n");
            // for (auto [p, cnt] : primeX) {
            //     printf("%d : %d\n", p, cnt);
            // }

            // printf("\nPrime factorization of Y:\n");
            // for (auto [p, cnt] : primeY) {
            //     printf("%d : %d\n", p, cnt);
            // }
            map<int, int, greater<int>> mult, div;
            set<int, greater<int>> m, d;
            int largestP = 1;
            for (auto[p, xcnt] : primeX) {
                int ycnt = primeY[p];

                if (xcnt != ycnt) largestP = max(largestP, p);

                if (ycnt < xcnt) {
                    div[p] += xcnt - ycnt;
                    d.insert(p);
                }
                else if (ycnt > xcnt) {
                    mult[p] += ycnt - xcnt;
                    m.insert(p);
                }
            }

            for (auto[p, ycnt] : primeY) {
                if (primeX[p] == 0) {
                    largestP = max(largestP, p);
                    mult[p] = ycnt;
                    m.insert(p);
                }
            }

            if (largestP > k) {
                cout << "-1\n";
            }
            else {
                int cnt = 0;
                long long cur = 10000001;
                for (auto [p, num] : mult) {
                    while (num > 0) {
                        if (p * cur > k) {
                            for (int option : m) {
                                while (option * cur <= k) {
                                    
                                    cur *= option;
                                    // printf("removing: %, cur: %d\n", option, cur);
                                    mult[option]--;
                                    if (mult[option] == 0) {
                                        m.erase(option);
                                        break;
                                    }
                                }
                            }
                            // printf("new op\n");
                            cnt++;
                            cur = p;
                            // printf("removing: %d, cur: %d\n",p, cur);
                        }
                        else {
                            // printf("removing: %d, cur: %d\n",p, cur);
                            cur *= p;
                            //printf("removing: %d, cur: %d\n",p, cur);
                        }
                        num--;
                    }
                    m.erase(p);
                }

                cur = 10000001;
                for (auto [p, num] : div) {
                    while (num > 0) {
                        if (p * cur > k) {
                            for (int option : d) {
                                while (option * cur <= k) {
                                    cur *= option;
                                    div[option]--;
                                    // printf("removing: %d, cur: %d\n", option, cur);
                                    if (div[option] == 0) {
                                        d.erase(option);
                                        break;
                                    }
                                }
                            }
                            // printf("new op\n");
                            

                            cnt++;
                            cur = p;
                            //printf("removing: %d, cur: %d\n",p, cur);
                        }
                        else {
                            
                            cur *= p;
                            //printf("removing: %d, cur: %d\n",p, cur);
                        }
                        num--;
                    }
                    d.erase(p);
                }

                cout << cnt << endl;
            }
        }
    }
}