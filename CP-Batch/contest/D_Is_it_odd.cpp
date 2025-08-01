#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> arr(n);
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            prefix[i + 1] = prefix[i] + arr[i];
        }

        long long total = prefix[n];

        while (q--) {
            int l, r;
            long long k;
            cin >> l >> r >> k;

            long long rsum = (r - l + 1) * k;
            long long orig_sum = prefix[r] - prefix[l - 1];
            long long new_total = total - orig_sum + rsum;

            if (new_total % 2 == 1)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }

    return 0;
}
