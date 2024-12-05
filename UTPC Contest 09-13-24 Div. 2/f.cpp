#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, s, k, g;
    
    cin >> n >> m >> s >> k >> g;

    vector<vector<int>> adjMatrix(n + 1);
    for (int i = 0; i < m; i++) {
        int src, d;
        cin >> src >> d;
        // cout << "Adding edge from " << src << " to " << d << "\n";
        adjMatrix[src].push_back(d);
        adjMatrix[d].push_back(src);
    }

    vector<int> exits;
    for (int i = 0; i < k; i++) {
        int e;
        cin >> e;
        exits.push_back(e);
    }

    vector<int> ghosts;
    for (int i = 0; i < g; i++){
        int ghost;
        cin >> ghost;
        ghosts.push_back(ghost);
    }

    vector<int> harryVisited(n + 1, -1);
    queue<int> q;
    q.push(s);
    int step = 0;
    while(!q.empty()) {
        int size = q.size();
        while (size > 0) {
            int node = q.front();
            q.pop();
            if (harryVisited[node] == -1){
                harryVisited[node] = step;
                for (int adj : adjMatrix[node]) {
                    q.push(adj);
                }
            }
            size--;
        }
        step++;
    }

    vector<int> ghostVisited(n + 1, -1);
    for (int ghost : ghosts) {
        q.push(ghost);
    }
    step = 0;
    while(!q.empty()) {
        int size = q.size();
        while (size > 0) {
            int node = q.front();
            q.pop();
            if (ghostVisited[node] == -1){
                ghostVisited[node] = step;
                for (int adj : adjMatrix[node]) {
                    q.push(adj);
                }
            }
            size--;
        }
        step++;
    }

    int count = 0;
    for (int exit : exits) { 
        // cout << exit << ": " << harryVisited[exit] << " " << ghostVisited[exit] << endl;
        if ((harryVisited[exit] != -1) && (ghostVisited[exit] == -1 || harryVisited[exit] < ghostVisited[exit])) {
            count++;
        }
    }

    cout << count << "\n";
}