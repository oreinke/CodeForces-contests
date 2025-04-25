#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, f; cin >> n >> f;
        vector<int> flowers (n), pick (f);
        for (auto &x : flowers) cin >> x;
        for (auto &x : pick) cin >> x;
        vector<int> pickF (f, -1), pickB (f, -1);
        
        int curF = 0;
        for (int i = 0; i < n && curF < f; ++i) {
        if (flowers[i] >= pick[curF]) {
                pickF[curF] = i;
                curF++;
            }
        }

        curF = f - 1;
        for (int i = n - 1; i >= 0 && curF >= 0; --i) {
        if (flowers[i] >= pick[curF]) {
            pickB[curF] = i;
                curF--;
            }
            
        }

        int res = -1;

        if (pickF[f - 1] != -1) {
            res = 0;
            //cout << "hit\n";
        }
        else if (f == 1) {
            res = pick[0];
        }
        else {
            for (int i = 0; i < f; ++i) {
                if (res == -1 || pick[i] < res) {
                    if (i == 0 && pickB[1] != -1) {
                        res = pick[i];
                    } 
                    else if (i == f - 1 && pickF[f - 2] != -1) {
                        res = pick[i];
                    }
                    else if (pickF[i - 1] != -1 && pickB[i + 1] != -1 && pickF[i - 1] < pickB[i + 1]) {
                        res = pick[i];
                    }
                }
            }
        }
        cout << res << endl;
    }
}