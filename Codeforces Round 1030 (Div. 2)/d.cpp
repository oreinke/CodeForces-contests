#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int rec(ull time, int direction, int n, int k, int ind, vector<ull> &position, vector<ull> &delay, vector<map<ull,int>> &reachedR, vector<map<ull,int>> &reachedL) {
    if (direction == 1) {
        if (reachedR[ind][time] == 0) {
            if (time < delay[ind] || time - delay[ind] > 0) {
                if (ind + 1 == n) {
                    return 1;
                }
                reachedR[ind][time] = 3;
                reachedR[ind][time] = rec((time + position[ind + 1] - position[ind]) % k, 1, n, k, ind + 1, position, delay, reachedR, reachedL);  
            }
            else {
                if (ind == 0) return 1;
                reachedR[ind][time] = 3;
                reachedR[ind][time] = rec((time + position[ind] - position[ind - 1]) % k, 0, n, k, ind - 1, position, delay, reachedR, reachedL);
            }
        }
        else if (reachedR[ind][time] == 3) {
            reachedR[ind][time] = 2;
        }
        return reachedR[ind][time];
    }
    else {
        if (reachedL[ind][time] == 0) {
            if (time < delay[ind] || time - delay[ind] > 0) {
                if (ind == 0) {
                    return 1;
                }
                reachedL[ind][time] = 3;
                reachedL[ind][time] = rec((time + position[ind] - position[ind - 1]) % k, 0, n, k, ind - 1, position, delay, reachedR, reachedL);  
            }
            else {
                if (ind + 1 == n) return 1;
                reachedL[ind][time] = 3;
                reachedL[ind][time] = rec((time + position[ind + 1] - position[ind]) % k, 1, n, k, ind + 1, position, delay, reachedR, reachedL);
            }
        }
        else if (reachedL[ind][time] == 3) {
            reachedL[ind][time] = 2;
        }
        return reachedL[ind][time];
    }
}

int main () {
    int t; cin >> t;
    while (t--) {
        ull n, k; cin >> n >> k;
        vector<ull> position (n), delay (n);
        for (auto &x : position) cin >> x;
        for (auto &x : delay) cin >> x;
        set<ull> hasLight;
        map<ull, int> lightInd;
        for (int i = 0; i <n ; ++i) {
            hasLight.insert(position[i]);
            lightInd[position[i]] = i;
        }


        // 0 = unexplored, 1 = success from here, 2 = failure, 3 = exploring
        vector<map<ull, int>> reachedR (n);
        vector<map<ull, int>> reachedL (n);
        int queries; cin >> queries;
        for (int i = 0; i < queries; ++i) {
            ull q; cin >> q;
            auto closestIt = hasLight.lower_bound(q);
            if (closestIt == hasLight.end()) {
                cout << "YES\n";
            }
            else {
                ull closest = *closestIt;
                ull time = closest - q;
                int start = lightInd[closest];
                int res = rec(time % k, 1, n, k, start, position, delay, reachedR, reachedL);
                if (res == 1) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";

                }
            }
        }
    }

    
}