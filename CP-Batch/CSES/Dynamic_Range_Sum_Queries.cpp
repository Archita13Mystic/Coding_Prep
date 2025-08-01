#include <bits/stdc++.h>
using namespace std;
 
vector<long long> fenwick;
 
void update(int i, long long delta, int n) {
    while (i <= n) {
        fenwick[i] += delta;
        i += i & -i;
    }
}
 
long long query(int i) {
    long long sum = 0;
    while (i > 0) {
        sum += fenwick[i];
        i -= i & -i;
    }
    return sum;
}
 
int main() { 
    int n, q;
    cin >> n >> q;
 
    vector<long long> arr(n + 1);
    fenwick.assign(n + 1, 0);
 
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i], n);
    }
 
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            update(k, u - arr[k], n);
            arr[k] = u;
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(b) - query(a - 1) << '\n';
        }
    }
 
    return 0;
}