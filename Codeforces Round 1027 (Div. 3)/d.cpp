#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll recA (ll n, vector<pair<ll, ll>> points, pair<ll, ll> ignore) {
    vector<ll> max1 (4, -1); 
        for (auto [x, y] : points) {
            if (x == ignore.first && y == ignore.second) continue;
            // big x
            if (x > max1[0] || max1[0] == -1) {
                max1[0] = x;
            }

            // lil x
            if (x < max1[1] || max1[1] == -1) {
                max1[1] = x;
            }

            // big y
            if (y > max1[2] || max1[2] == -1) {
                max1[2] = y;
            }

            // lil y
            if (y < max1[3] || max1[3] == -1) {
                max1[3] = y;
            }
        }

    ll area = (max1[0] - max1[1] + 1) * (max1[2] - max1[3] + 1);

    if (area < n) area += min((max1[0] - max1[1] + 1), (max1[2] - max1[3] + 1));
    return area;
}


int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> max1 (4, -1);
        vector<pair<ll,ll>> points1 (4, {-1, -1}); 
        vector<pair<ll, ll>> points(n);

        for (int i = 0; i < n; ++i) {
            ll x, y; cin >> x >> y;
            points[i] = {x, y}; 
            // big x
            if (x > max1[0] || max1[0] == -1) {
                max1[0] = x;
                points1[0] = {x, y};
            }

            // lil x
            if (x < max1[1] || max1[1] == -1) {
                max1[1] = x;
                points1[1] = {x, y};
            }

            // big y
            if (y > max1[2] || max1[2] == -1) {
                max1[2] = y;
                points1[2] = {x, y};
            }

            // lil y
            if (y < max1[3] || max1[3] == -1) {
                max1[3] = y;
                points1[3] = {x, y};
            }

        }

        if (n == 1) {
            cout << "1\n";
        }
        else {
            ll area = LLONG_MAX;
            for (int i = 0; i < 4; ++i) {
                area = min(area, recA(n, points, points1[i]));
            }
            cout << area << endl;
        }
        
    }
}