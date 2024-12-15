#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        string num;
        cin >> num;

        int count2 = 0;
        int count3 = 0;
        long long sum = 0;
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '2') {
                count2++;
            }
            else if (num[i] == '3') {
                count3++;
            }
            sum += num[i] - '0';
        }
        // cout << "Num = " << num << ", n2 = " << count2 << ", n3 = " << n3 << endl;
        
        sum %= 9;
        bool valid = false;    
        for (int i = 0; i <= min(count2, 10); i++) {
            if (i != 0) {
                sum += 2;
                sum %= 9;
            }

            if (sum == 0) {
                valid = true;
            }
            int sumCur = sum;
            for (int j = 0; j < min(count3, 10); j++) {
                sumCur += 6;
                sumCur %= 9;
                if (sumCur == 0) {
                    valid = true;
                }
            }
        }

        if (valid) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }



}