#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> dpStart, dpEnd;

int increasingEndingAt(int i) {
    if (i == 0) return 1;
    if (dpEnd[i] != -1) return dpEnd[i];
    if (a[i] > a[i - 1])
        return dpEnd[i] = 1 + increasingEndingAt(i - 1);
    return dpEnd[i] = 1;
}

int increasingStartingAt(int i) {
    if (i == n - 1) return 1;
    if (dpStart[i] != -1) return dpStart[i];
    if (a[i] < a[i + 1])
        return dpStart[i] = 1 + increasingStartingAt(i + 1);
    return dpStart[i] = 1;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int &x : a) cin >> x;

    dpStart.assign(n, -1);
    dpEnd.assign(n, -1);

    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, increasingEndingAt(i)); 
    }

    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i + 1]) {
            int left = increasingEndingAt(i - 1);
            int right = increasingStartingAt(i + 1);
            maxLen = max(maxLen, left + right);
        }
    }

    cout << maxLen << '\n';
    return 0;
}
