#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        // L is neg, R is pos
        vector<int> orig, rec;
        char prev = 'p';
        string str; cin >> str;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == 'L') {
                if (prev == 'L') orig[orig.size() - 1]--;
                else orig.push_back(-1);
                prev = 'L';
            }
            else {
                if (prev == 'R') orig[orig.size() - 1]++;
                else orig.push_back(1);   
                prev = 'R';

            }
        }
        prev = 'p';
        str; cin >> str;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == 'L') {
                if (prev == 'L') rec[rec.size() - 1]--;
                else rec.push_back(-1);
                prev = 'L';
            }
            else {
                if (prev == 'R') rec[rec.size() - 1]++;
                else rec.push_back(1);   
                prev = 'R';

            }
        }
        // printf("orig:\n");
        // for (int num : orig) printf(" %d", num);
        // printf ("\nrec:\n");
        // for (int num : rec) printf(" %d", num);
        // printf("\n");
        if (rec.size() != orig.size()) {
            cout << "NO\n";
        }
        else {
            bool good = true;
            for (int i = 0; i < orig.size() && good; ++i) {
                // printf("orig[%d]: %d, rec[%d]: %d\n",i, orig[i], i, rec[i]);
                if ((orig[i] > 0 && rec[i] < 0) || (orig[i] < 0 && rec[i] > 0) || (abs(rec[i]) < abs(orig[i])) || (abs(rec[i]) > (2 * abs(orig[i])))) good = false;
            }

            if (good) cout << "YES\n";
            else cout << "NO\n";
        }

    }
}