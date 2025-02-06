#include <bits/stdc++.h>

using namespace std;

string toBinary (int n) {
    string res = "";
    while (n > 0) {
        if (n % 2 == 1) {
            res.push_back('1');
        }
        else {
            res.push_back('0');
        }
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string prev = "";
        int zeroes = 0;
        unsigned long long ops = 0;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            string cur = toBinary(num);
            if (cur.size() > (prev.size() + zeroes)) {
                prev = cur;
                zeroes = 0;
            }
            else {
                int numOps = 0;
                if (cur.size() < (prev.size() + zeroes)) {
                    numOps += (prev.size() + zeroes) - cur.size();
                }
                bool done = false;
                for (int j = 0; j < min(cur.size(), prev.size()) && !done; ++j) {
                    if (cur[j] != prev[j]) {
                        if (cur[j] == '1') {
                            done = true;
                        }
                        else {
                            done = true;
                            numOps++;
                        }
                    }
                }
                if (!done) {
                    if (cur.size() < prev.size()) {
                        for (int j = cur.size(); j < prev.size() && !done; ++j) {
                            if (prev[j] == '1') {
                                done = true;
                                numOps++;
                            }
                        }
                    }
                }

                // printf("i: %d, numOps: %d, prev %s, cur: %s\n", i + 1, numOps, prev, cur);
                prev = cur;
                zeroes = numOps;
                ops += numOps;
            }
        }
        cout << ops << endl;
    }
}