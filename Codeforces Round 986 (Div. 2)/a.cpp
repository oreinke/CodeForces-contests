#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;

    cin >> t;
    for (int tc = 0; tc < t; t++) {
        string seq;
        int rX, rY;
        cin >> seq >> rX >> rY;

        int s = 0, w = 0, n = 0, e = 0;
        for (int i = 0; i < seq.length(); i++) {
            if (seq[i] == 'S') {
                s++;
            }
            else if (seq[i] == 'W'){ 
                w++;
            }
            else if (seq[i] == 'N'){
                n++;
            }
            else {
                e++;
            }
        }

        int x = 0, y = 0;
        bool flag = false;
        for (int j = 0; j < 25; j++) {
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i] == 'S') {
                    y--;
                }
                else if (seq[i] == 'W'){ 
                    x--;
                }
                else if(seq[i] == 'N') {
                    y++;
                }
                else if (seq[i] == 'E') {
                    x++;
                }
                if (x == rX && y == rY) {
                    flag == true;
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}