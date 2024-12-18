#include <bits/stdc++.h>

using namespace std;

// failed due to not further reducing the math required for this problem.
// we can further reduce the sum calculation from n2 to 2n.
// B = (b1a1 + b1a2) + (b2a1 + b2a2)
// B = b1(a1 + a2) + b2(a1 + a2)
// B = (a1 + a2) * (b1 + b2)
// B = SumA * SumB

// We also can apply this same approach to the updates.

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> arrA(n);
    vector<int> arrB(m);
    long long sumA = 0;
    long long sumB = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arrA[i] = num;
        sumA += num;
    }

    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        arrB[i] = num;
        sumB += num;
    }

    long long sum = sumA * sumB;
    
    
    unordered_set<long long> possA;
    unordered_set<long long> possB;
    for (int i = 0; i < n; i++) {
        possA.insert(sumA - arrA[i]);
    }
    
    for (int i = 0; i < m; i++) {
        possB.insert(sumB - arrB[i]);
    }


    for (int curQ = 0; curQ < q; curQ++) {
        int query;
        scanf("%d", &query);
        query = sum - query;
        bool found = false;
        if (query == 0) {
            if (possA.find(0) != possA.end() && possB.find(0) != possB.end() ) {
                found = true;
            }
        }

        int absQuery = abs(query); 
        for (int i = 1; i * i <= absQuery; i++) {
            if (absQuery % i == 0) {
                if (query > 0 && ((possA.find(absQuery / i)) && possB.find(i))) {

                }
            }
        }

        if (found) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    
    
}