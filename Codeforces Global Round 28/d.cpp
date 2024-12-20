#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, m;
        cin >> n >> m;
        vector<int> contestants, problems(m);
        int kevin;
        cin >> kevin;
        for (int i = 1; i < n; i++) {
            int offer;
            cin >> offer;
            if (offer > kevin) {
                contestants.push_back(offer);
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> problems[i];
        }
        
        sort(contestants.begin(), contestants.end());
        sort(problems.begin(), problems.end());
        int curC = 0, curP = 0;
        while (curP < m && problems[curP] <= kevin) {
            problems[curP] = 1;
            curP++;
        }

        while (curC < contestants.size() && curP < m) {
            if (contestants[curC] >= problems[curP]) {
                problems[curP] = 1 + (contestants.size() - curC);
                curP++;
            }
            else {
                curC++;
            }
        }

        while (curP < m) {
            problems[curP] = 1;
            curP++;
        }

        sort(problems.begin(), problems.end());

        
        for (int k = 1; k <= m; k++) {
            // using int results in WA
            unsigned long long sum = 0;
            for (int i = k - 1; i < m; i += k) {
                sum += problems[i];
            }
            cout << sum << " ";
        }
        cout << endl;
    
    }

}