#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a(2e5 + 1);
  vector<int> f(2e5 + 1);
    
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
      f[j] = INT_MAX; 
    }
    f[0] = 0;
    f[n] = INT_MAX;
    for (int j = 0; j < n; ++j) {
      f[j + 1] = min(f[j + 1], f[j] + 1);
      if (j + a[j] + 1 <= n) {
        f[j + a[j] + 1] = min(f[j + a[j] + 1], f[j]);
      }
    }
    cout << f[n] << endl;
  }
  
  return 0;
}