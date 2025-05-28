#include <bits/stdc++.h>

using namespace std;

void dfs (int u, int step,  vector<long long> &threat, vector<long long> &mThreat, vector<long long> &parent, vector<vector<int>> &adjL) {
    //printf("u: %d, step: %d\n", u, step); fflush(stdout);
    if (step > 1) {
        mThreat[u] = max(threat[u], mThreat[parent[parent[u]]] - threat[parent[u]] + threat[u]);
    }

    for (int v : adjL[u]) {
        if (v != parent[u]) {
            parent[v] = u;
            dfs(v, step + 1, threat, mThreat, parent, adjL);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adjL (n);
        vector<long long> threat(n), mThreat(n), parent(n);
        for (int i = 0; i < n; ++i) {
            cin >> threat[i];
            mThreat[i] = threat[i];
        }

        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            u--; v--;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        parent[0] = 0;
        dfs(0, 0, threat, mThreat, parent, adjL);
        
        for (int i = 0; i < n; ++i) {
            // check time save if we switch to printf later
            cout << mThreat[i] << " ";
        }
        cout << endl;
    }
}