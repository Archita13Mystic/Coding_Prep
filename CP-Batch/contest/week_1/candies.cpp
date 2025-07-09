#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<long long> pref(n);
        pref[0] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + a[i];
        }

        for (int i = 0; i < q; i++) {
            long long x;
            cin >> x;
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (pref[m] >= x) {
                    ans = m + 1;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
