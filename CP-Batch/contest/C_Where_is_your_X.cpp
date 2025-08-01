#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    unordered_map<long long, int> pcount;
    pcount[0] = 1;

    long long count = 0, psum = 0;

    for (int i = 0; i < n; ++i) {
        psum += a[i];
        if (pcount.count(psum - x))
            count += pcount[psum - x];
        pcount[psum]++;
    }

    cout << count << "\n";
    return 0;
}
