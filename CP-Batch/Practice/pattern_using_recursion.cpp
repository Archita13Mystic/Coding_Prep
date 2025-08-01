#include <bits/stdc++.h>
using namespace std;

int n;

void pattern(int i, int j) {
    if (i == n) return;

    if (j > i) {
        cout << "\n";
        pattern(i + 1, 0);
        return;
    }

    cout << "* ";
    pattern(i, j + 1);
}

int main() {
    cin >> n;
    pattern(0, 0);
    return 0;
}
