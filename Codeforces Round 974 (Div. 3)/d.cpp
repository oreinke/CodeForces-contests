#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, d, k;
        cin >> n >> d >> k;
        priority_queue<int, vector<int>, greater<int>> start;
        priority_queue<int, vector<int>, greater<int>> end;
        for (int i = 0; i < k; i++) {
            int s, e;
            cin >> s >> e;
            start.push(s);
            end.push(e + 1);
        }

        int count = 0;
        int endStay = 1;
        int startStay = 1;
        while (startStay <= d) {
            while (!start.empty() && start.top() == startStay) {
                count++;
                start.pop();
            }
            startStay++;
        }

        int min = count;
        int max = count;
        int minDay = 1;
        int maxDay = 1;
        while (startStay <= n) {
            endStay++;
            while (!end.empty() && end.top() == endStay) {
                count--;
                end.pop();
            }

            while (!start.empty() && start.top() == startStay) {
                count++;
                start.pop();
            }

            if (count > max) {
                max = count;
                maxDay = endStay;
            }
            if (count < min) {
                min = count;
                minDay = endStay;
            }

            startStay++;
        }
        cout << maxDay << " " << minDay << "\n";
    }
}