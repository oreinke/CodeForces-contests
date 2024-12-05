#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int start = 0;
        int end = arr.size() - 1;
        
        int target = n - 2;
        while (start < end) {
            if (arr[start] * arr[end] == target) {
                break;
            }
            else if (arr[start] * arr[end] < target) {
                start++;
            }
            else {
                end--;
            }
        }
        cout << arr[start] << " " << arr[end] << "\n";
    }
}