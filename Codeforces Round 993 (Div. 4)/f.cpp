#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> arrA(n);
    vector<int> arrB(n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arrA[i] = num;
    }

    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        arrB[i] = num;
    }

    
    vector<long long> rowSums(n);
    vector<long long> colSums(m, 0);
    set<long long> possibleSums;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long rSum = 0;
        for (int j = 0; j < m; j++) {
            rSum += arrA[i] * arrB[j];
            sum += arrA[i] * arrB[j];
            colSums[j] += arrA[i] * arrB[j];
        }
        rowSums[i] = rSum;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            possibleSums.insert(rowSums[i] + colSums[j] - arrA[i] * arrB[j]);
        }
    }

    for (int i = 0; i < q; i++) {
        int query;
        scanf("%d", &query);
        if (possibleSums.find(sum - query) != possibleSums.end()) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }



}