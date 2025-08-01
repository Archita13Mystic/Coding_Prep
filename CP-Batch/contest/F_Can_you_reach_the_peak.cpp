#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (((n - 1) & i) == i) {
            res ^= a[i];
        }
    }

    cout << res << "\n";
    return 0;
}
