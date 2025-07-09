#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n + 1), prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        prefix[i] = prefix[i - 1] + x[i];
    }

    multiset<long long> window;
    long long result = LLONG_MIN;

    for (int i = a; i <= n; i++) {
        window.insert(prefix[i - a]);
        if (i - b - 1 >= 0) {
            window.erase(window.find(prefix[i - b - 1]));
        }
        result = max(result, prefix[i] - *window.begin());
    }

    cout << result << "\n";
    return 0;
}
