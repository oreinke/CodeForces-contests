#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    
    while(t--) {
        //cout << "----------------------------------------\n";
        int n, m; cin >> n >> m;
        vii cows(n);
        vector<pair<int,int>> order;
        int startCow = -1;
        int lowest = n * m;
        for (int i = 0; i < n; ++i) {
            for (int j =0; j < m; ++j) {
                int card; cin >> card;
                cows[i].push_back(card);
            }
            sort(cows[i].begin(), cows[i].end());
            order.emplace_back(cows[i][0], i);
        }
        sort(order.begin(), order.end());
        int lastCard = -1;
        bool playing = true;
        for (int i = 0; i < m && playing; i++) {
            for (int j = 0; j < n && playing; ++j) {
                //
                if (cows[order[j].second][i] > lastCard) {
                    //cout << "Cow " << (order[j].second + 1) << " placing " << cows[order[j].second][i] << endl;
                    lastCard = cows[order[j].second][i];
                }
                else {

                    playing = false;
                }
            }
        }

        if (playing) {
            for (int i = 0; i < n; i++) {
                cout << order[i].second + 1 << " ";
            }
        }
        else {
            cout << "-1";
        }
        cout << endl;
    }
}