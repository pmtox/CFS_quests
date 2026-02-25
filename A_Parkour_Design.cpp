#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        long long x, y;
        cin >> x >> y;

        if (x - 2*y >= 0 && (x - 2*y) % 3 == 0 && x + 4*y >= 0) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
};

int main() {
k
    int t;
    cin >> t;

    Solution obj;
    while (t--) {
        obj.solve();
    }

    return 0;
}