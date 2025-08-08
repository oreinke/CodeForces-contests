#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int recDiffOne (string lStr, string rStr) {
    // printf("l: %d, r: %d\n", l, r);
    int l = stoi(lStr), r = stoi(rStr);
    int fl = lStr[0] - '0', fr = rStr[0] - '0';
    if (rStr.length() == 1) {
        if (fl == 9 &&  fr == 0) return 1;
        return 0;
    }

    if (fl == 9 && fr == 0) return 1 + recDiffOne(lStr.substr(1), rStr.substr(1));
    return 0;
}

int recDiffZero (string lStr, string rStr) {
    // cout << "l: " << lStr << " r: " << rStr << endl;
    int l = stoi(lStr), r = stoi(rStr);
    int fl = lStr[0] - '0', fr = rStr[0] - '0';
    // cout << "!l: " << l << " r: " << r << endl;
    // cout << "!fl: " << fl << " fr: " << fr << endl;
    fflush(stdout);
    if (rStr.length() == 1) {
        if (fl == fr) return 2;
        if (fl + 1 == fr) return 1;
        return 0;
    }

    if (fl == fr) return 2 + recDiffZero(lStr.substr(1), rStr.substr(1));
    if (fr == fl + 1) return 1 + recDiffOne(lStr.substr(1), rStr.substr(1));
    return 0;
}

int main() {
    int t; cin >> t;
    while (t--) {
        string l, r; cin >> l >> r;
        cout << recDiffZero(l, r) << endl;
        //cout << "----------------------------------\n";
    }
}