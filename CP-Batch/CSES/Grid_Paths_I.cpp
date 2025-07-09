#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;
int n;
vector<string> grid;
vector<vector<long long>> dp;

long long countPaths(int i, int j) {
    if (i < 0 || j < 0 || grid[i][j] == '*') return 0;
    if (i == 0 && j == 0) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    long long fromTop = countPaths(i - 1, j);
    long long fromLeft = countPaths(i, j - 1);

    return dp[i][j] = (fromTop + fromLeft) % MOD;
}

int main() {
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    dp.assign(n, vector<long long>(n, -1));
    cout << countPaths(n - 1, n - 1) << endl;
    return 0;
}
