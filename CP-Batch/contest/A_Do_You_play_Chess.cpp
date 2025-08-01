#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        char l = s[0];
        char d = s[1];

        for (char c = 'a'; c <= 'h'; ++c) {
            if (c != l) {
                cout << c << d << "\n";
            }
        }

        for (char r = '1'; r <= '8'; ++r) {
            if (r != d) {
                cout << l << r << "\n";
            }
        }
    }
    return 0;
}
