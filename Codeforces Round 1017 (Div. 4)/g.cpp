#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int q; cin >> q;
        int direction = 0, n = 0;

        unsigned long long fVal = 0, bVal = 0, elementSum = 0;

        deque<unsigned long long> f, b;
        while (q--) {
            int cmd; cin >> cmd;
            if (cmd == 1) {
                //shift
                if (direction == 0) {
                    fVal -= f.back() * n;
                    fVal += elementSum;
                    f.push_front(f.back());
                    f.pop_back();

                    bVal -= elementSum;
                    bVal += b.front() * n;
                    b.push_back(b.front());
                    b.pop_front();
                }
                else {
                    bVal -= b.back() * n;
                    bVal += elementSum;
                    b.push_front(b.back());
                    b.pop_back();

                    fVal -= elementSum;
                    fVal += f.front() * n;
                    f.push_back(f.front());
                    f.pop_front(); 
                }
            }
            else if (cmd == 2) {
                direction = (direction + 1) % 2;
            }
            else {
                //append
                unsigned long long k; cin >> k;
                n++;
                elementSum += k;
                if (direction == 0) {
                    f.push_back(k);
                    fVal += k * n;

                    bVal += elementSum;
                    b.push_front(k);
                }
                else {
                    b.push_back(k);
                    bVal += k * n;

                    fVal += elementSum;
                    f.push_front(k);
                }
            }
            if (direction == 0) {
                printf("%llu\n", fVal);
            }
            else {
                printf("%llu\n", bVal);
            }
        }

    }
}