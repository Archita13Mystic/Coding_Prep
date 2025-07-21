#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> up(n + 1, vector<int>(20, -1));

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        up[i][0] = a;
    } 

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < 20; ++j) {
            if ((k >> j)&1) {
                x = up[x][j];
                if (x == -1) break;
            }
        }
        cout << x << '\n';
    }

    return 0;
}
