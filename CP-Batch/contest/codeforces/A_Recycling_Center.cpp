#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        vector<long long> a(n,0);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        sort(a.begin(), a.end()); 
        int d = 0;

        for (int i = 0; i < n; ++i) {
            long long weight = a[i] << i; 
            if (weight > c)
                d++;
        }

        cout << d << '\n';
    }
    return 0;
}
